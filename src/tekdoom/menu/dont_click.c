/*
** dont_click.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/menu
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Dec 27 20:06:39 2015 Luka Boulagnon
** Last update Sat Jan 23 19:55:47 2016 Antoine Baché
*/

#include "tekdoom.h"

t_bunny_response		dont_click_4(void *param, int menu_type)
{
  t_params			*params;
  t_lst				*elem;
  t_bunny_position		pos;

  params = param;
  elem = params->menu_buttons;
  pos.x = 220;
  pos.y = 7;
  while (elem->next && elem->action != &dont_click_4)
    elem = elem->next;
  if (elem->action == &dont_click_4)
    {
      parall(elem->background, 0xE3F6FD);
      elem->text = "Okay, then...";
      write_text(elem->background, elem->text, &pos);
      elem->action = &dont_click_5;
    }
  if (++params->curr_opacity > 30)
    {
      params->curr_opacity = 0;
      params->current = &dont_click_5;
    }
  menu(param, menu_type);
  return (GO_ON);
}

t_bunny_response		dont_click_3(void *param, int menu_type)
{
  t_params			*params;
  t_lst				*elem;
  t_bunny_position		pos;

  params = param;
  elem = params->menu_buttons;
  pos.x = 220;
  pos.y = 7;
  while (elem->next && elem->action != &dont_click_3)
    elem = elem->next;
  if (elem->action == &dont_click_3)
    {
      parall(elem->background, 0xE3F6FD);
      elem->text = "I warned you !";
      write_text(elem->background, elem->text, &pos);
      elem->action = dont_click_4;
    }
  menu(param, menu_type);
  return (GO_ON);
}

t_bunny_response		dont_click_2(void *param, UNUSED int menu_type)
{
  t_params			*params;
  t_lst				*elem;
  t_bunny_position		pos;

  params = param;
  elem = params->menu_buttons;
  pos.x = 220;
  pos.y = 7;
  while (elem->next && elem->action != &dont_click_2)
    elem = elem->next;
  if (elem->action == &dont_click_2)
    {
      parall(elem->background, 0xE3F6FD);
      elem->text = "Just try again...";
      write_text(elem->background, elem->text, &pos);
      elem->action = dont_click_3;
    }
  params->current = &menu;
  return (GO_ON);
}

t_bunny_response		dont_click(void *param, UNUSED int menu_type)
{
  t_params			*params;
  t_lst				*elem;
  t_bunny_position		pos;

  params = param;
  elem = params->menu_buttons;
  pos.x = 220;
  pos.y = 7;
  while (elem->next && elem->action != &dont_click)
    elem = elem->next;
  if (elem->action == &dont_click)
    {
      parall(elem->background, 0xE3F6FD);
      elem->text = "I said DON'T";
      write_text(elem->background, elem->text, &pos);
      elem->action = dont_click_2;
    }
  params->current = &menu;
  return (GO_ON);
}
