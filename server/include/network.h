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

# include <fcntl.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/poll.h>
# include <time.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>

/**
 * struct that represents a network connection
 */
typedef struct	s_network
{
  short		port;
  int		max_client;
  int		server_fd;
  struct pollfd	fds[256];
  int		nb_fd;
}		t_network;

/**
 * initialize a network socket
 * exit 84 on failure
 */
t_network	init_network(short port, int max_client);
/**
 * close network connection
 */
void		close_network(t_network *network);

/**
 * Package: contains the timestamp and the message
 */
typedef struct	s_package
{
  time_t	timestamp;
  char		*msg;
}		t_package;

t_package	poll_event(t_network *network);

#endif /* !NETWORK_H_ */
