/*
** network.h for network in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 15 23:51:14 2017 David Zeng
** Last update Thu Jun 15 23:51:14 2017 David Zeng
*/

#ifndef NETWORK_H_
# define NETWORK_H_

/**
 * struct that represents a network connection
 */
typedef struct	s_network
{
  int		port;
}		t_network;

/**
 * initialize a network socket
 * return 0 on success and -1 on failure
 */
int		init_network(t_network *network);

#endif /* !NETWORK_H_ */
