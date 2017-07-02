#include "Tools.hpp"

std::string Tools::parseStreamString(std::stringstream& ss) {
  std::string str;

  ss >> str;
  if (ss.fail()) {
    return "";
  }
  return str;
}
