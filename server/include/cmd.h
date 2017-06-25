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

/**
 * entity that represent a type of connection
 */
typedef enum	e_entity
  {
    CLIENT,
    PLAYER,
    GRAPHIC,
  }		t_entity;

typedef struct	s_command t_command;

typedef void	(*cmd_action)(t_server *server, t_command *cmd);

struct s_command
{
  cmd_action	action;
  long long	timestamp;
  long long	end_time;
  void		*item;
};

typedef void	(*cmd)(t_server *, t_package *, char **);

typedef struct	s_cmd
{
  char const	*key;
  cmd		cmd;
}		t_cmd;

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
void		cmd_graphic(t_server *server, t_package *package, char **cmd);
void		cmd_player(t_server *server, t_package *package, char **cmd);

/**
 * PLAYER cmd
 */
extern const t_cmd g_player_cmd[];

void		cmd_forward(t_server *, t_package *, char **);
void		cmd_right(t_server *, t_package *, char **);
void		cmd_left(t_server *, t_package *, char **);
void		cmd_look(t_server *, t_package *, char **);
void		cmd_inventory(t_server *, t_package *, char **);
void		cmd_broadcast(t_server *, t_package *, char **);
void		cmd_connect(t_server *, t_package *, char **);
void		cmd_fork(t_server *, t_package *, char **);
void		cmd_eject(t_server *, t_package *, char **);
void		cmd_take(t_server *, t_package *, char **);
void		cmd_set(t_server *, t_package *, char **);
void		cmd_incant(t_server *, t_package *, char **);

void		action_forward(t_server *server, t_command *cmd);
void		action_right(t_server *server, t_command *cmd);
void		action_left(t_server *server, t_command *cmd);
void		action_look(t_server *server, t_command *cmd);
void		action_inventory(t_server *server, t_command *cmd);
void		action_broadcast(t_server *server, t_command *cmd);
/* void		action_connect(t_server *server, t_command *cmd); */
void		action_fork(t_server *server, t_command *cmd);
void		action_eject(t_server *server, t_command *cmd);
void		action_take(t_server *server, t_command *cmd);
void		action_set(t_server *server, t_command *cmd);
void		action_incant(t_server *server, t_command *cmd);

/**
 * GRAPHIC cmd
 */
extern const t_cmd g_graphic_cmd[];

// map size
void		cmd_msz(t_server *, t_package *, char **);
// case content
void		cmd_bct(t_server *, t_package *, char **);
// map content
void		cmd_mct(t_server *, t_package *, char **);
// team names
void		cmd_tna(t_server *, t_package *, char **);
// player position
void		cmd_ppo(t_server *, t_package *, char **);
// player level
void		cmd_plv(t_server *, t_package *, char **);
// player inventory
void		cmd_pin(t_server *, t_package *, char **);
// current frequency
void		cmd_sgt(t_server *, t_package *, char **);
// set frequency
void		cmd_sst(t_server *, t_package *, char **);

/**
 * helper function
 */
int		nb_player_team(t_vector *players, int team_id);
t_player	*find_player(t_vector *players, int id);

#endif /* !CMD_H_ */
