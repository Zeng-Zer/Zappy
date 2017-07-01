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
# include <sys/resource.h>

# include "vector.h"

# define INPUT_FAILURE 1
# define CONNECTION_CLOSED 2

/**
 * struct that represents a network connection
 */
typedef struct	s_network
{
  short		port;
  int		max_client;
  int		server_fd;
  struct pollfd	*fds;
  int		nb_fd;
}		t_network;

/**
 * initialize a network socket
 * exit 84 on failure
 */
t_network	init_network(short port);
/**
 * close network connection
 */
void		close_network(t_network *network);

/**
 * Package: contains the timestamp and the message
 */
typedef struct	s_package
{
  // client id
  int		fd;
  char		*msg;
  bool		close;
}		t_package;

/**
 * package functions
 */
t_package	*new_package(int fd, char *msg, bool to_close);
void		free_package(void *item);
void		packages_dump(t_vector *packages);
void		package_dump(t_package *package);

/**
 * return t_vector of t_package
 */
t_vector	*poll_event(t_network *network);
/**
 * clean fd that are equals to -1
 */
void		clean_fd(t_network *network);
/**
 * close a fd
 */
void		close_connection(t_network *network, int fd);

/**
 * get input from file descriptor and write status to status
 */
char		*get_input(int fd, int *status);

/**
 * utils function
 */
void		network_fail(t_network *network, char const *msg);
bool		has_event(t_network *network);
bool		clean_pollin(t_vector *packages, t_network *network, int i);

#endif /* !NETWORK_H_ */
