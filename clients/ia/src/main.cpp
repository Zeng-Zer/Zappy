/*
** main.c for main in
**
** Made by Jamy Bailly
** Login   <baillyj@epitech.net>
**
** Started on  Thu Jun 22 15:32:00 2017 Jamy Bailly
** Last update Thu Jun 22 15:32:00 2017 Jamy Bailly
*/

#include <stdio.h>

void	usage(void)
{
  puts("USAGE: ./zappy_ai -p port -n name -h machine");
  puts("\tport    is the port number");
  puts("\tname    is the name of the team");
  puts("\tmachine is the name of the machine; localhost by default");
}

int	main(void)
{
  usage();
  return (0);
}
