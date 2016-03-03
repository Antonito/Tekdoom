/*
** print_letter.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:59:00 2016 Antoine Baché
** Last update Wed Jan 27 08:18:50 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void			blit_letter(t_bunny_pixelarray *pix,
				    t_bunny_pixelarray *letter,
				    t_bunny_position *pos)
{
  int			i;
  t_color		*color_pix;
  t_color		*color_letter;

  color_pix = pix->pixels;
  color_letter = letter->pixels;
  while (pos->y < 34 && (i = pos->x - 1))
    {
      while (++i < 20)
	color_pix[pos->y * WIN_X + i].full =
	  color_letter[pos->y * 20 + i].full;
    }
}

int			print_game_letter(t_data *data, char *letter)
{
  t_bunny_pixelarray	*letter_pix;
  t_bunny_position	shift;
  t_bunny_position	pos;

  clear_cursor(&data->cursor_pos, data->win);
  data->cursor_pos.x += 10;
  if ((letter_pix = bunny_new_pixelarray(20, 34)) == NULL)
    return (1);
  pos.x = 1 + (data->message.indice - 1) * 10;
  pos.y = 260;
  shift.x = 0;
  shift.y = 9;
  write_text_lower(letter_pix, letter, &shift, true);
  pos.y = 686;
  bunny_blit(&data->win->buffer, &letter_pix->clipable, &pos);
  bunny_delete_clipable(&letter_pix->clipable);
  return (0);
}
