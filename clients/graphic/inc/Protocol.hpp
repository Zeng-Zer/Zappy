#ifndef PROTOCOL_HPP_
# define PROTOCOL_HPP_

# include <SFML/Graphics.hpp>
# include <string>
# include <sstream>
# include <map>
# include "Logic.hpp"

namespace Protocol
{
  enum Cmd{
    MSZ = 0,
    BCT,
    UNKNOWN,
  };

  extern const std::map<Cmd, std::string> cmdMap;
  extern const std::map<std::string, Cmd> cmdString;
  extern const std::map<Cmd, std::function<void(Logic&, std::string const&)>> cmdFun;

  Cmd stringToCmd(std::string const& str);
  std::string cmdToString(Cmd res);

  void msz(Logic&, std::string const&);
  void bct(Logic&, std::string const&);

};

#endif /* !PROTOCOL_HPP_ */
