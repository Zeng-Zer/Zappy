#include "Error.hpp"

zap::Error::Error(std::string const &s) throw()
{
  _msg = "Error : " + s;
}

zap::Error::~Error() {}

char const		*zap::Error::what() const throw()
{
  return (_msg.c_str());
}
