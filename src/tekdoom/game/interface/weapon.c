/*
** weapon.c for Tekdoom in /gfx_tekdoom/src/tekdoom/game/interface
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 14:52:59 2016 Antoine Baché
** Last update Wed Jan 27 06:17:37 2016 Antoine Baché
*/

#include "tekdoom.h"

int		unset_weapon(t_player *player)
{
  player->knife.is_selected = 0;
  player->gun.is_selected = 0;
  player->rifle.is_selected = 0;
  return (1);
}

void		mean(t_color *to, t_color fr)
{
  to->argb[0] = (float)to->argb[0] * (float)(255 - fr.argb[3]) / 255.0 +
    (float)fr.argb[0] * (float)fr.argb[3] / 255.0;
  to->argb[1] = (float)to->argb[1] * (float)(255 - fr.argb[3]) / 255.0 +
    (float)fr.argb[1] * (float)fr.argb[3] / 255.0;
  to->argb[2] = (float)to->argb[2] * (float)(255 - fr.argb[3]) / 255.0 +
    (float)fr.argb[2] * (float)fr.argb[3] / 255.0;
  to->argb[3] = MAX(fr.argb[3], to->argb[3]);
}

void		transp_blit(t_bunny_pixelarray *to,
			    t_bunny_pixelarray *from, t_bunny_position pos)
{
  int		x;
  int		y;
  t_color	*pixs;

  y = 0;
  pixs = from->pixels;
  while (y < from->clipable.clip_height)
    {
      x = 0;
      while (x < from->clipable.clip_width)
	{
	  if ((y + pos.y) >= 0 && (y + pos.y) < to->clipable.clip_height
	      && (x + pos.x) >= 0 && (x + pos.x) < to->clipable.clip_width)
	    mean((t_color *)to->pixels + (y + pos.y) * to->clipable.clip_width
		 + x + pos.x, pixs[y * from->clipable.clip_width + x]);
	  ++x;
	}
      ++y;
    }
}

int			disp_munitions(t_data *data, int nb, int pos)
{
  char			*no;
  t_bunny_position	*position;

  position = malloc(sizeof(t_bunny_position));
  position->x = 30 - 10 * pos;
  position->y = 40;
  no = my_strdup(".");
  *no = nb % 10 + '0';
  write_text_lower(data->pix, no, position, false);
  free(position);
  free(no);
  return ((nb / 10) ? disp_munitions(data, nb / 10, pos + 1) : 1);
}

void			display_weapon(t_data *data)
{
  t_bunny_position	origin;
  static int		pos = 0;
  static int		dir = 1;

  pos += dir;
  if (pos < 0)
    dir = 1;
  origin.x = 0;
  origin.y = 10 + 10 * cos((float)pos / 10.0);
  if (sin(((float)pos / 36.0)) == 1.0)
    dir = -dir;
  if (data->player[0].knife.is_selected && disp_munitions(data, -1, 0))
    transp_blit(data->pix, data->event.bits.shot ? data->player[0].knife.shot :
		data->player[0].knife.texture, origin);
  else if (data->player[0].rifle.is_selected &&
	   disp_munitions(data, data->player->rifle.remaining, 0))
    transp_blit(data->pix, data->event.bits.shot ? data->player[0].rifle.shot :
		data->player[0].rifle.texture, origin);
  else if (disp_munitions(data, data->player->gun.remaining, 0))
    transp_blit(data->pix, data->event.bits.shot ? data->player[0].gun.shot :
		data->player[0].gun.texture, origin);
}
