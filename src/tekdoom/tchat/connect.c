/*
** connect.c for tekdoom in /home/asphahyre/rendu/tekdoom_dev/src/tekdoom/tchat
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Fri Jan 22 10:04:55 2016 Luka Boulagnon
** Last update Wed Jan 27 03:18:39 2016 Luka Boulagnon
*/

#include "tekdoom.h"

t_bunny_response	panel_click(void *param)
{
  t_click		*click;
  t_lst			*element;
  t_params		*params;
  t_key			key;

  click = param;
  if (click->state == GO_DOWN)
    return (GO_ON);
  params = click->params;
  element = params->connect_buttons;
  while (element)
    {
      if (element->hover && element->action)
	params->current = element->action;
      element = element->next;
    }
  key.key = BKS_BACKSPACE;
  key.state = GO_DOWN;
  key.params = params;
  params->current(&key, KEY);
  return (GO_ON);
}

t_bunny_response	panel_mouse(void *params)
{
  t_lst		*elem;
  t_params	*par;
  int		is;

  par = params;
  elem = par->connect_buttons;
  while (elem && !(is = 0))
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

t_bunny_response	panel_connect(void *param)
{
  t_params		*params;

  params = param;
  coloring(params->background, 0x322B00);
  bunny_blit(&params->window->buffer,
	     &params->background->clipable, &params->origin);
  disp_elems(params, params->connect_buttons);
  return (GO_ON);
}

t_bunny_response	panel_text(UNUSED void *param)
{
  return (GO_ON);
}

t_bunny_response	connect_srv(void *params, int type)
{
  if (type == LOOP)
    return (panel_connect(params));
  if (type == KEY)
    return (panel_text(params));
  if (type == HOVER)
    return (panel_mouse(params));
  if (type == CLICK)
    return (panel_click(params));
  return (GO_ON);
}
