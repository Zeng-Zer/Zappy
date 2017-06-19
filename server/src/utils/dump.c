/*
** dump.c for dump in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 18 22:47:12 2017 David Zeng
** Last update Sun Jun 18 22:47:12 2017 David Zeng
*/

#include "param.h"

void	dump_param(t_param *param)
{
  printf("port %d\n", param->port);
  printf("pos: x %d, y %d\n", param->dimension.x, param->dimension.y);
  for (int i = 0; param->names && param->names[i] != NULL; ++i)
    printf("team %d %s\n", i, param->names[i]);
  printf("nb client %d\n", param->nb_client);
  printf("frequency %d\n", param->frequency);
}
