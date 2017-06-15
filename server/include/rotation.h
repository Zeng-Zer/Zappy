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

/**
 * enum that describes a player rotation
 */
typedef enum	e_rotation
  {
    RIGHT,
    LEFT,
    UP,
    DOWN,
  }		t_rotation;

/**
 * turn current rotation to corresponding direction
 */
t_rotation turn(t_rotation current, t_rotation direction);

#endif /* !ROTATION_H_ */
