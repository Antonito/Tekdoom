/*
** print_letter.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:59:00 2016 Antoine Baché
** Last update Tue Jan 26 11:43:35 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int			print_letter(t_data *data, char *letter)
{
  t_bunny_pixelarray	*letter_pix;
  t_bunny_position	shift;
  t_bunny_position	pos;

  clear_cursor(&data->cursor_pos, data->win);
  data->cursor_pos.x += 10;
  if ((letter_pix = bunny_new_pixelarray(20, 34)) == NULL)
    return (1);
  pos.x = 6 + (data->message.indice - 1) * 10;
  pos.y = 680;
  shift.x = 0;
  shift.y = 7;
  transparency_letter(data->pix, letter_pix, &pos);
  write_text_lower(letter_pix, letter, &shift, true);
  bunny_blit(&data->win->buffer, &letter_pix->clipable, &pos);
  bunny_delete_clipable(&letter_pix->clipable);
  return (0);
}
