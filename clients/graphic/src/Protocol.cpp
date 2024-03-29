#include "Logic.hpp"
#include "Protocol.hpp"

const std::map<Protocol::Cmd, std::string> Protocol::cmdMap = {
  {Cmd::MSZ, "msz"},
  {Cmd::BCT, "bct"},
  {Cmd::TNA, "tna"},
  {Cmd::PNW, "pnw"},
  {Cmd::PPO, "ppo"},
  {Cmd::PLV, "plv"},
  {Cmd::PIC, "pic"},
  {Cmd::PIE, "pie"},
  {Cmd::PFK, "pfk"},
  {Cmd::PDR, "pdr"},
  {Cmd::PGT, "pgt"},
  {Cmd::PDI, "pdi"},
  {Cmd::ENW, "enw"},
  {Cmd::SGT, "sgt"},
  {Cmd::SEG, "seg"},
  {Cmd::QUIT, "quit"}
};

const std::map<std::string, Protocol::Cmd> Protocol::cmdString = {
  {"msz", Cmd::MSZ},
  {"bct", Cmd::BCT},
  {"tna", Cmd::TNA},
  {"pnw", Cmd::PNW},
  {"ppo", Cmd::PPO},
  {"plv", Cmd::PLV},
  {"pic", Cmd::PIC},
  {"pie", Cmd::PIE},
  {"pfk", Cmd::PFK},
  {"pdr", Cmd::PDR},
  {"pgt", Cmd::PGT},
  {"pdi", Cmd::PDI},
  {"enw", Cmd::ENW},
  {"sgt", Cmd::SGT},
  {"seg", Cmd::SEG},
  {"quit", Cmd::QUIT},
};

const std::map<Protocol::Cmd, std::function<void(Logic&, std::string const&)>> Protocol::cmdFun = {
  {Cmd::MSZ, &msz},
  {Cmd::BCT, &bct},
  {Cmd::TNA, &tna},
  {Cmd::PNW, &pnw},
  {Cmd::PPO, &ppo},
  {Cmd::PLV, &plv},
  {Cmd::PIC, &pic},
  {Cmd::PIE, &pie},
  {Cmd::PFK, &pfk},
  {Cmd::PDR, &pdr},
  {Cmd::PGT, &pgt},
  {Cmd::PDI, &pdi},
  {Cmd::ENW, &enw},
  {Cmd::SGT, &sgt},
  {Cmd::SEG, &seg},
  {Cmd::QUIT, &quit},
  {Cmd::UNKNOWN, &ukn}

};

Protocol::Cmd Protocol::stringToCmd(std::string const& str) {
  std::cout << "STR TO CMD: " << str << std::endl;
  if (cmdString.count(str) > 0) {
    return cmdString.at(str);
  } else {
    return Cmd::UNKNOWN;
  }
}

std::string Protocol::cmdToString(Cmd res) {
  if (cmdMap.count(res) > 0) {
    return cmdMap.at(res);
  } else {
    return "";
  }
}

void Protocol::initDataGame(Logic& l) {
  Network::getInstance().sendMsg("GRAPHIC");
  std::string line = Network::getInstance().recvMsg();

  while (!line.empty()) {
    std::cout << "Line: " << line << std::endl;
    std::stringstream ss(line);
    std::string cmdString;

    cmdString = Tools::parseStreamString(ss);
    std::cout << "Command: " << cmdString << std::endl;

    Protocol::Cmd cmd = Protocol::stringToCmd(cmdString);
    std::cout << "Enum cmd: " << cmd << std::endl;

    Protocol::cmdFun.at(cmd)(l, line);
    line = Network::getInstance().recvMsg(MSG_DONTWAIT);
  }
}

void Protocol::msz(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  sf::Vector2i coord = {
    Tools::parseStream<int>(ss),
    Tools::parseStream<int>(ss)
  };
  l.setMapSize(coord);
  l.createMap(TileMap::GRASS);
}

