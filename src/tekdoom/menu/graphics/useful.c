/*
** useful.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/graphics
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Sun Dec 27 20:46:24 2015 Luka Boulagnon
** Last update Sun Dec 27 20:46:32 2015 Luka Boulagnon
*/

#include "tekdoom.h"

t_bunny_pixelarray	*copy(t_bunny_pixelarray *orig)
{
  t_bunny_pixelarray	*copy;
  int			len;

  copy = bunny_new_pixelarray(orig->clipable.clip_width,
			       orig->clipable.clip_height);
  len = orig->clipable.clip_width * orig->clipable.clip_height;
  while (--len >= 0)
    ((t_color *)copy->pixels)[len].full =
      ((t_color *)orig->pixels)[len].full;
  return (copy);
}
