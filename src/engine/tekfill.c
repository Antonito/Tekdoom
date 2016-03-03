/*
** tekfill.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Sun Jan 17 14:49:13 2016 Ludovic Petrenko
** Last update Wed Jan 27 08:21:57 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void		tekfill(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int	*pixels;
  int		i;
  int		size;

  pixels = (unsigned int*)pix->pixels;
  i = 0;
  size = pix->clipable.clip_width * pix->clipable.clip_height;
  while (i < size)
    {
      pixels[i] = color;
      i++;
    }
}
