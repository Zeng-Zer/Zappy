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
# include <getopt.h>
# include <string.h>
# include <errno.h>
# include "utils.h"

# define DEFAULT_PORT 4242
# define DEFAULT_NB_CLIENT 3
# define DEFAULT_DIMENSION (t_pos){10, 10}
# define DEFAULT_FREQUENCY 100

/**
 * struct that describes program parameters parsed by getopt()
 */
typedef struct	s_param
{
  short		port;
  t_pos		dimension;
  char		**teams;
  int		nb_client;
  short		frequency;
}		t_param;

typedef int (*fptr)(t_param *, int, char **);

typedef struct	s_pair
{
  char		c;
  fptr		func;
}		t_pair;

/**
 * parse program parameter in t_param
 */
t_param		parse_args(int argc, char *argv[]);

/**
 * helper functions
 */
void		usage(char *prog);
int		param_port(t_param *param, int argc, char **argv);
int		param_width(t_param *param, int argc, char **argv);
int		param_height(t_param *param, int argc, char **argv);
int		param_name(t_param *param, int argc, char **argv);
int		param_client(t_param *param, int argc, char **argv);
int		param_help(t_param *param, int argc, char **argv);
int		param_freq(t_param *param, int argc, char **argv);

/**
 * debug function that dumps param structure
 */
void		param_dump(t_param *param);
/**
 * add default parameter to missing one
 */
void		param_default(t_param *param);
#endif /* !PARAM_H_ */
