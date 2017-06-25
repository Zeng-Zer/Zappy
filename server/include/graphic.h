/*
** graphic.h for  in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 25 16:03:28 2017 David Zeng
** Last update Sun Jun 25 16:03:28 2017 David Zeng
*/

#ifndef GRAPHIC_H_
# define GRAPHIC_H_

# include "vector.h"
# include "cmd.h"

/**
 * struct that represents a graphic monitor
 */
typedef struct	s_graphic
{
  // fd
  int		id;
  // graphic cmds
  t_vector	*cmds;
}		t_graphic;

// create a new graphic
t_graphic	*new_graphic(int fd);
void		free_graphic(void *item);

void		add_graphic_cmd(t_graphic *graphic, t_command *cmd);

#endif /* !GRAPHIC_H_ */
