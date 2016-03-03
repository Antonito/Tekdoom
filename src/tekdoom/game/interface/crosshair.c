/*
** crosshair.c for Tekdoom in /gfx_tekdoom/src/tekdoom/game/interface
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 14:53:54 2016 Antoine Baché
** Last update Tue Jan 26 23:02:37 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void			display_crosshair(t_data *data)
{
  t_bunny_position	pos;

  pos.x = (1280 - data->interface.crosshair->clipable.clip_width) / 2;
  pos.y = (720 - data->interface.crosshair->clipable.clip_height) / 2;
  transp_blit(data->pix, data->interface.crosshair, pos);
}
