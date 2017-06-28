/*
** rotation.h for rotation in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 15 22:54:07 2017 David Zeng
** Last update Thu Jun 15 22:54:07 2017 David Zeng
*/

#ifndef ROTATION_H_
# define ROTATION_H_

#include "utils.h"

/**
 * enum that describes a player rotation
 */
typedef enum	e_rotation
  {
    UP = 1,
    RIGHT,
    DOWN,
    LEFT,
  }		t_rotation;

/**
 * turn current rotation to corresponding direction
 */
t_rotation	turn(t_rotation current, t_rotation direction);

/**
 * get front cell, pos[0] -> next row, pos[1] next cell on the row
 */
void		get_front_dir(t_rotation rot, t_pos *pos);

/**
 * -> -> : from = left,  player = left -> DOWN
 * direction that it comes from for the player
 */
t_rotation	related_dir(t_rotation from, t_rotation player);

#endif /* !ROTATION_H_ */
