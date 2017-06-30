#ifndef CONNECTION_HPP_
# define CONNECTION_HPP_

# include <memory>
# include <string>
# include <sstream>
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>
# include "Exception.hpp"

class Connection
{
public:

  static void initConnection(int port, std::string host);
  static void destroyConnection();
  static Connection& getInstance();

  /**
   * send msg in socket
   */
  void sendMsg(std::string const &msg) const;
  /**
   * read sentence by socket
   * to set non-blocking mode use flag : MSG_DONTWAIT
   * return a empty string if nothing to read
   */
  std::string recvMsg(int flags = 0);

private:
  Connection();

  static std::unique_ptr<Connection> _instance;

  int _sock;
  bool _isConnected;
  char	_buff[4097];
  int _i;
};

#endif /* !CONNECTION_HPP_ */
