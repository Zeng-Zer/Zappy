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
#include "utils.h"
#include "network.h"

int		main(int argc, char *argv[])
{
  t_param	param;
  t_network	network;

  param = parse_args(argc, argv);
  dump_param(&param); // TODO remove debug func
  network = init_network(param.port ? param.port : 4242,
			 param.nb_client ? param.nb_client : 10);
  while (1)
    {
      poll_event(&network);
    }
  return (0);
}
