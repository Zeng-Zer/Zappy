/*
** graphic_cmd5.c for graphic_cmd5 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 29 18:45:13 2017 David Zeng
** Last update Thu Jun 29 18:45:13 2017 David Zeng
*/

#include "cmd.h"
#include "egg.h"

void	graphic_eht(int fd, t_egg *egg)
{
  dprintf(fd, "eht %d\n", (int)egg);
}

void	graphic_ebo(int fd, t_egg *egg)
{
  dprintf(fd, "ebo %d\n", (int)egg);
}

void	graphic_seg(int fd, char *team)
{
  dprintf(fd, "seg %s\n", team);
}
