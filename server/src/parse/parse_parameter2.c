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
