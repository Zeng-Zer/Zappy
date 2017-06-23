#ifndef CONNECTION_HPP_
# define CONNECTION_HPP_

#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <Exception.hpp>

class Connection
{
public:

  static void initConnection(int port, std::string host = "localhost");
  static Connection& getInstance();
  static void destroyConnection();

private:
  Connection();
  static std::unique_ptr<Connection> _instance;

  int sock;
  bool isConnected;
};

#endif /* !CONNECTION_HPP_ */
