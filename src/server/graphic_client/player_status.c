/*
** player_status.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 19 14:08:23 2016 Antoine Baché
** Last update Sun Jan 24 01:21:42 2016 Lucas Troncy
*/

#include "tekdoom.h"

void	status_global(t_data *data)
{
  status1_text_x(data->pix, data->win, ((data->player[0].status) ? 1 : 0));
  status2_text_x(data->pix, data->win, ((data->player[1].status) ? 1 : 0));
  status3_text_x(data->pix, data->win, ((data->player[2].status) ? 1 : 0));
  status4_text_x(data->pix, data->win, ((data->player[3].status) ? 1 : 0));
  status5_text_x(data->pix, data->win, ((data->player[4].status) ? 1 : 0));
  status6_text_x(data->pix, data->win, ((data->player[5].status) ? 1 : 0));
  status7_text_x(data->pix, data->win, ((data->player[6].status) ? 1 : 0));
  status8_text_x(data->pix, data->win, ((data->player[7].status) ? 1 : 0));
}

void			status1_text_x(t_bunny_pixelarray *pix,
				       t_bunny_window *win, int i)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	pos;
  t_bunny_position	shift;

  if ((letter = bunny_new_pixelarray(174, 79)) == NULL)
    return ;
  pos.x = 1101;
  pos.y = 6;
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

void			status2_text_x(t_bunny_pixelarray *pix,
				       t_bunny_window *win, int i)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	pos;
  t_bunny_position	shift;

  if ((letter = bunny_new_pixelarray(174, 79)) == NULL)
    return ;
  pos.x = 1101;
  pos.y = 86;
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

void			status3_text_x(t_bunny_pixelarray *pix,
				       t_bunny_window *win, int i)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	pos;
  t_bunny_position	shift;

  if ((letter = bunny_new_pixelarray(174, 79)) == NULL)
    return ;
  pos.x = 1101;
  pos.y = 166;
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

void			status4_text_x(t_bunny_pixelarray *pix,
				       t_bunny_window *win, int i)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	pos;
  t_bunny_position	shift;

  if ((letter = bunny_new_pixelarray(174, 79)) == NULL)
    return ;
  pos.x = 1101;
  pos.y = 246;
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
