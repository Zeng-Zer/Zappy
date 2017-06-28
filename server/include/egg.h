/*
** egg.h for egg in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 28 00:00:48 2017 David Zeng
** Last update Wed Jun 28 00:00:48 2017 David Zeng
*/

#ifndef EGG_H_
# define EGG_H_

# include "utils.h"

typedef struct	s_egg
{
  int		team_id;
  t_pos		pos;
  bool		hatched;
  long long	end_time;
}		t_egg;

t_egg		*create_egg(int team_id, t_pos *pos, long long end_time);
void		free_egg(void *item);

#endif /* !EGG_H_ */
