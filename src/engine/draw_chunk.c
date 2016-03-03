/*
** draw_chunk.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Sun Jan 17 15:22:48 2016 Ludovic Petrenko
** Last update Wed Jan 27 06:59:33 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void	draw_chunk(t_bunny_pixelarray *pix,
		   t_object *object,
		   double *zbuf)
{
  int	i;

  i = 0;
  while (i < object->nb_polygons)
    {
      draw_polygon(pix, object->polygons + i, zbuf);
      i++;
    }
}
