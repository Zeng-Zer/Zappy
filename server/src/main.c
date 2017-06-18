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

int		main(int argc, char *argv[])
{
  t_param	param;

  param = parse_args(argc, argv);
  printf("port %d\n", param.port);
  printf("pos: x %d, y %d\n", param.dimension.x, param.dimension.y);
  for (int i = 0; param.names && param.names[i] != NULL; ++i)
    printf("team %d %s\n", i, param.names[i]);
  printf("nb client %d\n", param.nb_client);
  printf("frequency %d\n", param.frequency);
  return (0);
}
