/*
** player_tab.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan 16 22:08:31 2016 Antoine Baché
** Last update Sat Jan 23 23:55:48 2016 Antoine Baché
*/

#include "tekdoom.h"

void		player_tab_lines(t_bunny_pixelarray *pix)
{
  int		i;
  int		j;
  t_color	*colors;

  i = 404;
  colors = pix->pixels;
  while (++i < 1275)
    {
      colors[WIN_X * 5 + i].full = 0x000000;
      colors[WIN_X * 85 + i].full = 0x000000;
      colors[WIN_X * 165 + i].full = 0x000000;
      colors[WIN_X * 245 + i].full = 0x000000;
      colors[WIN_X * 325 + i].full = 0x000000;
      colors[WIN_X * 405 + i].full = 0x000000;
      colors[WIN_X * 485 + i].full = 0x000000;
      colors[WIN_X * 565 + i].full = 0x000000;
      colors[WIN_X * 645 + i].full = 0x000000;
    }
  j = 4;
  while (++j < 645)
    {
      colors[WIN_X * j + 404].full = 0x000000;
      colors[WIN_X * j + 1275].full = 0x000000;
      colors[WIN_X * j + 1100].full = 0x000000;
    }
}

void	player_tab_background(t_bunny_pixelarray *pix)
{
  int		j;
  int		i;
  t_color	*colors;

  colors = pix->pixels;
  j = 4;
  while (++j < 645 && (i = 404))
    {
      while (++i < 1275)
	colors[j * WIN_X + i].full = 0xE3F6FD;
    }
}
