/*
** utils.c for utils in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jun 20 21:34:29 2017 David Zeng
** Last update Tue Jun 20 21:34:29 2017 David Zeng
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (!tab)
    return;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
}

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i])
    ++i;
  return (i);
}

int	send_msg(int fd, char *msg)
{
  if (dprintf(fd, "%s\n", msg) < 0)
    return (-1);
  return (0);
}

long long		current_time()
{
  struct timespec	spec;
  long long		ms;

  clock_gettime(CLOCK_REALTIME, &spec);
  ms = spec.tv_sec * 1000 + spec.tv_nsec / 1.0e6;
  return (ms);
}
