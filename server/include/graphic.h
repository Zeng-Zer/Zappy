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

typedef struct	s_egg t_egg;

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

void		graphic_pie(int fd, t_pos pos, bool elevation);
void		graphic_pic(int fd, t_player *player, t_tile *tile);
void		graphic_pex(int fd, t_player *player);
void		graphic_pnw(int fd, t_server *server, t_player *player);
void		graphic_pbc(int fd, t_player *player, char *msg);
void		graphic_enw(int fd, int id, t_egg *egg);
void		graphic_pdi(int fd, t_player *player);
void		graphic_pgt(int fd, t_player *player, t_stone res);
void		graphic_pdr(int fd, t_player *player, t_stone res);
void		graphic_pfk(int fd, t_player *player);
void		graphic_eht(int fd, t_egg *egg);
void		graphic_ebo(int fd, t_egg *egg);
void		graphic_seg(int fd, char *team);
void		multi_graphic_pnw(t_vector *, t_server *, t_player *);
void		multi_graphic_ebo(t_vector *graphics, t_egg *egg);
void		multi_graphic_ppo(t_vector *graphics, t_player *player);
void		multi_graphic_take(t_vector *, t_world *, t_player *, t_stone);
void		multi_graphic_set(t_vector *, t_world *, t_player *, t_stone);
void		multi_graphic_eject(t_vector *, t_server *, t_player *);
void		multi_graphic_broadcast(t_vector *, t_player *, char *);
void		multi_graphic_pic(t_vector *, t_player *, t_tile *);
void		multi_graphic_pie(t_vector *, t_pos, bool, t_server *);
void		multi_graphic_pfk(t_vector *graphics, t_player *player);
void		multi_graphic_enw(t_vector *, t_player *, t_egg *);
void		multi_graphic_eht(t_vector *graphics, t_egg *egg);
void		multi_graphic_pdi(t_vector *graphics, t_player *player);
void		multi_graphic_seg(t_vector *graphics, char *team);

#endif /* !GRAPHIC_H_ */
