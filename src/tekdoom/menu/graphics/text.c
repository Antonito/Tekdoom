/*
** text.c for wolf in /gfx_tekdoom/src/tekdoom/graphics
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Dec 27 20:45:15 2015 Luka Boulagnon
** Last update Tue Jan 26 18:12:26 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void			write_text_lower(t_bunny_pixelarray *to, char *text,
					 t_bunny_position *origin, bool i)
{
  t_texture		*texture;
  char			*address;

  if (i == false)
    origin->x -= to->clipable.clip_width;
  else
    origin->x -= my_strlen(text) * 10;
  address = my_strdup("assets/imgs/text_chat/A.bmp");
  while (*text)
    {
      address[22] = *text;
      if (*text == '/')
	address[22] = '$';
      else if (*text == '.')
	address[22] = '`';
      texture = load_image(address, 0);
      if (!texture)
	break;
      origin->x += texture->width;
      draw(texture, to, *origin);
      free(texture->pixels);
      free(texture);
      ++text;
    }
  free(address);
}

void			write_text(t_bunny_pixelarray *to, char *text,
				   t_bunny_position *origin)
{
  t_texture		*texture;
  char			*address;

  origin->x -= my_strlen(text) * 10;
  address = my_strdup("assets/imgs/text/A.bmp");
  while (*text)
    {
      address[17] = *text;
      if (*text == '/')
	address[17] = '$';
      else if (*text == '.')
	address[17] = '`';
      texture = load_image(address, 0);
      if (!texture)
	break;
      origin->x += texture->width;
      draw(texture, to, *origin);
      free(texture->pixels);
      free(texture);
      ++text;
    }
  free(address);
}
