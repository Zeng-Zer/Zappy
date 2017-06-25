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
#include "utils.h"

/**
 * accept() new client
 */
static void	handle_new_connection(t_network *network)
{
  int		new_fd;
  int		opt;

  opt = 1;
  new_fd = 0;
  while (network->nb_fd <= network->max_client &&
	 (new_fd = accept(network->server_fd, NULL, NULL)) != -1)
    {
      ioctl(new_fd, FIONBIO, &opt);
      printf("\nNew incoming connection - nb: %d\n", network->nb_fd);
      network->fds[network->nb_fd].fd = new_fd;
      network->fds[network->nb_fd].events = POLLIN;
      ++network->nb_fd;
      dprintf(new_fd, "WELCOME\n");
    }
  if (new_fd == -1 && errno != EWOULDBLOCK)
    network_fail(network, "Server: accept failed");
}

/**
 * return true if we decrement nb_fd
 */
static bool	handle_new_events(t_vector *packages, t_network *network, int i)
{
  int		status;
  char		*input;

  while ((input = get_input(network->fds[i].fd, &status)))
    {
      vector_push(packages, new_package(network->fds[i].fd, input, false));
    }
  if (status == INPUT_FAILURE || status == CONNECTION_CLOSED)
    {
      vector_push(packages, new_package(network->fds[i].fd, NULL, true));
      close(network->fds[i].fd);
      network->fds[i].fd = -1;
      return (true);
    }
  return (false);
}

void	close_connection(t_network *network, int fd)
{
  int	i;

  i = -1;
  while (++i < network->nb_fd)
    {
      if (network->fds[i].fd == fd)
	{
	  while (i < network->nb_fd)
	    {
	      close(fd);
	      network->fds[i].fd = network->fds[i + 1].fd;
	      ++i;
	    }
	  --network->nb_fd;
	  break;
	}
    }
}

void	clean_fd(t_network *network)
{
  int	i;
  int	j;

  i = -1;
  while (++i < network->nb_fd)
    {
      if (network->fds[i].fd == -1)
	{
	  j = i - 1;
	  while (++j < network->nb_fd)
	    {
	      network->fds[j].fd = network->fds[j + 1].fd;
	    }
	  --network->nb_fd;
	}
    }
}

t_vector	*poll_event(t_network *network)
{
  t_vector	*packages;
  int		cur;
  int		i;
  bool		clean;

  if (!has_event(network) || !(packages = vector_new()))
    return (NULL);
  i = -1;
  cur = network->nb_fd;
  clean = false;
  while (++i < cur)
    {
      if (!network->fds[i].revents)
	continue;
      if (network->fds[i].revents != POLLIN)
	network_fail(network, "Server: poll() unexpected revents value");
      if (network->fds[i].fd == network->server_fd)
	handle_new_connection(network);
      else
	clean = handle_new_events(packages, network, i);
    }
  if (clean)
    clean_fd(network);
  return (packages);
}
