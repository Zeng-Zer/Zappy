#ifndef PARAM_HPP_
# define PARAM_HPP_

#include <string>
#include <iostream>
#include <cstring>

class Param
{
public:
  Param(int argc, char **argv);
  ~Param();

  int getPort(void) const;
  std::string const &getHost(void) const;

  void parse_arg(char *type, char *arg);
  void usage(void) const;

private:
  int port;
  std::string host;
};

#endif /* !PARAM_HPP_ */
