/*
** cursor.c for Tekdoom in /gfx_tekdoom/src/tekdoom/game/interface
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 26 05:13:46 2016 Antoine Baché
** Last update Tue Jan 26 11:44:56 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void	display_cursor(t_data *data)
{
  if (data->cursor_toggle >= 0 && data->cursor_toggle <= 30)
    draw_cursor(&data->cursor_pos, data->win);
  else if (data->cursor_toggle == 60)
    {
      clear_cursor(&data->cursor_pos, data->win);
      data->cursor_toggle = 0;
    }
  else
    clear_cursor(&data->cursor_pos, data->win);
}
