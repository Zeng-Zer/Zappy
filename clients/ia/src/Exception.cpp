#include "Exception.hpp"

Exception::Exception(std::string const& msg) : _msg(msg) {
}

Exception::~Exception() throw() {
}

char const *Exception::what() const throw() {
  return _msg.c_str();
}

ConnectionException::ConnectionException(std::string const& msg) : Exception(msg) {
}
