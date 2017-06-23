#include "Connection.hpp"

std::unique_ptr<Connection> Connection::_instance(nullptr);

Connection::Connection() {

}

Connection& Connection::getInstance() {
  return *_instance;
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
      throw (ConnectionException("connect( failed)"));
    }
  _instance->isConnected = true;
}

void Connection::destroyConnection()
{
  close(_instance->sock);
  _instance.reset(nullptr);
}
