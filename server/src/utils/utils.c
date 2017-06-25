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
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

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

long long		current_time()
{
  struct timespec	spec;
  long long		ms;

  clock_gettime(CLOCK_REALTIME, &spec);
  ms = spec.tv_sec * 1000 + spec.tv_nsec / 1.0e6;
  return (ms);
}

char		**split(char *str, char *delim)
{
  char		**tab;
  char		*ptr;
  int		i;
  char		*buf;

  if (!str)
    return (NULL);
  tab = malloc(sizeof(char*) * (strlen(str) + 1));
  if (!tab || !(buf = strdup(str)))
    return (NULL);
  ptr = strtok(buf, delim);
  i = 0;
  while (ptr)
    {
      if (ptr[0] != '\0')
	{
	  tab[i++] = strdup(ptr);
	  if (!tab[i - 1])
	    return (NULL);
	}
      ptr = strtok(NULL, delim);
    }
  tab[i] = NULL;
  free(buf);
  return (tab);
}

bool	match_first_word(char const *str, char const *to_match)
{
  char	sep;

  return (strncmp(str, to_match, strlen(to_match)) == 0 &&
	  ((sep = str[strlen(to_match)]) == ' ' || sep == '\0'));
}
