#include "Network.hpp"

std::unique_ptr<Network> Network::_instance(nullptr);

Network::Network() {
  _buff[0] = '\0';
  _i = 0;
}

Network::~Network()
{
  close(_instance->_sock);
}

void Network::initNetwork(int port, std::string host) {
  _instance.reset(new Network());
  struct protoent *pe;
  pe = getprotobyname("TCP");
  if (pe == NULL)
    throw (NetworkException("getprotobyname() failed"));

  _instance->_sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (_instance->_sock == -1)
    throw (NetworkException("socket() failed"));

  struct sockaddr_in s_in;
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(host.c_str());
  if (connect(_instance->_sock, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(_instance->_sock) == -1)
	throw (NetworkException("close() failed"));
      throw (NetworkException("connect() failed"));
    }
  _instance->_isConnected = true;
}

Network& Network::getInstance() {
  return *_instance;
}

void Network::sendMsg(std::string const &msg) const {
  send(_sock, std::string(msg + '\n').c_str(), msg.size() + 1, 0);
}

std::string Network::recvMsg(int flags) {
  std::string line;
  std::stringstream ss;
  int	ret = 0;

  while (ret != -1) {
    if (_buff[0] != '\0') {
      ss << &_buff[_i];
      while (_buff[_i] != '\n' && _buff[_i] != '\0')
	_i++;
      if (_buff[_i] == '\n') {
	std::getline(ss, line);
	_i++;
	return line;
      }
      else if (_buff[_i] == '\0') {
	_i = 0;
	_buff[_i] = '\0';
      }
    }
    else {
      ret = recv(_sock, _buff, 4096, flags);
      if (ret != -1)
	_buff[ret] = '\0';
      else
	_buff[0] = '\0';
    }
  }
  return line;
}

// void Network::getCmd() {
//   std::string line = recvMsg();
// }
