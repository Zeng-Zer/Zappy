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

void		free_tab(char **tab)
{
  int		i;

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
