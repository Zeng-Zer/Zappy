/*
** server.h for server in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 15 23:47:08 2017 David Zeng
** Last update Thu Jun 15 23:47:08 2017 David Zeng
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "network.h"
# include "world.h"

/**
 * struct containing server attribute
 */
typedef struct	s_server
{
  // network
  t_network	network;
  // TODO list of task to treat
  // world map
  t_world	*world;
  // nb of team
  int		nb_team;
  // TODO player list
}		t_server;

#endif /* !SERVER_H_ */
