/*
** clear_zbuf.c for doom in /home/petren_l/rendu/tek1/semestre_01/doom
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Mon Jan 11 23:25:24 2016 Ludovic Petrenko
** Last update Tue Jan 26 13:26:58 2016 Antoine Baché
*/

#include "tekdoom.h"

void	clear_zbuf(double *zbuf)
{
  int	i;
  int	size;

  i = 0;
  size = WIN_X * WIN_Y;
  while (i < size)
    {
      zbuf[i] = -(ZFAR);
      ++i;
    }
}
