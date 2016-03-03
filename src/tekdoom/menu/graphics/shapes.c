/*
** shapes.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/graphics
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Sun Dec 27 20:26:57 2015 Luka Boulagnon
** Last update Tue Jan 26 17:28:15 2016 Luka Boulagnon
*/

#include "tekdoom.h"

double		dec_part(double nb)
{
  while (nb >= 1)
    --nb;
  while (nb < 0)
    ++nb;
  return (nb);
}

void		parall(t_bunny_pixelarray *array, unsigned int fir_color)
{
  int		i;
  int		j;
  float		count;
  int		width;
  int		height;
  t_color	*pixel;

  width = array->clipable.clip_width;
  count = (height = array->clipable.clip_height - 10) / 2;
  j = 10;
  while (++j < height)
  {
    i = -1;
    count -= 0.3;
    while (++i < width)
    {
      pixel = ((t_color *)array->pixels) + j * width + i;
      if (i == ((int)count + 1))
	set_pix_clr(pixel, 0xFFFFFF, 1.0 - dec_part(count));
      else if (i == (width - (height - (int)count)))
	set_pix_clr(pixel, 0xFFFFFF, dec_part(count));
      else if (i <= (width - (height - count)) && i > count)
	set_pix_clr(pixel, fir_color, 1.0);
    }
  }
}

void	coloring(t_bunny_pixelarray *array, unsigned int color)
{
  int	i;

  i = array->clipable.clip_width;
  i *= array->clipable.clip_height;
  while (--i >= 0)
    ((t_color *)array->pixels)[i].full = color;
}

void			draw(t_texture *image, t_bunny_pixelarray *to,
			     t_bunny_position pos)
{
  t_color		*pixels;
  int			i;
  int			j;

  i = 0;
  pixels = to->pixels;
  while (i < image->height && i < to->clipable.clip_height)
    {
      j = 0;
      while (j < image->width && (j + pos.y) < to->clipable.clip_width)
	{
	  if (pos.y + i > 0)
	    mean_color(pixels + (pos.y + i) * to->clipable.clip_width
		       + pos.x + j, image->pixels[i * image->width + j],
		       (float)(255
			       - image->pixels[i * image->width + j].argb[3])
		       / 255.0);
	  ++j;
	}
      ++i;
    }
}
