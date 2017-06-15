/*
** player.h for player in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 14 03:49:33 2017 David Zeng
** Last update Wed Jun 14 03:49:33 2017 David Zeng
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# include "stone.h"
# include "utils.h"
# include "rotation.h"

/**
 * structure that represents a player
 */
typedef struct	s_player
{
  // id
  int		id;
  // team id
  int		team_id;
  // level always >= 1
  int		level;
  // number of stones in the inventory for each type use t_stones enum as index
  int		stones[STONES_SIZE];
  // life unit that represent the time the player can live
  int		food;
  // position in the map
  t_pos		pos;
  // rotation
  t_rotation	rotation;
}		t_player;

/**
 * create a player in the given team
 * has random position and rotation
 */
t_player	*create_player(int team_id);

#endif /* !PLAYER_H_ */
