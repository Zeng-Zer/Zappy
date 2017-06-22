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
# include "param.h"

/**
 * struct containing server attribute
 */
typedef struct	s_server
{
  // network
  t_network	network;
  // list of task to treat
  t_vector	*cmds;  // TODO CREATE TASK STRUCTURE
  // world map
  t_world	*world;
  // team
  int		nb_team;
  char		**teams;
  // player list
  t_vector	*players;
  // TODO graphic list
  bool		running;
}		t_server;

t_server	init_server(t_param *param);
void		close_server(t_server *server);

#endif /* !SERVER_H_ */
