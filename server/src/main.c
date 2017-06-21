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
  t_vector	*events;

  param = parse_args(argc, argv);
  network = init_network(param.port ? param.port : DEFAULT_PORT,
			 param.nb_client ? param.nb_client : DEFAULT_NB_CLIENT);
  while (1)
    {
      events = poll_event(&network);
      packages_dump(events);
      vector_delete(events, free_package);
    }
  return (0);
}
