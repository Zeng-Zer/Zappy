/*
** utils.h for utils in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 14 03:50:45 2017 David Zeng
** Last update Wed Jun 14 03:50:45 2017 David Zeng
*/

#ifndef UTILS_H_
# define UTILS_H_

/**
 * position in 2D
 */
typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

/**
 * free 2D array
 */
void		free_tab(char **tab);
/**
 * 2D array length
 */
int		tablen(char **tab);
/**
 * send a message in fd return 0 on success and -1 on failure
 */
int		send_msg(int fd, char *msg);

/**
 * get current time in millisecond
 */
long long	current_time();

/**
 * split str with delim
 */
char		**split(char *str, char *delim);

#endif /* !UTILS_H_ */
