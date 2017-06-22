/*
** main.c for main in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Jan 23 17:57:49 2017 David Zeng
** Last update Mon Jan 23 17:57:49 2017 David Zeng
*/

#include "server.h"

int		main(int argc, char *argv[])
{
  t_param	param;
  t_server	server;
  t_vector	*packages;

  param = parse_args(argc, argv);
  param_default(&param);
  param_dump(&param);
  server = init_server(&param);
  while (server.running)
    {
      packages = poll_event(&server.network);
      packages_dump(packages);
      vector_delete(packages, free_package);
    }
  return (0);
}
