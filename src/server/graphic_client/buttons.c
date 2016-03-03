/*
** buttons.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan 16 21:57:36 2016 Antoine Baché
** Last update Wed Jan 27 06:15:29 2016 Antoine Baché
*/

#include "tekdoom.h"

void			left_button_text(t_bunny_pixelarray *pix,
					 t_bunny_window *win)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	pos;
  t_bunny_position	shift;

  if ((letter = bunny_new_pixelarray(200, 34)) == NULL)
    return ;
  pos.x = 520;
  pos.y = 681;
  shift.x = -58;
  shift.y = 6;
  transparency_letter(pix, letter, &pos);
  write_text_lower(letter, "Start Game", &shift, true);
  bunny_blit(&(win->buffer), &(letter->clipable), &pos);
  bunny_delete_clipable(&letter->clipable);
}

void			right_button_text(t_bunny_pixelarray *pix,
					  t_bunny_window *win)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	pos;
  t_bunny_position	shift;

  if ((letter = bunny_new_pixelarray(200, 34)) == NULL)
    return ;
  pos.x = 980;
  pos.y = 681;
  shift.x = -92;
  shift.y = 6;
  transparency_letter(pix, letter, &pos);
  write_text_lower(letter, "Exit", &shift, true);
  bunny_blit(&(win->buffer), &(letter->clipable), &pos);
  bunny_delete_clipable(&letter->clipable);
}

void		left_button(t_bunny_pixelarray *pix)
{
  int		j;
  int		i;
  t_color	*colors;

  colors = pix->pixels;
  j = 679;
  while (++j < 715 && (i = 519))
    {
      while (++i < 720)
	colors[j * WIN_X + i].full = 0xE3F6FD;
    }
  i = 519;
  while (++i < 720)
    {
      colors[680 * WIN_X + i].full = 0x000000;
      colors[715 * WIN_X + i].full = 0x000000;
    }
  i = 679;
  while (++i < 715)
    {
      colors[i * WIN_X + 519].full = 0x000000;
      colors[i * WIN_X + 720].full = 0x000000;
    }
}

void		right_button(t_bunny_pixelarray *pix)
{
  int		j;
  int		i;
  t_color	*colors;

  colors = pix->pixels;
  j = 679;
  while (++j < 715 && (i = 979))
    {
      while (++i < 1180)
	colors[j * WIN_X + i].full = 0xE3F6FD;
    }
  i = 979;
  while (++i < 1180)
    {
      colors[680 * WIN_X + i].full = 0x000000;
      colors[715 * WIN_X + i].full = 0x000000;
    }
  i = 679;
  while (++i < 715)
    {
      colors[i * WIN_X + 979].full = 0x000000;
      colors[i * WIN_X + 1180].full = 0x000000;
    }
}
