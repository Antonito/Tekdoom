/*
** intro.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/menu
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sat Dec 26 12:13:18 2015 Luka Boulagnon
** Last update Sat Jan 23 20:04:25 2016 Antoine Baché
*/

#include "tekdoom.h"

t_bunny_response		intro(void *param, UNUSED int menu_type)
{
  t_params			*params;

  params = param;
  params->current = &goto_menu;
  return (GO_ON);
}
