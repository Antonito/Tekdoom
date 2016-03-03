/*
** my_puterr.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Jan 16 20:13:24 2016 Ludovic Petrenko
** Last update Tue Jan 26 11:41:11 2016 Antoine Baché
*/

#include "tekdoom.h"

void	my_puterr(char *s, char *t)
{
  write(2, s, my_strlen(s));
  if (t != NULL)
    write(2, t, my_strlen(t));
}
