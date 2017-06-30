#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <string>
# include <exception>

namespace			zap
{
  class				Error : public std::exception
  {
  private:
    std::string			_msg;

  public:
    Error(std::string const& = "zappy error") throw();
    virtual ~Error();

    virtual char const		*what() const throw();
  };
}

#endif /* !ERROR_HPP_ */
