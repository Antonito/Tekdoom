/*
** glitch.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/menu
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Dec 27 19:29:24 2015 Luka Boulagnon
** Last update Mon Jan 25 05:29:05 2016 Antoine Baché
*/

#include "tekdoom.h"

void			glitch_line(t_bunny_pixelarray *glitched,
				    t_bunny_pixelarray *image,
				    int *rdm, int width)
{
  width = image->clipable.clip_width;
  rdm[3] = rand() % 10 - 5;
  rdm[4] -= width - rdm[0];
  while (++rdm[4] < (width - rdm[3]))
    {
      ((t_color *)glitched->pixels)[rdm[5] * width + rdm[4]].full =
	(((t_color *)image->pixels)[rdm[5] * width + rdm[4] + rdm[3]].full);
    }
}

void			glitch_colors(t_bunny_pixelarray *glitched,
				      t_bunny_pixelarray *image,
				      int *rdm, int width)
{
  t_color	*pixels_img;
  t_color	*pixels_glitch;

  pixels_img = image->pixels;
  pixels_glitch = glitched->pixels;
  pixels_glitch[(rdm[5] - rdm[1]) * width + rdm[4]].argb[0] =
    (pixels_img[rdm[5] * width + rdm[4] + rdm[0] + rdm[3]].argb[0]);
  pixels_glitch[(rdm[5] + rdm[2]) * width + rdm[4]].argb[2] =
    (pixels_img[rdm[5] * width + rdm[4] - rdm[0] - rdm[3]].argb[2]);
}

t_bunny_pixelarray	*glitch(t_bunny_pixelarray *image)
{
  int			height;
  int			width;
  int			rdm[6];
  t_bunny_pixelarray	*glitched;

  rdm[0] = rand() % 8;
  rdm[1] = rand() % 4 - (rdm[5] = 2);
  rdm[2] = rand() % 4 - 2;
  width = image->clipable.clip_width;
  height = image->clipable.clip_height;
  glitched = copy(image);
  while (++rdm[5] < (height - 2))
    {
      rdm[3] = rand() % (rdm[4] = 6) - 3;
      while (++rdm[4] < (width - rdm[1] - rdm[3]))
	glitch_colors(glitched, image, rdm, width);
      if (rand() % 20 == 0)
	glitch_line(glitched, image, rdm, width);
    }
  return (glitched);
}
