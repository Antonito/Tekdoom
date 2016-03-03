/*
** rick_roll.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/menu
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Dec 27 19:59:28 2015 Luka Boulagnon
** Last update Wed Jan 27 08:17:01 2016 Luka Boulagnon
*/

#include "tekdoom.h"

t_bunny_response		dont_click_6(void *param, UNUSED int menu_type)
{
  t_params			*params;
  t_lst				*elem;
  t_bunny_position		pos;

  params = param;
  elem = params->menu_buttons;
  pos.x = 220;
  pos.y = 7;
  while (elem->next && elem->action != &dont_click_6)
    elem = elem->next;
  if (elem->action == &dont_click_6)
    {
      parall(elem->background, 0xE3F6FD);
      elem->text = "RICK ROLLED !";
      write_text(elem->background, elem->text, &pos);
      elem->action = &dont_click_6;
    }
  if (++params->curr_opacity > 30)
    {
      params->curr_opacity = 0;
      params->current = &set_rick_roll;
    }
  menu(param, LOOP);
  return (GO_ON);
}

t_bunny_response		dont_click_5(void *param, UNUSED int menu_type)
{
  t_params			*params;
  t_lst				*elem;
  t_bunny_position		pos;

  params = param;
  elem = params->menu_buttons;
  pos.x = 220;
  pos.y = 7;
  while (elem->next && elem->action != &dont_click_5)
    elem = elem->next;
  if (elem->action == &dont_click_5)
    {
      parall(elem->background, 0xE3F6FD);
      elem->text = "you have been...";
      write_text(elem->background, elem->text, &pos);
      elem->action = &dont_click_6;
    }
  if (++params->curr_opacity > 30)
    {
      params->curr_opacity = 5;
      params->current = &dont_click_6;
    }
  menu(param, LOOP);
  return (GO_ON);
}

t_bunny_response		set_fullscreen(void *param, UNUSED int type)
{
  t_params			*params;
  t_bunny_position		pos;

  params = param;
  if ((params->fullscreen = !params->fullscreen))
    params->menu_buttons->next->text[13] = 'n' +
      (params->menu_buttons->next->text[14] = 0);
  else
    params->menu_buttons->next->text[13] =
      (params->menu_buttons->next->text[14] = 'f');
  parall(params->menu_buttons->next->background, 0xE3F6FD);
  pos.x = 220;
  pos.y = 7;
  write_text(params->menu_buttons->next->background,
	     params->menu_buttons->next->text, &pos);
  menu(param, type);
  params->current = &menu;
  return (GO_ON);
}

t_bunny_response		set_rick_roll(void *param, UNUSED int menu_type)
{
  t_params			*params;

  params = param;
  bunny_sound_stop(params->intro_sound);
  bunny_sound_play(params->rick_roll);
  bunny_sound_volume(params->rick_roll, 100);
  params->current = NULL;
  params->n_frame = my_strdup("assets/videos/rick_roll/00000.bmp");
  return (GO_ON);
}
