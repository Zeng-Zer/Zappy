/*
** stone.c for stone in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 25 22:23:27 2017 David Zeng
** Last update Sun Jun 25 22:23:27 2017 David Zeng
*/

#include <stdlib.h>
#include <string.h>
#include "stone.h"

char		*stone_to_str(t_stone stone)
{
  if (stone == FOOD)
    return (strdup("food"));
  else if (stone == LINEMATE)
    return (strdup("linemate"));
  else if (stone == DERAUMERE)
    return (strdup("deraumere"));
  else if (stone == SIBUR)
    return (strdup("sibur"));
  else if (stone == MENDIANE)
    return (strdup("mendiane"));
  else if (stone == PHIRAS)
    return (strdup("phiras"));
  else if (stone == THYSTAME)
    return (strdup("thystame"));
  return (NULL);
}

t_stone		str_to_stone(char *str)
{
  if (strcmp("food", str) == 0)
    return (FOOD);
  else if (strcmp("linemate", str) == 0)
    return (LINEMATE);
  else if (strcmp("deraumere", str) == 0)
    return (DERAUMERE);
  else if (strcmp("sibur", str) == 0)
    return (SIBUR);
  else if (strcmp("mendiane", str) == 0)
    return (MENDIANE);
  else if (strcmp("phiras", str) == 0)
    return (PHIRAS);
  else if (strcmp("thystame", str) == 0)
    return (THYSTAME);
  return (STONES_SIZE);
}
