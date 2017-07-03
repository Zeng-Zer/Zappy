#ifndef CONNECTION_HPP_
# define CONNECTION_HPP_

# include <memory>
# include <string>
# include <sstream>
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>
# include "Error.hpp"

# include <iostream>

class Network
{
public:
  ~Network();

  static void initNetwork(int port, std::string host);
  static Network& getInstance();

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
  Network();

  static std::unique_ptr<Network> _instance;

  int _sock;
  bool _isConnected;
  char	_buff[4097];
  int _i;
};

#endif /* !CONNECTION_HPP_ */
