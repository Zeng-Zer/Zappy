/*
** package.h for package in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 15 23:38:19 2017 David Zeng
** Last update Thu Jun 15 23:38:19 2017 David Zeng
*/

#ifndef PACKAGE_H_
# define PACKAGE_H_

# include <time.h>

/**
 * Package: contains the timestamp and the message
 */
typedef struct	s_package
{
  time_t	timestamp;
  char		*msg;
}		t_package;

#endif /* !PACKAGE_H_ */
