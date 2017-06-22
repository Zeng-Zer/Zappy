/*
** stones.h for stones in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 14 03:25:42 2017 David Zeng
** Last update Wed Jun 14 03:25:42 2017 David Zeng
*/

#ifndef STONE_H_
# define STONE_H_

/**
 * constant for stones
 */
typedef enum	e_stone
  {
    LINEMATE = 0,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    STONES_SIZE,
  }		t_stone;

/**
 * return an malloc'ed string corresponding to the stone
 */
char		*stone_to_str(t_stone stone);
/**
 * return the stone enum corresponding to the string
 * return STONES_SIZE in case of failure
 */
t_stone		str_to_stone(char *str);

#endif /* !STONE_H_ */
