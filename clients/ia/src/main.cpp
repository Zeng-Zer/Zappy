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


int	main(int argc, char **argv)
{
  try {
    Param args(argc, argv);

    struct ConnectionInit {
      ConnectionInit(Param args) {
        Connection::initConnection(args.getPort(), args.getHost());
      }

      ~ConnectionInit() {
        Connection::destroyConnection();
      }
    } ConnectionIniter(args);

    // Player player;
    // while (1)
    //   {
    // 	player.update();
    //   }
  }
  catch (Exception const& e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
