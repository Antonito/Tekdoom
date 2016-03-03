/*
** life.c for Tekdoom in /gfx_tekdoom/src/tekdoom/game/interface
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 14:26:56 2016 Antoine Baché
** Last update Sat Feb 20 22:05:57 2016 Antoine Baché
*/

#include "tekdoom.h"

void		semi_parall(t_bunny_pixelarray *array, unsigned int fir_color)
{
  int		i;
  int		j;
  float		count;
  int		width;
  int		height;
  int		border[2];

  width = array->clipable.clip_width;
  count = (height = array->clipable.clip_height) / 2;
  j = 0;
  while (++j < height  && (i = -1) && (count -= 0.5))
    while (++i < width)
      {
	border[0] = (width - (height - count + (j > 40) * 170) - 15);
	border[1] = (width - (height - count + (j > 30) * 170) - 15) + 1;
	if (i <= (width - (height - count + (j > 40) * 170))
	    && ((j < 12 || j > 48) || i > 15) && (i < 25 || i > 32)
	    && (i >= border[1] || i <= border[1] - 3 || j >= 48 || j < 12)
	    && (j != 31 || i > *border || i < (width - height + count - 185))
	    && (j != 12 || i > *border || i < 80)
	    && (j != 48 || i > *border || i < 80)
	    && (j < 12 || (i != 80 && i != 81) || j > 48))
	  ((t_color *)array->pixels)[ j * width + i].full = fir_color;
      }
}

void			draw_life(double percent, t_bunny_pixelarray *to)
{
  int			j;
  int			i;
  t_color		*pixels;

  j = 13;
  pixels = to->pixels;
  while (j < 48)
  {
    i = 81;
    while (pixels[j * to->clipable.clip_width + ++i].argb[0] &&
	   ((float)(i - 81) / 323.0 * 100) < percent - (float)j / 6.5)
      {
	if (((float)(i - 81) / 316.0 * 100) < 5)
	  pixels[j * to->clipable.clip_width + i].argb[0] = 255 +
	    (pixels[j * to->clipable.clip_width + i].argb[1] = 0);
	else if (((float)(i - 81) / 316.0 * 100) > 75)
	  pixels[j * to->clipable.clip_width + i].argb[1] = 255 +
	    (pixels[j * to->clipable.clip_width + i].argb[0] = 0);
	else
	  pixels[j * to->clipable.clip_width + i].argb[0] =
	    255 - ((float)(i - 97) / 224.0) * 255 + 0 *
	    (pixels[j * to->clipable.clip_width + i].argb[1] =
	     ((float)(i - 97) / 224.0) * 255);
	pixels[j * to->clipable.clip_width + i].argb[2] = 0;
      }
    ++j;
  }
}

void			semi_blit(t_bunny_pixelarray *to,
				  t_bunny_pixelarray *from, float alpha)
{
  t_color		*pixels;
  t_color		*blood;
  int			i;

  pixels = to->pixels;
  blood = from->pixels;
  i = -1;
  if (alpha > 1 || alpha < 0)
    return ;
  while (++i < to->clipable.clip_width * to->clipable.clip_height)
  {
    pixels[i].argb[0] = (1 - alpha) * pixels[i].argb[0] +
      alpha * blood[i].argb[0];
    pixels[i].argb[1] = (1 - alpha) * pixels[i].argb[1] +
      alpha * blood[i].argb[1];
    pixels[i].argb[2] = (1 - alpha) * pixels[i].argb[2] +
      alpha * blood[i].argb[2];
  }
}

void			display_life(t_data *data)
{
  t_bunny_position	origin;
  static unsigned int	blur = 0;
  static double		life = 100;

  /* if (!(rand() % 50)) */
  /*   data->player->life += (data->player->life > 70) ? -30 : (-rand() % 15); */
  if (life < data->player[0].life && life < 0)
    life = data->player[0].life;
  if (life > data->player[0].life)
    life -= 0.4;
  if (life < data->player[0].life)
    life += 0.4;
  coloring(data->interface.life, 0x00000000);
  semi_parall(data->interface.life, 0xD080808c);
  draw_life(life, data->interface.life);
  origin.x = 50;
  origin.y = 21;
  if (++blur > 4194302)
    blur = 0;
  if (life < 50)
    semi_blit(data->pix, data->blur,
	      (1 - ((float)life - cos((float)blur / 6.0) * 4) / 50.0) * 0.7);
  transp_blit(data->pix, data->interface.life, origin);
}
