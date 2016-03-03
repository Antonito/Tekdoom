/*
** menu.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/menu
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Dec 27 19:26:27 2015 Luka Boulagnon
** Last update Tue Jan 26 23:43:30 2016 Luka Boulagnon
*/

#include "tekdoom.h"

t_bunny_response	menu_mouse(void *params)
{
  t_lst		*elem;
  t_params	*par;
  int		is;

  par = params;
  elem = par->menu_buttons;
  while (elem && par->current == &menu && !(is = 0))
    {
      if (elem->hover && (is = 1))
	elem->hover = 0;
      if (par->cur_pos.y > elem->pos.y && par->cur_pos.y < elem->pos.y + 70)
	{
	  if ((elem->hover = 1) && !is && par->sound_toggle)
	    bunny_sound_play(par->menu_sound);
	  bunny_sound_volume(par->menu_sound, par->sound_toggle);
	}
      elem = elem->next;
    }
  return (GO_ON);
}

t_bunny_response	menu_click(void *param)
{
  t_click		*click;
  t_lst			*element;
  t_params		*params;

  click = param;
  if (click->state == GO_DOWN)
    return (GO_ON);
  params = click->params;
  element = params->menu_buttons;
  while (element)
    {
      if (element->hover && element->action)
	params->current = element->action;
      element = element->next;
    }
  return (GO_ON);
}

t_bunny_response	menu(void *param, int menu_type)
{
  t_params		*params;

  if (menu_type == LOOP)
    {
      params = param;
      bunny_sound_volume(params->intro_sound, --params->intro_volume);
      if (!params->intro_volume)
	bunny_sound_stop(params->intro_sound);
      coloring(params->background, 0x322B00);
      bunny_blit(&params->window->buffer,
		 &params->background->clipable, &params->origin);
      disp_elems(params, params->menu_buttons);
      return (params->again);
    }
  if (menu_type == HOVER)
    return (menu_mouse(param));
  if (menu_type == CLICK)
    return (menu_click(param));
  return (GO_ON);
}

t_bunny_response	set_oculus(void *param, UNUSED int menu_type)
{
  t_params		*params;
  t_lst			*elem;
  t_bunny_position	pos;

  params = param;
  params->config.oculus = !params->config.oculus;
  elem = params->menu_buttons;
  pos.x = 220;
  pos.y = 7;
  while (elem->next && elem->action != &set_oculus)
    elem = elem->next;
  if (elem->action == &set_oculus)
    {
      parall(elem->background, 0xE3F6FD);
      elem->text = (params->config.oculus) ? "Oculus: on"
	: "Oculus: off";
      write_text(elem->background, elem->text, &pos);
    }
  params->current = &menu;
  return (GO_ON);
}

t_bunny_response	(*get_action_by_hover(t_lst *menu, t_bunny_response
					      (*func)
					      (void *, int)))(void *, int)
{
  while (menu)
    {
      if (menu->hover)
	return (menu->action);
      menu = menu->next;
    }
  return (func);
}
