/*
** my_strlen.c for Tekdoom in /gfx_tekdoom/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 12 20:47:01 2016 Antoine Baché
** Last update Sun Jan 17 14:52:30 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str != NULL && *str != '\0' && (str++) && (++i));
  return (i);
}
