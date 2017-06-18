/*
** param.h for param in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 18 18:03:56 2017 David Zeng
** Last update Sun Jun 18 18:03:56 2017 David Zeng
*/

#ifndef PARAM_H_
# define PARAM_H_

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <strings.h>
# include <getopt.h>
# include "utils.h"

typedef struct	s_param
{
  short		port;
  t_pos		dimension;
  char		**names;
  int		nb_client;
  short		frequency;
}		t_param;

typedef int (*fptr)(t_param *, int, char **);

typedef struct	s_pair
{
  char		c;
  fptr		func;
}		t_pair;

t_param		parse_args(int argc, char *argv[]);
void		usage(char *prog);

int		param_port(t_param *param, int argc, char **argv);
int		param_width(t_param *param, int argc, char **argv);
int		param_height(t_param *param, int argc, char **argv);
int		param_name(t_param *param, int argc, char **argv);
int		param_client(t_param *param, int argc, char **argv);
int		param_help(t_param *param, int argc, char **argv);
int		param_freq(t_param *param, int argc, char **argv);

#endif /* !PARAM_H_ */
