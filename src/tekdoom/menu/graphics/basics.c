/*
** basics.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/graphics
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Dec 27 20:07:51 2015 Luka Boulagnon
** Last update Tue Jan 26 23:34:04 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int		set_message(char *message, t_params *params)
{
  params->message = message;
  params->timer = 1;
#ifdef DEBUG
  printf("%s\n", message);
#endif
  return (1);
}

void			set_square(t_bunny_position start,
				   t_bunny_pixelarray *to,
				   int filled, int size)
{
  t_bunny_position	pos;
  t_color		*pixel;
  t_color		color;

  pos.x = 0;
  color.full = 0x756e67;
  while (pos.x <= size)
    {
      pos.y = 0;
      while (pos.y <= size)
	{
	  pixel = to->pixels;
	  mean_col(pixel + (start.y + pos.y) * to->clipable.clip_width
		   + (start.x + pos.x), color,
		   (1 - 0.6 * !filled));
	  ++pos.y;
	}
      ++pos.x;
    }
}

void		blit(t_bunny_buffer *buffer,
		     t_bunny_pixelarray *glitched,
		     t_lst *element,
		     int oculus)
{
  t_bunny_position	pos;

  pos = element->pos;
  if (element->hover)
    pos.x += rand() % 8 - 4;
  if (oculus)
    {
      pos.x -= 1920 / 4 - element->hover * 15;
      bunny_blit(buffer, (element->hover) ? &glitched->clipable :
		 &element->background->clipable, &pos);
      pos.x += 1920 / 2 - element->hover * 30;
    }
  bunny_blit(buffer, (element->hover) ?
	     &glitched->clipable : &element->background->clipable,
	     &pos);
}

void		set_pix_clr(t_color *pixel, unsigned int color, float opacity)
{
  t_color	clr;

  clr.full = color;
  pixel->argb[0] = ((float)(clr.argb[0]) * opacity);
  pixel->argb[1] = ((float)(clr.argb[1]) * opacity);
  pixel->argb[2] = ((float)(clr.argb[2]) * opacity);
}

void			notification(t_bunny_pixelarray *to, char *text)
{
  t_texture		*texture;
  t_bunny_position	origin;
  char			*address;

  origin.x = 960 - (my_strlen(text) + 1) * 10;
  origin.y = 7;
  address = my_strdup("assets/imgs/text/A.bmp");
  while (*text)
    {
      address[17] = *text;
      texture = load_image(address, 0);
      if (!texture)
	break;
      origin.x += texture->width;
      draw(texture, to, origin);
      free(texture->pixels);
      free(texture);
      ++text;
    }
  free(address);
}
