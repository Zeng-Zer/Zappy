#include "Connection.hpp"

std::unique_ptr<Connection> Connection::_instance(nullptr);

Connection::Connection() {
  buff[0] = '\0';
  i = 0;
}

Connection& Connection::getInstance() {
  return *_instance;
}

void Connection::sendMsg(std::string const &msg) const {
  send(sock, std::string(msg + '\n').c_str(), msg.size() + 1, 0);
}

std::string Connection::recvMsg(int flags) {
  std::string line;
  std::stringstream ss;
  int	ret = 0;

  while (ret != -1) {
    if (buff[0] != '\0') {
      ss << &buff[i];
      while (buff[i] != '\n' && buff[i] != '\0')
	i++;
      if (buff[i] == '\n') {
	std::getline(ss, line);
	i++;
	return (line);
      }
      else if (buff[i] == '\0') {
	i = 0;
	buff[i] = '\0';
      }
    }
    else {
      ret = recv(sock, buff, 4096, flags);
      if (ret != -1)
	buff[ret] = '\0';
      else
	buff[0] = '\0';
    }
  }
  return line;
}

void Connection::initConnection(int port, std::string host) {
  _instance.reset(new Connection());
  struct protoent *pe;
  pe = getprotobyname("TCP");
  if (pe == NULL)
    throw (ConnectionException("getprotobyname() failed"));

  _instance->sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (_instance->sock == -1)
    throw (ConnectionException("socket() failed"));

  struct sockaddr_in s_in;
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(host.c_str());
  if (connect(_instance->sock, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(_instance->sock) == -1)
	throw (ConnectionException("close() failed"));
      throw (ConnectionException("connect() failed"));
    }
  _instance->isConnected = true;
}

void Connection::destroyConnection()
{
  close(_instance->sock);
  _instance.reset(nullptr);
}
