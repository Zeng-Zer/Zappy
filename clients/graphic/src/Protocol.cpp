#include "Protocol.hpp"

const std::map<Protocol::Cmd, std::string> Protocol::cmdMap = {
  {Cmd::MSZ, "msz"},
  {Cmd::BCT, "bct"}
};

const std::map<std::string, Protocol::Cmd> Protocol::cmdString = {
  {"msz", Cmd::MSZ},
  {"bct", Cmd::BCT}
};

const std::map<Protocol::Cmd, std::function<void(std::string const&)>> Protocol::cmdFun = {
  {Cmd::MSZ, &msz},
  {Cmd::BCT, &bct}
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

void Protocol::msz(std::string const& str) {
  (void) str;
}

void Protocol::bct(std::string const& str) {
  (void) str;
}
