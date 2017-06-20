/*
** get_input.c for get_input in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun May 14 20:12:12 2017 David Zeng
** Last update Sun May 14 20:12:12 2017 David Zeng
*/

#include "network.h"
#include "utils.h"

static bool	malloc_ok(void *ptr, int *status)
{
  if (!ptr)
    {
      *status = INPUT_FAILURE;
      return (false);
    }
  return (true);
}

static int	read_input(int fd, char *buf, int *status)
{
  int		ret;

  if ((ret = read(fd, buf, 4096)) <= 0)
    {
      if (ret < 0 && errno != EWOULDBLOCK)
	*status = INPUT_FAILURE;
      if (ret == 0)
	*status = CONNECTION_CLOSED;
      return (-1);
    }
  buf[ret] = '\0';
  return (ret);
}

static char	*new_line(int fd, char *sep, int *status)
{
  char		buf[4097];
  int		ret;
  char		*line;

  line = NULL;
  while (line == NULL || !(strlen(line) > strlen(sep) &&
			   strcmp(line + strlen(line) - strlen(sep), sep) == 0))
    {
      if ((ret = read_input(fd, buf, status)) == -1)
	return (NULL);
      if (!line)
	line = strdup(buf);
      else
	{
	  line = realloc(line, strlen(line) + ret + 1);
	  if (line)
	    strcat(line, buf);
	}
    }
  if (!malloc_ok(line, status))
    return (NULL);
  line[strlen(line) - strlen(sep)] = '\0';
  return (line);
}

static char	**str_tab(char *str, char *delim, int *status)
{
  char		**tab;
  char		*ptr;
  int		i;

  tab = malloc(sizeof(char*) * (strlen(str) + 1));
  if (!malloc_ok(tab, status))
    return (NULL);
  ptr = strtok(str, delim);
  i = 0;
  while (ptr)
    {
      if (ptr[0] != '\0')
	{
	  tab[i++] = strdup(ptr);
	  if (!malloc_ok(tab[i - 1], status))
	    return (NULL);
	}
      ptr = strtok(NULL, delim);
    }
  tab[i] = NULL;
  return (tab);
}

char		*get_input(int fd, int *status)
{
  char		*line;
  static char	**ptr = NULL;
  static char	**tab = NULL;

  *status = 0;
  if (!tab || !*tab)
    {
      free_tab(ptr);
      line = new_line(fd, "\n", status);
      if (!line)
	{
	  ptr = NULL;
	  tab = NULL;
	  return (NULL);
	}
      tab = str_tab(line, "\n", status);
      ptr = tab;
      free(line);
    }
  line = strdup(tab[0]);
  ++tab;
  if (!line)
    *status = INPUT_FAILURE;
  return (line);
}
