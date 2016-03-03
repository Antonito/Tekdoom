/*
** background.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan 16 21:04:34 2016 Antoine Baché
** Last update Sun Jan 24 15:13:11 2016 Lucas Troncy
*/

#include "tekdoom.h"

void		chatbox_set(t_bunny_pixelarray *pix)
{
  int		j;
  int		i;
  t_color	*colors;

  colors = pix->pixels;
  j = 4;
  while (++j < 680 && (i = 4))
    {
      while (++i < 400)
	colors[j * WIN_X + i].full = 0x969483;
    }
  i = 4;
  while (++i < 400)
    {
      colors[5 * WIN_X + i].full = 0x000000;
      colors[680 * WIN_X + i].full = 0x000000;
      colors[715 * WIN_X + i].full = 0x000000;
    }
  i = 5;
  while (++i < 715)
    {
      colors[i * WIN_X + 5].full = 0x000000;
      colors[i * WIN_X + 400].full = 0x000000;
    }
}

void		textbar_set(t_bunny_pixelarray *pix)
{
  int		j;
  int		i;
  t_color	*colors;

  colors = pix->pixels;
  j = 680;
  while (++j < 715 && (i = 5))
    {
      while (++i < 400)
	colors[j * WIN_X + i].full = 0xE3F6FD;
    }
}

void		background_set(t_bunny_pixelarray *pix)
{
  int		i;
  t_color	*colors;

  colors = pix->pixels;
  i = -1;
  while (++i < WIN_X * WIN_Y)
    {
      colors[i].full = 0x322B00;
    }
}

void	pre_interface(t_bunny_pixelarray *pix)
{
  background_set(pix);
  left_button(pix);
  right_button(pix);
  player_tab_background(pix);
  player_tab_lines(pix);
  textbar_set(pix);
  chatbox_set(pix);
}

void	set_interface(t_data *data)
{
  status_global(data);
  player_name_global(data);
  left_button_text(data->pix, data->win);
  right_button_text(data->pix, data->win);
  cursor(data);
  if (data->area == TEXTBOX)
    data->cursor_toggle++;
  else if (!data->cursor_toggle)
    data->cursor_toggle = 0;
}
