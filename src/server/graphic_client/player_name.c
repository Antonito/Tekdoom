/*
** player_name.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 19 19:33:25 2016 Antoine Baché
** Last update Thu Jan 21 13:58:43 2016 Antoine Baché
*/

#include "tekdoom.h"

void			player_name_global(t_data *data)
{
  int			i;
  t_bunny_position	pos;

  i = 0;
  pos.x = 404;
  pos.y = 5;
  while (i < MAX_PLAYER)
    {
      player_name_disp(data->pix, data->win, &pos, data->player[i].name);
      pos.y += 80;
      ++i;
    }
}

void			player_name_disp(t_bunny_pixelarray	*pix,
					 t_bunny_window		*win,
					 t_bunny_position	*pos,
					 char			*pseudo)
{
  t_bunny_pixelarray	*name;
  t_bunny_position	shift;

  if ((name = bunny_new_pixelarray(696, 79)) == NULL)
    return ;
  shift.x = 340;
  shift.y = 13;
  transparency_letter(pix, name, pos);
  write_text(name, pseudo, &shift);
  bunny_blit(&(win->buffer), &(name->clipable), pos);
  bunny_delete_clipable(&name->clipable);
}
