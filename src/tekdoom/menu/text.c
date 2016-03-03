/*
** text.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/graphics
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Sun Dec 27 20:45:15 2015 Luka Boulagnon
** Last update Sun Dec 27 21:16:54 2015 Luka Boulagnon
*/

#include "tekdoom.h"

void			write_text(t_bunny_pixelarray *to, char *text)
{
  t_texture		*texture;
  t_bunny_position	origin;
  char			*address;

  origin.x = 220 - my_strlen(text) * 10;
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
