#include "Error.hpp"

Error::Error(std::string const &s) throw()
{
  _msg = "Error : " + s;
}

Error::~Error() {}

char const		*Error::what() const throw()
{
  return _msg.c_str();
}

NetworkException::NetworkException(std::string const& msg) : Error(msg) {
}
