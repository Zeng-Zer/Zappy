/*
** cmd_player.c for cmd_player in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Jun 24 17:00:31 2017 David Zeng
** Last update Sat Jun 24 17:00:31 2017 David Zeng
*/

#include "cmd.h"

void		cmd_forward(t_server *server, t_package *package, char **cmd)
{
  t_player	*player;

  if (!(player = find_player(server->players, package->fd)))
    return;
}

void		cmd_right(t_server *server, t_package *package, char **cmd)
{

}

void		cmd_left(t_server *server, t_package *package, char **cmd)
{

}

void		cmd_look(t_server *server, t_package *package, char **cmd)
{

}

void		cmd_inventory(t_server *server, t_package *package, char **cmd)
{

}
