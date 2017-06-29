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
# include "player.h"

# define END_TIME(t) (long long)(t / server->frequency * 1000)

/**
 * entity that represent a type of connection
 */
typedef enum	e_entity
  {
    CLIENT,
    PLAYER,
    GRAPHIC,
  }		t_entity;

typedef void	(*cmd)(t_server *, t_command *);

typedef struct	s_cmd
{
  char const	*key;
  cmd		cmd;
  // time to complete task -> x <- / f
  float		time;
}		t_cmd;

typedef struct	s_command
{
  cmd		action;
  long long	end_time;
  // player or graphic
  void		*entity;
  // package char *
  void		*item;
  // start countdown ?
  bool		start;
  bool		delete;
}		t_command;

t_command	*create_command(cmd, long long, void *, void *);
void		free_command(void *item);

/**
 * handle one package
 */
void		handle_cmd(t_server *server, t_package *package);

/***********************************************************************
		             RECEIVED CMD
 ***********************************************************************/

/**
 * CLIENT cmd
 */
void		cmd_graphic(t_server *server, t_package *package);
void		cmd_player(t_server *server, t_package *package);

/**
 * PLAYER cmd
 */
extern const t_cmd g_player_cmd[];

void		cmd_forward(t_server *server, t_command *command);
void		cmd_right(t_server *server, t_command *command);
void		cmd_left(t_server *server, t_command *command);
void		cmd_look(t_server *server, t_command *command);
void		cmd_inventory(t_server *server, t_command *command);
void		cmd_broadcast(t_server *server, t_command *command);
void		cmd_connect(t_server *server, t_command *command);
void		cmd_fork(t_server *server, t_command *command);
void		cmd_eject(t_server *server, t_command *command);
void		cmd_take(t_server *server, t_command *command);
void		cmd_set(t_server *server, t_command *command);
void		cmd_incant(t_server *server, t_command *command);

/**
 * GRAPHIC cmd
 */
extern const t_cmd g_graphic_cmd[];

// map size
void		cmd_msz(t_server *server, t_command *command);
// case content
void		cmd_bct(t_server *server, t_command *command);
// map content
void		cmd_mct(t_server *server, t_command *command);
// team names
void		cmd_tna(t_server *server, t_command *command);
// player position
void		cmd_ppo(t_server *server, t_command *command);
// player level
void		cmd_plv(t_server *server, t_command *command);
// player inventory
void		cmd_pin(t_server *server, t_command *command);
// current frequency
void		cmd_sgt(t_server *server, t_command *command);
// set frequency
void		cmd_sst(t_server *server, t_command *command);

/**
 * helper function
 */
int		nb_player_team(t_vector *players, int team_id);
t_player	*find_player(t_vector *players, int id);
int		broadcast_dir(t_world *world, t_player *from, t_player *other);

#endif /* !CMD_H_ */
