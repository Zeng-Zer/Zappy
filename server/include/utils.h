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

// forward declaration for param
typedef struct	s_param t_param;

/**
 * position in 2D
 */
typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

/**
 * debug function that dumps param structure
 */
void	dump_param(t_param *param);

#endif /* !UTILS_H_ */
