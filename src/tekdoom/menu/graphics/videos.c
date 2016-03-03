/*
** videos.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/graphics
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Dec 27 20:39:59 2015 Luka Boulagnon
** Last update Mon Jan 25 05:33:37 2016 Antoine Baché
*/

#include "tekdoom.h"

void		set_pix_four(t_texture *image,
			     t_bunny_pixelarray *to,
			     t_bunny_position pos,
			     t_bunny_position pix)
{
  t_color	*pixels;

  pixels = to->pixels;
  mean_color(pixels + (pos.y + pix.x * 2) * to->clipable.clip_width
	     + pos.x + pix.y * 2 + 1, image->pixels[pix.x * image->width + pix.y],
	     (float)(255 - image->pixels[pix.x * image->width + pix.y].argb[3])
	     / 255.0);
  mean_color(pixels + (pos.y + pix.x * 2 + 1) * to->clipable.clip_width
	     + pos.x + pix.y * 2 + 1, image->pixels[pix.x * image->width + pix.y],
	     (float)(255 - image->pixels[pix.x * image->width + pix.y].argb[3])
	     / 255.0);
  mean_color(pixels + (pos.y + pix.x * 2) * to->clipable.clip_width
	     + pos.x + pix.y * 2, image->pixels[pix.x * image->width + pix.y],
	     (float)(255 - image->pixels[pix.x * image->width + pix.y].argb[3])
	     / 255.0);
  mean_color(pixels + (pos.y + pix.x * 2 + 1) * to->clipable.clip_width
	     + pos.x + pix.y * 2, image->pixels[pix.x * image->width + pix.y],
	     (float)(255 - image->pixels[pix.x * image->width + pix.y].argb[3])
	     / 255.0);
}

void			draw_video(t_texture *image,
				   t_bunny_pixelarray *to,
				   t_bunny_position pos)
{
  t_bunny_position	pix;

  pix.x = -1;
  while (++pix.x < (image->height - 2))
    {
      pix.y = -1;
      while (++pix.y < (image->width - 2))
	set_pix_four(image, to, pos, pix);
    }
}
