#ifndef PROTOCOL_HPP_
# define PROTOCOL_HPP_

# include <SFML/Graphics.hpp>
# include <string>
# include <sstream>
# include <map>
# include <functional>
# include "Network.hpp"
# include "Tools.hpp"

# include <iostream>

class Logic;

namespace Protocol
{
  enum Cmd{
    MSZ = 0,
    BCT,
    TNA,
    PNW,
    PPO,
    PLV,
    PFK,
    PDR,
    PGT,
    PDI,
    ENW,
    SGT,
    SEG,
    UNKNOWN,
  };

  extern const std::map<Cmd, std::string> cmdMap;
  extern const std::map<std::string, Cmd> cmdString;
  extern const std::map<Cmd, std::function<void(Logic&, std::string const&)>> cmdFun;

  Cmd stringToCmd(std::string const& str);
  std::string cmdToString(Cmd res);

  void initDataGame(Logic &);

  void msz(Logic&, std::string const&);
  void bct(Logic&, std::string const&);
  void tna(Logic&, std::string const&);
  void pnw(Logic&, std::string const&);
  void ppo(Logic&, std::string const&);
  void plv(Logic&, std::string const&);
  void pfk(Logic&, std::string const&);
  void pdr(Logic&, std::string const&);
  void pgt(Logic&, std::string const&);
  void pdi(Logic&, std::string const&);
  void enw(Logic&, std::string const&);
  void sgt(Logic&, std::string const&);
  void seg(Logic&, std::string const&);

};

#endif /* !PROTOCOL_HPP_ */
