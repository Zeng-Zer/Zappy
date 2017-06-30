#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <string>
# include <exception>

class				Error : public std::exception
{
private:
  std::string			_msg;

public:
  Error(std::string const& = "zappy error") throw();
  virtual ~Error();

  virtual char const		*what() const throw();
};

class NetworkException : public Error {
public:
  NetworkException(std::string const& msg);
};

#endif /* !ERROR_HPP_ */
