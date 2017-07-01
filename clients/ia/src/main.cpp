/*
** main.c for main in
**
** Made by Jamy Bailly
** Login   <baillyj@epitech.net>
**
** Started on  Thu Jun 22 15:32:00 2017 Jamy Bailly
** Last update Thu Jun 22 15:32:00 2017 Jamy Bailly
*/

#include <iostream>
#include "Exception.hpp"
#include "Param.hpp"
#include "Connection.hpp"
#include "Player.hpp"

static std::pair<int, int> getStartPosition(std::string str) {
  std::stringstream ss;
  ss << str;
  int x;
  ss >> x;
  std::cout << "X = " << x << std::endl;
  int y;
  ss >> y;
  std::cout << "Y = " << y << std::endl;
  return std::make_pair(x, y);
}

int main(int argc, char **argv) {

  try {
    Param args(argc, argv);

    Connection::initConnection(args.getPort(), args.getHost());
    RequestBuffer::initRequestBuffer(10);

    if (Connection::getInstance().recvMsg() != "WELCOME") {
      throw (std::logic_error("Connection not etablished"));
    }

    Connection::getInstance().sendMsg(args.getTeamName());
    Connection::getInstance().recvMsg();
    auto startPos = getStartPosition(Connection::getInstance().recvMsg());

    Player player(startPos.first, startPos.second, args.getTeamName());

    while (player.isAlive()) {
      player.update();
    }

  } catch (Exception const& e) {
    std::cerr << e.what() << std::endl;
    return 84;
  }

  return 0;
}
