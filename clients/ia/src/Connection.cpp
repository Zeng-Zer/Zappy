#include "Connection.hpp"

std::unique_ptr<Connection> Connection::_instance(nullptr);

Connection::Connection(std::string port_str, std::string addr)
{
  struct protoent *pe;
  pe = getprotobyname("TCP");
  if (pe == NULL)
    throw (ConnectionException("getprotobyname() failed"));

  sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (sock == -1)
    throw (ConnectionException("socket() failed"));

  struct sockaddr_in s_in;
  int port = std::stoi(port_str);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(addr.c_str());
  if (connect(sock, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(sock) == -1)
	throw (ConnectionException("close() failed"));
      throw (ConnectionException("connect( failed)"));
    }
  isConnected = true;
}

Connection& Connection::getInstance()
{
  return *_instance;
}

void Connection::destroyInstance()
{
  _instance.reset(nullptr);
}
