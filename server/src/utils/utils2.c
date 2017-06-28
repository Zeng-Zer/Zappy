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

char		*first_word(char *str)
{
  char		*word;
  char		*sep;

  sep = index(str, ' ');
  if (!(word = strndup(str, sep - str)))
    return (NULL);
  return (word);
}
