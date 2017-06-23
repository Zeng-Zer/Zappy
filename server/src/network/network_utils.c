/*
** network_utils.c for network_utils in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 21 00:53:17 2017 David Zeng
** Last update Wed Jun 21 00:53:17 2017 David Zeng
*/

#include "network.h"

void	network_fail(t_network *network, char const *msg)
{
  fprintf(stderr, "%s\n", msg);
  close_network(network);
  exit(84);
}

/**
 * check if there is an event with poll()
 */
bool	has_event(t_network *network)
{
  int	ret;

  if ((ret = poll(network->fds, network->nb_fd, 0)) == -1)
    {
      if (errno == EINTR)
	return (false);
      network_fail(network, "Server: poll() failed");
    }
  return (ret != 0);
}
