/*
** pixels.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/graphics
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Sat Dec 26 12:01:36 2015 Luka Boulagnon
** Last update Sat Dec 26 12:01:53 2015 Luka Boulagnon
*/

#include "tekdoom.h"

t_color		*get_pixel(t_bunny_pixelarray *content, int x, int y)
{
  t_color	*pixels;

  pixels = content->pixels;
  if (x > content->clipable.clip_width ||
      y > content->clipable.clip_height ||
      x < 0 || y < 0)
    return (NULL);
  return (pixels + y * content->clipable.clip_width + x);
}

void		mean_color(t_color *to, t_color with, float crease)
{
  while (crease < 0)
    ++crease;
  while (crease > 1)
    --crease;
  if (with.full && to)
    {
      to->argb[0] = to->argb[0] * crease + (with.argb[0]) * (1 - crease);
      to->argb[1] = to->argb[1] * crease + (with.argb[1]) * (1 - crease);
      to->argb[2] = to->argb[2] * crease + (with.argb[2]) * (1 - crease);
    }
}
