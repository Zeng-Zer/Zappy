/*
** parse_parameter2.c for parse_parameter2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 18 20:52:57 2017 David Zeng
** Last update Sun Jun 18 20:52:57 2017 David Zeng
*/

#include "param.h"

int	param_freq(t_param *param, int argc, char **argv)
{
  char	*str;

  (void)argc;
  (void)argv;
  str = NULL;
  param->frequency = strtol(optarg, &str, 0);
  errno = 0;
  if (errno == ERANGE || (str != NULL && strcmp(str, "") != 0))
    {
      fprintf(stderr, "Error: failed to parse frequency \"%s\"\n", optarg);
      return (1);
    }
  if (param->frequency < 2 || param->frequency > 10000)
    {
      fprintf(stderr, "-f option only accepts integer"
	      " values between 2 and 10000\n");
      return (1);
    }
  return (0);
}

int	param_help(t_param *param, int argc, char **argv)
{
  (void)param;
  (void)argc;
  (void)argv;
  usage(argv[0]);
  exit(84);
}

static bool	exist(char **tab, int index, char *to_find)
{
  while (--index >= 0)
    {
      if (strcmp(tab[index], to_find) == 0)
	return (true);
    }
  return (false);
}

int	param_name(t_param *param, int argc, char **argv)
{
  int	i;
  int	size;

  i = --optind;
  size = 0;
  while (i + size < argc && *argv[i + size] != '-')
    ++size;
  param->teams = malloc(sizeof(char*) * (size + 1));
  if (!param->teams)
    exit(84);
  while (optind < argc && *argv[optind] != '-')
    {
      if (!exist(param->teams, optind - i, argv[optind]))
	{
	  param->teams[optind - i] = strdup(argv[optind]);
	  if (!param->teams[optind - i])
	    exit(84);
	}
      else
	++i;
      ++optind;
    }
  param->teams[optind - i] = NULL;
  return (0);
}
