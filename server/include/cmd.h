/*
** cmd.h for cmd in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 22 15:56:45 2017 David Zeng
** Last update Thu Jun 22 15:56:45 2017 David Zeng
*/

#ifndef CMD_H_
# define CMD_H_

# include "network.h"
# include "server.h"

/**
 * entity that represent a type of connection
 */
typedef enum	e_entity
  {
    CLIENT,
    PLAYER,
    GRAPHIC,
  }		t_entity;

/**
 * get the entity, the package is from
 */
t_entity	get_entity(t_server *server, t_package *package);

/***********************************************************************
		             RECEIVED CMD
 ***********************************************************************/
typedef void	(*cmd)(t_server *server, t_package *package);

/**
 * CLIENT cmd
 */
extern const cmd g_client_cmd[2];

void		cmd_graphic(t_server *server, t_package *package);
void		cmd_player(t_server *server, t_package *package);

/**
 * PLAYER cmd
 */
extern const cmd g_player_cmd[12];

void		cmd_forward(t_server *server, t_package *package);
void		cmd_right(t_server *server, t_package *package);
void		cmd_left(t_server *server, t_package *package);
void		cmd_look(t_server *server, t_package *package);
void		cmd_inventory(t_server *server, t_package *package);
void		cmd_broadcast(t_server *server, t_package *package);
void		cmd_connect(t_server *server, t_package *package);
void		cmd_fork(t_server *server, t_package *package);
void		cmd_eject(t_server *server, t_package *package);
void		cmd_take(t_server *server, t_package *package);
void		cmd_set(t_server *server, t_package *package);
void		cmd_incantation(t_server *server, t_package *package);

/**
 * GRAPHIC cmd
 */
extern const cmd g_graphic_cmd[9];

// map size
void		cmd_msz(t_server *server, t_package *package);
// case content
void		cmd_bct(t_server *server, t_package *package);
// map content
void		cmd_mct(t_server *server, t_package *package);
// team names
void		cmd_tna(t_server *server, t_package *package);
// player position
void		cmd_ppo(t_server *server, t_package *package);
// player level
void		cmd_plv(t_server *server, t_package *package);
// player inventory
void		cmd_pin(t_server *server, t_package *package);
// current frequency
void		cmd_sgt(t_server *server, t_package *package);
// set frequency
void		cmd_sst(t_server *server, t_package *package);

#endif /* !CMD_H_ */
