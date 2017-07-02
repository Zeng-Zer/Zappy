#include "Tools.hpp"

unsigned Tools::parseStreamUnsignedInt(std::stringstream& ss) {
  unsigned value;

  ss >> value;
  if (ss.fail()) {
    return 0;
  }
  return value;
}

int Tools::parseStreamInt(std::stringstream& ss) {
  int value;

  ss >> value;
  if (ss.fail()) {
    return 0;
  }
  return value;
}

std::string Tools::parseStreamString(std::stringstream& ss) {
  std::string str;

  ss >> str;
  if (ss.fail()) {
    return "";
  }
  return str;
}
