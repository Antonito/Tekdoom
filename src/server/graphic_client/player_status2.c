/*
** player_status2.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 19 14:28:56 2016 Antoine Baché
** Last update Thu Jan 21 13:58:56 2016 Antoine Baché
*/

#include "tekdoom.h"

void			status5_text_x(t_bunny_pixelarray *pix,
				       t_bunny_window *win, int i)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	pos;
  t_bunny_position	shift;

  if ((letter = bunny_new_pixelarray(174, 79)) == NULL)
    return ;
  pos.x = 1101;
  pos.y = 326;
  shift.x = 240;
  shift.y = 13;
  transparency_letter(pix, letter, &pos);
  if (i == 0)
    write_text(letter, "X", &shift);
  else
    write_text(letter, "OK", &shift);
  bunny_blit(&(win->buffer), &(letter->clipable), &pos);
  bunny_delete_clipable(&letter->clipable);
}

void			status6_text_x(t_bunny_pixelarray *pix,
				       t_bunny_window *win, int i)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	pos;
  t_bunny_position	shift;

  if ((letter = bunny_new_pixelarray(174, 79)) == NULL)
    return ;
  pos.x = 1101;
  pos.y = 406;
  shift.x = 240;
  shift.y = 13;
  transparency_letter(pix, letter, &pos);
  if (i == 0)
    write_text(letter, "X", &shift);
  else
    write_text(letter, "OK", &shift);
  bunny_blit(&(win->buffer), &(letter->clipable), &pos);
  bunny_delete_clipable(&letter->clipable);
}

void			status7_text_x(t_bunny_pixelarray *pix,
				       t_bunny_window *win, int i)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	pos;
  t_bunny_position	shift;

  if ((letter = bunny_new_pixelarray(174, 79)) == NULL)
    return ;
  pos.x = 1101;
  pos.y = 486;
  shift.x = 240;
  shift.y = 13;
  transparency_letter(pix, letter, &pos);
  if (i == 0)
    write_text(letter, "X", &shift);
  else
    write_text(letter, "OK", &shift);
  bunny_blit(&(win->buffer), &(letter->clipable), &pos);
  bunny_delete_clipable(&letter->clipable);
}

void			status8_text_x(t_bunny_pixelarray *pix,
				       t_bunny_window *win, int i)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	pos;
  t_bunny_position	shift;

  if ((letter = bunny_new_pixelarray(174, 79)) == NULL)
    return ;
  pos.x = 1101;
  pos.y = 566;
  shift.x = 240;
  shift.y = 13;
  transparency_letter(pix, letter, &pos);
  if (i == 0)
    write_text(letter, "X", &shift);
  else
    write_text(letter, "OK", &shift);
  bunny_blit(&(win->buffer), &(letter->clipable), &pos);
  bunny_delete_clipable(&letter->clipable);
}
