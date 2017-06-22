#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <exception>
# include <string>

class Exception : public std::exception {
public:
  Exception(std::string const& msg);
  virtual ~Exception() throw();

  char const *what() const throw();

private:
  std::string _msg;
};

class ConnectionException : public Exception {
public:
  ConnectionException(std::string const& msg);
};
#endif /* !EXCEPTION_HPP_ */
