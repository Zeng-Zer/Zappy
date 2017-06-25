#include "Connection.hpp"

std::unique_ptr<Connection> Connection::_instance(nullptr);

Connection::Connection() {
  _buff[0] = '\0';
  _i = 0;
}

void Connection::initConnection(int port, std::string host) {
  _instance.reset(new Connection());
  struct protoent *pe;
  pe = getprotobyname("TCP");
  if (pe == NULL)
    throw (ConnectionException("getprotobyname() failed"));

  _instance->_sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (_instance->_sock == -1)
    throw (ConnectionException("socket() failed"));

  struct sockaddr_in s_in;
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(host.c_str());
  if (connect(_instance->_sock, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(_instance->_sock) == -1)
	throw (ConnectionException("close() failed"));
      throw (ConnectionException("connect() failed"));
    }
  _instance->_isConnected = true;
}

void Connection::destroyConnection()
{
  close(_instance->_sock);
  _instance.reset(nullptr);
}

Connection& Connection::getInstance() {
  return *_instance;
}

void Connection::sendMsg(std::string const &msg) const {
  send(_sock, std::string(msg + '\n').c_str(), msg.size() + 1, 0);
}

std::string Connection::recvMsg(int flags) {
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
	std::cout << line << std::endl;
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
