#include "Protocol.hpp"

const std::map<Protocol::Cmd, std::string> Protocol::cmdMap = {
  {Cmd::MSZ, "msz"},
  {Cmd::BCT, "bct"},
  {Cmd::SGT, "sgt"}
};

const std::map<std::string, Protocol::Cmd> Protocol::cmdString = {
  {"msz", Cmd::MSZ},
  {"bct", Cmd::BCT},
  {"sgt", Cmd::SGT}
};

const std::map<Protocol::Cmd, std::function<void(Logic&, std::string const&)>> Protocol::cmdFun = {
  {Cmd::MSZ, &msz},
  {Cmd::BCT, &bct},
  {Cmd::SGT, &sgt}
};

Protocol::Cmd Protocol::stringToCmd(std::string const& str) {
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
  std::stringstream ss(line);
  std::string cmdString;

  std::cout << "Line: " << line << std::endl;
  ss >> cmdString;
  std::cout << "Command: " << cmdString << std::endl;
  Protocol::Cmd cmd = Protocol::stringToCmd(cmdString);
  std::cout << "Enum cmd: " << cmd << std::endl;
  Protocol::cmdFun.at(cmd)(l, line);
}

void Protocol::msz(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  unsigned x;
  unsigned y;
  ss >> x;
  ss >> y;
  l.setMapSize(sf::Vector2i(x, y));
}

void Protocol::bct(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  sf::Vector2i coord = {
    Tools::parseStreamInt(ss),
    Tools::parseStreamInt(ss)
  };
  resource_list	rl = {
    {
      Tools::parseStreamUnsignedInt(ss),
      Tools::parseStreamUnsignedInt(ss),
      Tools::parseStreamUnsignedInt(ss),
      Tools::parseStreamUnsignedInt(ss),
      Tools::parseStreamUnsignedInt(ss),
      Tools::parseStreamUnsignedInt(ss),
      Tools::parseStreamUnsignedInt(ss),
    }
  };
  l.setMapContent(coord, rl);
}

void Protocol::sgt(Logic& l, std::string const& str) {
  std::stringstream ss(str);
  std::string cmd;
  ss >> cmd;
  int t;
  ss >> t;
  l.setUnitTime(t);
}
