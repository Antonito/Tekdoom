/*
** cursor.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan 16 23:46:15 2016 Antoine Baché
** Last update Tue Jan 26 11:44:00 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void		draw_cursor(t_bunny_position *pos, t_bunny_window *win)
{
  int			i;
  t_bunny_pixelarray	*cursor;
  t_color		*color;

  if ((cursor = bunny_new_pixelarray(1, 35)) == NULL)
    return ;
  i = -1;
  color = cursor->pixels;
  while (++i < 34)
    color[i].full = 0x000000;
  color[i].full = 0x000000;
  bunny_blit(&win->buffer, &cursor->clipable, pos);
  bunny_delete_clipable(&cursor->clipable);
}

void		clear_cursor(t_bunny_position *pos, t_bunny_window *win)
{
  int			i;
  t_bunny_pixelarray	*cursor;
  t_color		*color;

  if ((cursor = bunny_new_pixelarray(1, 35)) == NULL)
    return ;
  i = -1;
  color = cursor->pixels;
  while (++i < 34)
    color[i].full = 0xE3F6FD;
  color[i].full = 0x000000;
  bunny_blit(&win->buffer, &cursor->clipable, pos);
  bunny_delete_clipable(&cursor->clipable);
}

void	cursor(t_data *data)
{
  if (data->cursor_toggle >= 0 && data->cursor_toggle <= 30 &&
      data->area == TEXTBOX)
    draw_cursor(&data->cursor_pos, data->win);
  else if (data->cursor_toggle == 60)
    {
      clear_cursor(&data->cursor_pos, data->win);
      data->cursor_toggle = 0;
    }
  else
    clear_cursor(&data->cursor_pos, data->win);
}
