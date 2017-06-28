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
  // list of cmd to treat
  t_vector	*cmds;
  // world map
  t_world	*world;
  // team
  int		nb_team;
  int		max_client;
  char		**teams;
  // player list
  t_vector	*players;
  // graphic list
  t_vector	*graphic;
  // eggs list
  t_vector	*eggs;
  bool		running;
  // frequency
  int		frequency;
}		t_server;

t_server	init_server(t_param *param);
void		close_server(t_server *server);

/**
 * main server function
 */
void		server_update(t_server *server);
/**
 * parse and interpret every packages
 */
void		handle_packages(t_server *server, t_vector *packages);

#endif /* !SERVER_H_ */
