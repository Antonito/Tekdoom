/*
** interface.c for Tekdoom in /gfx_tekdoom/src/tekdoom/game
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 14:22:02 2016 Antoine Baché
** Last update Wed Jan 27 01:35:23 2016 Antoine Baché
*/

#include "tekdoom.h"

void			display_interface(t_data *data)
{
  display_minimap(data);
  display_weapon(data);
  display_crosshair(data);
  display_life(data);
  if (data->show_chat)
    display_chat(data);
}
