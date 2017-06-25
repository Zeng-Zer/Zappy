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

typedef struct	s_command t_command;

typedef void	(*cmd_action)(t_server *server, t_command *cmd);

struct s_command
{
  cmd_action	action;
  long long	timestamp;
  long long	end_time;
  void		*item;
};

typedef void	(*cmd)(t_server *, t_package *, char **, cmd_action);

typedef struct	s_cmd
{
  char const	*key;
  cmd		cmd;
  cmd_action	action;
  int		time;
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

void		cmd_forward(t_server *, t_package *, char **, cmd_action);
void		cmd_right(t_server *, t_package *, char **, cmd_action);
void		cmd_left(t_server *, t_package *, char **, cmd_action);
void		cmd_look(t_server *, t_package *, char **, cmd_action);
void		cmd_inventory(t_server *, t_package *, char **, cmd_action);
void		cmd_broadcast(t_server *, t_package *, char **, cmd_action);
void		cmd_connect(t_server *, t_package *, char **, cmd_action);
void		cmd_fork(t_server *, t_package *, char **, cmd_action);
void		cmd_eject(t_server *, t_package *, char **, cmd_action);
void		cmd_take(t_server *, t_package *, char **, cmd_action);
void		cmd_set(t_server *, t_package *, char **, cmd_action);
void		cmd_incant(t_server *, t_package *, char **, cmd_action);

/**
 * GRAPHIC cmd
 */
extern const t_cmd g_graphic_cmd[];

// map size
void		cmd_msz(t_server *, t_package *, char **, cmd_action);
// case content
void		cmd_bct(t_server *, t_package *, char **, cmd_action);
// map content
void		cmd_mct(t_server *, t_package *, char **, cmd_action);
// team names
void		cmd_tna(t_server *, t_package *, char **, cmd_action);
// player position
void		cmd_ppo(t_server *, t_package *, char **, cmd_action);
// player level
void		cmd_plv(t_server *, t_package *, char **, cmd_action);
// player inventory
void		cmd_pin(t_server *, t_package *, char **, cmd_action);
// current frequency
void		cmd_sgt(t_server *, t_package *, char **, cmd_action);
// set frequency
void		cmd_sst(t_server *, t_package *, char **, cmd_action);

/**
 * helper function
 */
int		nb_player_team(t_vector *players, int team_id);

#endif /* !CMD_H_ */
