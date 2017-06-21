/*
** parse_args.c for parse_args in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Mar  7 01:39:10 2017 David Zeng
** Last update Tue Mar  7 01:39:10 2017 David Zeng
*/

#include "param.h"

static const struct option long_option[] = {
  {"port", required_argument, 0, 'p'},
  {"width", required_argument, 0, 'x'},
  {"height", required_argument, 0, 'y'},
  {"nameX", required_argument, 0, 'n'},
  {"clientsNb", required_argument, 0, 'c'},
  {"freq", required_argument, 0, 'f'},
  {"help", required_argument, 0, 'h'},
  {NULL, 0, 0, 0},
};

static const char *optstring = "p:x:y:n:c:f:h";

static t_pair pair[] = {
  {'p', param_port},
  {'x', param_width},
  {'y', param_height},
  {'n', param_name},
  {'c', param_client},
  {'f', param_freq},
  {'h', param_help},
};

void	param_dump(t_param *param)
{
  printf("param:\n");
  printf("  port %d\n", param->port);
  printf("  pos: x %d, y %d\n", param->dimension.x, param->dimension.y);
  for (int i = 0; param->names && param->names[i] != NULL; ++i)
    printf("  team %d %s\n", i, param->names[i]);
  printf("  nb client %d\n", param->nb_client);
  printf("  frequency %d\n", param->frequency);
}

void	usage(char *prog)
{
  fprintf(stderr, "USAGE: %s -p port -x width -y height -n name1 name2", prog);
  fprintf(stderr, " ... -c clientsNb -f freq\n");
  fprintf(stderr, "\tport\t\tis the port number\n");
  fprintf(stderr, "\twidth\t\tis the width of the world\n");
  fprintf(stderr, "\theight\t\tis the height of the world\n");
  fprintf(stderr, "\tnameX\t\tis the name of the team X\n");
  fprintf(stderr, "\tclientsNb\tis the number of authorized clients per"
	  " team\n");
  fprintf(stderr, "\tfreq\t\tis the reciprocal of time unit for execution of"
	  " actions\n");
}

static int	process_arg(char c, t_param *param, int argc, char *argv[])
{
  size_t	i;
  size_t	size;

  size = sizeof(pair) / sizeof(*pair);
  i = 0;
  while (i < size)
    {
      if (c == pair[i].c)
	return (pair[i].func(param, argc, argv));
      ++i;
    }
  return (0);
}

t_param		parse_args(int argc, char *argv[])
{
  t_param	param;
  int		c;

  bzero(&param, sizeof(t_param));
  while ((c = getopt_long_only(argc, argv, optstring, long_option, 0)) != -1)
    {
      if (process_arg(c, &param, argc, argv) != 0)
	{
	  usage(argv[0]);
	  exit(84);
	}
    }
  return (param);
}
