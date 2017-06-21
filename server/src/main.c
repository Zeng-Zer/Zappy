/*
** main.c for main in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Jan 23 17:57:49 2017 David Zeng
** Last update Mon Jan 23 17:57:49 2017 David Zeng
*/

#include "param.h"
#include "network.h"

int		main(int argc, char *argv[])
{
  t_param	param;
  t_network	network;
  t_vector	*packages;

  param = parse_args(argc, argv);
  if (!param.port)
    param.port = DEFAULT_PORT;
  if (!param.nb_client)
    param.nb_client = param.nb_client * (tablen(param.names) + 1);
  param_dump(&param);
  network = init_network(param.port);
  while (1)
    {
      packages = poll_event(&network);
      packages_dump(packages);
      vector_delete(packages, free_package);
    }
  return (0);
}
