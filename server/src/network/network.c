/*
** network.c for  in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Jun 19 00:04:20 2017 David Zeng
** Last update Mon Jun 19 00:04:20 2017 David Zeng
*/

#include "network.h"

static void	check_error(int val, char const *msg, int fd, int fd2)
{
  if (val == -1)
    {
      fprintf(stderr, "%s\n", msg);
      if (fd != -1)
	close(fd);
      if (fd2 != -1)
	close(fd2);
      exit(84);
    }
}

static int	get_max_client()
{
  struct rlimit	rlp;

  if (getrlimit(RLIMIT_NOFILE, &rlp) == -1)
    {
      fprintf(stderr, "Server: getrlimit() failed\n");
      exit(84);
    }
  return (rlp.rlim_cur);
}

static int		init_socket(short port, int max_client)
{
  int			fd;
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  int			option;

  pe = getprotobyname("TCP");
  check_error(-(!pe), "Server: getprotobyname() failed", -1, -1);
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  check_error(fd, "Server: socket()", -1, -1);
  option = 1;
  check_error(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)),
	      "Server: setsockopt() failed", fd, -1);
  check_error(ioctl(fd, FIONBIO, &option), "Server: ioctl() failed", fd, -1);
  bzero(&s_in, sizeof(s_in));
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  check_error(bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)),
	      "Server: bind() failed", fd, -1);
  check_error(listen(fd, max_client), "Server: listen() failed", fd, -1);
  fprintf(stderr, "Server initialized\n");
  return (fd);
}

t_network	init_network(short port)
{
  t_network	network;
  int		max_client;

  max_client = get_max_client();
  network.port = port;
  network.max_client = max_client;
  network.server_fd = init_socket(port, max_client);
  printf("network server fd: %d\n", network.server_fd);
  if (!(network.fds = malloc(sizeof(*network.fds) * (max_client + 1))))
    {
      fprintf(stderr, "Server: malloc() failed\n");
      exit(84);
    }
  bzero(network.fds, sizeof(*network.fds) * (max_client + 1));
  network.fds[0].fd = network.server_fd;
  network.fds[0].events = POLLIN;
  network.nb_fd = 1;
  return (network);
}

void	close_network(t_network *network)
{
  int	i;

  i = -1;
  while (++i < network->nb_fd)
    {
      if (network->fds[i].fd >= 0)
	close(network->fds[i].fd);
    }
  free(network->fds);
}
