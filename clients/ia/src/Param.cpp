#include "Param.hpp"

Param::Param(int argc, char **argv)
{
  port = 0;
  if (argc > 7)
    usage();
  if (argc >= 3 && argv[1][0] == '-')
    parse_arg(&argv[1][1], argv[2]);
  if (argc >= 5 && argv[3][0] == '-')
    parse_arg(&argv[3][1], argv[4]);
  if (argc >= 7 && argv[5][0] == '-')
    parse_arg(&argv[5][1], argv[6]);
  if (port == 0 || teamName.empty())
    usage();
}

Param::~Param() {}

int Param::getPort(void) const {
  return port;
}

std::string Param::getTeamName(void) const {
  return teamName;
}

std::string Param::getHost(void) const {
  return host;
}

void Param::parse_arg(char *type, char *arg)
{
  if (!strcmp(type, "help")) {
    usage();
  }
  else if (!strcmp(type, "p")) {
    try {
      port = std::stoi(arg);
    }
    catch (std::invalid_argument) {
      usage();
    }
  }
  else if (!strcmp(type, "n")) {
    teamName = std::string(arg);
  }
  else if (!strcmp(type, "h")) {
    host = std::string(arg);
  }
}

void Param::usage(void) const
{
  std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
  std::cout << "\tport    is the port number" << std::endl;
  std::cout << "\tname    is the name of the team" << std::endl;
  std::cout << "\tmachine is the name of the machine; localhost by default" << std::endl;
  exit(0);
}
