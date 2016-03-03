/*
** transparency.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 19 17:46:15 2016 Antoine Baché
** Last update Sat Jan 23 20:14:14 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void		transparency_letter(t_bunny_pixelarray *pix,
				    t_bunny_pixelarray *letter,
				    t_bunny_position	*pos)
{
  int		i;
  int		j;
  t_color	*foreground;
  t_color	*background;

  i = -1;
  foreground = letter->pixels;
  background = pix->pixels;
  while (++i < letter->clipable.clip_height && (j = -1))
    {
      while (++j < letter->clipable.clip_width)
	foreground[i * letter->clipable.clip_width + j].full =
	  background[(i + pos->y) * WIN_X + (j + pos->x)].full;
    }
}
