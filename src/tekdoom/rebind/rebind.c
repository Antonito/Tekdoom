/*
** connect.c for tekdoom in /home/asphahyre/rendu/tekdoom_dev/src/tekdoom/tchat
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Fri Jan 22 10:04:55 2016 Luka Boulagnon
** Last update Sun Jan 24 22:34:21 2016 Luka Boulagnon
*/

#include "tekdoom.h"

t_bunny_response	rebind_mouse(void *params)
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

t_bunny_response	rebind_disp(void *param)
{
  t_params		*params;

  params = param;
  coloring(params->background, 0x322B00);
  bunny_blit(&params->window->buffer,
	     &params->background->clipable, &params->origin);
  disp_elems(params, params->connect_buttons);
  return (GO_ON);
}

t_bunny_response	rebind_inputs(void *param)
{
  t_key			*key;

  key = param;
  (void)key;
  return (GO_ON);
}

t_bunny_response	rebind(void *params, int type)
{
  if (type == LOOP)
    return (rebind_disp(params));
  if (type == KEY)
    return (rebind_inputs(params));
  return (GO_ON);
}
