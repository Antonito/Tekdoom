/*
** connect.c for tekdoom in /home/asphahyre/rendu/tekdoom_dev/src/tekdoom/tchat
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Fri Jan 22 10:04:55 2016 Luka Boulagnon
** Last update Wed Jan 27 03:23:36 2016 Luka Boulagnon
*/

#include "tekdoom.h"

t_bunny_response	innme_click(void *param)
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
	{
	  params->current = element->action;
	  break;
	}
      element = element->next;
    }
  key.key = BKS_ESCAPE;
  key.state = GO_DOWN;
  key.params = params;
  params->current(&key, KEY);
  return (GO_ON);
}

t_bunny_response	innme_mouse(void *params)
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

t_bunny_response	innme_connect(void *param)
{
  t_params		*params;

  params = param;
  coloring(params->background, 0x322B00);
  bunny_blit(&params->window->buffer,
	     &params->background->clipable, &params->origin);
  params->connect_buttons->next->next->hover = 0;
  disp_elems(params, params->connect_buttons);
  return (GO_ON);
}

t_bunny_response	innme_text(void *param)
{
  t_key			*key;
  t_msg			*msg;
  static mousetab	array;
  static int		unsetted = 1;

  key = param;
  msg = &key->params->data->message;
  if (unsetted == 1)
    set(&array, &unsetted, key->params->connect_buttons->next->next);
  set_inme_text(key, msg, &unsetted);
  if (key->state == GO_DOWN && key->key != BKS_RETURN
      && key->key != BKS_UNKNOWN && key->key != BKS_ESCAPE)
    array[key->key](key->params->data);
  free(key->params->connect_buttons->next->next->text);
  if ((key->params->connect_buttons->next->next->text =
       malloc(my_strlen(msg->msg) + 1)) == NULL)
    return (EXIT_ON_ERROR);
  my_bzero(key->params->connect_buttons->next->next->text,
	   my_strlen(msg->msg) + 1);
  my_strcpy(key->params->connect_buttons->next->next->text, msg->msg);
  if (key->state == GO_DOWN && key->key == BKS_RETURN)
    key->params->current = &connecting;
  else if (key->key == BKS_ESCAPE)
    key->params->current = &connect_srv;
  return (GO_ON);
}

t_bunny_response	input_pseudo(void *params, int type)
{
  if (type == LOOP)
    return (innme_connect(params));
  if (type == KEY)
    return (innme_text(params));
  if (type == HOVER)
    return (innme_mouse(params));
  if (type == CLICK)
    return (innme_click(params));
  return (GO_ON);
}
