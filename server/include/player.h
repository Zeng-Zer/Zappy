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

# include "stones.h"
# include "utils.h"

/**
 * structure that represents a player
 */
typedef struct	s_player
{
  int		team;
  // level of the player always >= 1
  int		level;
  // number of stones in the inventory for each type use t_stones enum as index
  int		stones[STONES_SIZE];
  // life unit that represent the time the player can live
  int		food;
  // position in the map
  t_pos		pos;
}		t_player;

#endif /* !PLAYER_H_ */
