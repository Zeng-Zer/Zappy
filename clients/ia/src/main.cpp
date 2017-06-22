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
#include "Player.hpp"

void	usage(void)
{
  std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
  std::cout << "\tport    is the port number" << std::endl;
  std::cout << "\tname    is the name of the team" << std::endl;
  std::cout << "\tmachine is the name of the machine; localhost by default" << std::endl;
}

int	main(void)
{
  try {
    Player player;
    usage();
    while (1)
      {
	player.update();
      }
  }
  catch (Exception const& e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
