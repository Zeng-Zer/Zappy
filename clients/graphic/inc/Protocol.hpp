#ifndef PROTOCOL_HPP_
# define PROTOCOL_HPP_

# include <string>
# include <map>

namespace Protocol
{
  enum Cmd{
    MSZ = 0,
    BCT,
    UNKNOWN,
  };

  extern const std::map<Cmd, std::string> cmdMap;
  extern const std::map<std::string, Cmd> cmdString;
  extern const std::map<Cmd, std::function<void(std::string const&)>> cmdFun;

  Cmd stringToCmd(std::string const& str);
  std::string cmdToString(Cmd res);

  void msz(std::string const&);
  void bct(std::string const&);

};

#endif /* !PROTOCOL_HPP_ */
