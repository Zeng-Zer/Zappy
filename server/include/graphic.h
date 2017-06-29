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
void		graphic_sbp(t_graphic *graphic);
void		graphic_msz(int fd, t_world *world);
void		graphic_bct(int fd, t_world *world, t_pos pos);
void		graphic_mct(int fd, t_world *world);
void		graphic_tna(int fd, t_server *server);
void		graphic_ppo(int fd, t_player *player);
void		graphic_plv(int fd, t_player *player);
void		graphic_pin(int fd, t_player *player);
void		graphic_sgt(int fd, t_server *server);
void		graphic_sst(int fd, t_server *server, int freq);

#endif /* !GRAPHIC_H_ */
