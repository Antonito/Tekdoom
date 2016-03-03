/*
** goto_menu.c for Tekdoom in /gfx_tekdoom/src/tekdoom/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 02:15:32 2016 Antoine Baché
** Last update Sun Jan 24 22:23:52 2016 Luka Boulagnon
*/

#include "tekdoom.h"

t_bunny_response	goto_menu(void *param, UNUSED int menu_type)
{
  t_params		*params;

  params = param;
  bunny_sound_volume(params->loop_sound, 30);
  bunny_set_mouse_visibility(params->window, 1);
  params->current = &menu;
  return (GO_ON);
}
