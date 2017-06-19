/*
** poll.c for poll in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jun 20 00:02:22 2017 David Zeng
** Last update Tue Jun 20 00:02:22 2017 David Zeng
*/

#include "network.h"

static void	network_fail(t_network *network, char const *msg)
{
  fprintf(stderr, "%s\n", msg);
  close_network(network);
  exit(84);
}

/**
 * check if there is an event with poll()
 */
static bool	has_event(t_network *network)
{
  int		ret;

  /* fprintf(stderr, "polling !\n"); */
  if ((ret = poll(network->fds, network->nb_fd, 10000)) == -1)
    network_fail(network, "Server: poll() failed");
  return (ret != 0);
}

/**
 * accept() new client
 */
static void	handle_new_connection(t_network *network, int i)
{
  int		new_fd;
  int		opt;

  opt = 1;
  new_fd = 0;
  while ((new_fd = accept(network->server_fd, NULL, NULL)) != -1)
    {
      ioctl(new_fd, FIONBIO, &opt);
      fprintf(stderr, "  New incoming connection - %d\n", new_fd);
      network->fds[network->nb_fd].fd = new_fd;
      network->fds[network->nb_fd].events = POLLIN;
      ++network->nb_fd;
    }
  if (new_fd == -1 && errno != EWOULDBLOCK)
    network_fail(network, "Server: accept failed");
}

t_package	poll_event(t_network *network)
{
  t_package	pkg;
  int		cur;
  int		i;

  bzero(&pkg, sizeof(pkg));
  if (!has_event(network))
    return (pkg);
  i = -1;
  cur = network->nb_fd;
  while (++i < cur)
    {
      if (!network->fds[i].revents)
	continue;
      if (network->fds[i].revents != POLLIN)
	network_fail(network, "Server: poll() unexpected revents value");
      if (network->fds[i].fd == network->server_fd)
	handle_new_connection(network, i);
      else
	(void)0; // TODO handle disconnect / message
    }
  return (pkg);
}
