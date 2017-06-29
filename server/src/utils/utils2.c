/*
** utils2.c for utils2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 28 01:30:13 2017 David Zeng
** Last update Wed Jun 28 01:30:13 2017 David Zeng
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

char		*first_word(char *str)
{
  char		*word;
  char		*sep;

  sep = index(str, ' ');
  if (!(word = strndup(str, sep - str)))
    return (NULL);
  return (word);
}

static t_line	fill_t_line(int x0, int y0, int x1, int y1)
{
  t_line	line;

  line.dx = abs(x1 - x0);
  line.sx = x0 < x1 ? 1 : -1;
  line.dy = abs(y1 - y0);
  line.sy = y0 < y1 ? 1 : -1;
  line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
  return (line);
}

void		line(t_pos p0, t_pos p1, t_pos *pos)
{
  t_line	line;
  int		i;

  line = fill_t_line(p0.x, p0.y, p1.x, p1.y);
  i = 0;
  if (p0.x != p1.x || p0.y != p1.y)
    {
      line.e2 = line.err;
      if (line.e2 >-line.dx)
	{
	  line.err -= line.dy;
	  p0.x += line.sx;
	}
      if (line.e2 < line.dy)
	{
	  line.err += line.dx;
	  p0.y += line.sy;
	}
      if (i == 0)
	pos[i++] = p0;
    }
  *pos = p0;
}