void Protocol::bct(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  sf::Vector2i coord = {
    Tools::parseStream<int>(ss),
    Tools::parseStream<int>(ss)
  };
  std::cout << "X: " << coord.x << "\t Y: " << coord.y<< std::endl;
  resource_list	rl = {
    {
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
      Tools::parseStream<unsigned>(ss),
    }
  };
  l.setMapContent(coord, rl);
}

void Protocol::tna(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  std::string team = Tools::parseStreamString(ss);
  l.addTeam(team);
}

void Protocol::pnw(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  unsigned id = Tools::parseStream<unsigned>(ss);
  sf::Vector2i coord = {
    Tools::parseStream<int>(ss),
    Tools::parseStream<int>(ss)
  };
  unsigned o = Tools::parseStream<unsigned>(ss);
  unsigned lvl = Tools::parseStream<unsigned>(ss);
  std::string team = Tools::parseStreamString(ss);
  l.createPlayer(id, coord, o, lvl, team);
}

void Protocol::ppo(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  unsigned id = Tools::parseStream<unsigned>(ss);
  sf::Vector2i coord = {
    Tools::parseStream<int>(ss),
    Tools::parseStream<int>(ss)
  };
  unsigned o = Tools::parseStream<unsigned>(ss);
  l.setPlayerPosition(id, coord, o);
}

void Protocol::plv(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  unsigned id = Tools::parseStream<unsigned>(ss);
  unsigned lvl = Tools::parseStream<unsigned>(ss);
  l.setPlayerLevel(id, lvl);
}

void Protocol::pic(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  sf::Vector2i coord = {
    Tools::parseStream<int>(ss),
    Tools::parseStream<int>(ss)
  };
  unsigned nextLevel = Tools::parseStream<unsigned>(ss);
  unsigned idPlayer = 1;
  while (idPlayer != 0) {
    idPlayer = Tools::parseStream<unsigned>(ss);
    if (idPlayer != 0)
      l.prepareIncantation(coord, nextLevel, idPlayer);
  }
}

void Protocol::pie(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  sf::Vector2i coord = {
    Tools::parseStream<int>(ss),
    Tools::parseStream<int>(ss)
  };
  unsigned r = Tools::parseStream<unsigned>(ss);
  l.endIncantation(coord, r);
}

void Protocol::pfk(Logic& l, std::string const& str) {
  (void) l;
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  unsigned id = Tools::parseStream<unsigned>(ss);
  (void) id;
}

void Protocol::pdr(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  unsigned idPlayer = Tools::parseStream<unsigned>(ss);
  unsigned idResource = Tools::parseStream<unsigned>(ss);
  l.playerDropResource(idPlayer, idResource);
}

void Protocol::pgt(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  unsigned idPlayer = Tools::parseStream<unsigned>(ss);
  unsigned idResource = Tools::parseStream<unsigned>(ss);
  l.playerTakeResource(idPlayer, idResource);
}

void Protocol::pdi(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  unsigned idPlayer = Tools::parseStream<unsigned>(ss);
  l.playerDead(idPlayer);
}

void Protocol::enw(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  unsigned idEgg = Tools::parseStream<unsigned>(ss);
  unsigned idPlayer = Tools::parseStream<unsigned>(ss);
  sf::Vector2i coord = {
    Tools::parseStream<int>(ss),
    Tools::parseStream<int>(ss)
  };
  l.createEgg(idEgg, idPlayer, coord);
}

void Protocol::sgt(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  int t = Tools::parseStream<int>(ss);
  l.setUnitTime(t);
}

void Protocol::seg(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  std::string team = Tools::parseStreamString(ss);
  l.endGame(team);
  std::cout << "ENDGAME LOL" << std::endl;
}

void Protocol::quit(Logic& l, std::string const& str) {
  (void) str;
  l.quit();
}

void Protocol::ukn(Logic& l, std::string const& str) {
  (void) l;
  (void) str;
}
