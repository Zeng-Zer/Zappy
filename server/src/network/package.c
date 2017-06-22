/*
** package.c for package in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 21 00:57:27 2017 David Zeng
** Last update Wed Jun 21 00:57:27 2017 David Zeng
*/

#include "utils.h"
#include "network.h"

t_package	*new_package(int fd, char *msg, bool to_close)
{
  t_package	*package;

  if (!(package = malloc(sizeof(*package))))
    return (NULL);
  package->fd = fd;
  package->msg = msg;
  package->timestamp = current_time();
  package->close = to_close;
  return (package);
}

void		free_package(void *item)
{
  t_package	*package;

  package = item;
  if (package)
    {
      free(package->msg);
      free(package);
    }
}

void		package_dump(t_package *package)
{
  if (package)
    {
      printf("\npackage:\n");
      printf("  fd %d\n", package->fd);
      printf("  timestamp %llu\n", package->timestamp);
      printf("  msg %s\n", package->msg);
      printf("  close %d\n", package->close);
    }
}

void		packages_dump(t_vector *packages)
{
  size_t	i;

  if (packages)
    {
      i = -1;
      while (++i < packages->length)
	package_dump(packages->items[i]);
    }
}
