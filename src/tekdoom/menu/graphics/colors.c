/*
** colors.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/graphics
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Sun Dec 27 20:36:29 2015 Luka Boulagnon
** Last update Sun Dec 27 20:37:13 2015 Luka Boulagnon
*/

#include "tekdoom.h"

void		opacity(t_bunny_pixelarray *image, unsigned char opacity)
{
  int		size;
  t_color *	pixels;

  size = image->clipable.clip_width * image->clipable.clip_height;
  pixels = image->pixels;
  while (--size >= 0)
  {
    pixels[size].argb[0] *= 1 - ((float)opacity / 255);
    pixels[size].argb[1] *= 1 - ((float)opacity / 255);
    pixels[size].argb[2] *= 1 - ((float)opacity / 255);
  }
}

void		mean_col(t_color *to, t_color with, float crease)
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
