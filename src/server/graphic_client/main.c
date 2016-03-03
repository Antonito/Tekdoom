/*
** main.c for gfx_colle_fantasy1 in /gfx_colle_fantasy1/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan  6 18:17:40 2016 Antoine Baché
** Last update Wed Jan 27 08:49:13 2016 Antoine Baché
*/

#include "tekdoom.h"

t_bunny_response	client_click(t_bunny_event_state state,
				     t_bunny_mousebutton key, t_data *data)
{
  if (state == GO_DOWN)
    data->mouse_click[key](data);
  return (GO_ON);
}

t_bunny_response	client_key(t_bunny_event_state state,
				   t_bunny_keysym key, t_data *data)
{
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE && !(data->sock.run = 0))
	return (EXIT_ON_SUCCESS);
      else if (data->area == TEXTBOX &&
	       key != BKS_UNKNOWN && key != BKS_LAST_KEY)
	data->keys[key](data);
    }
  return (GO_ON);
}

t_bunny_response	room_loop(t_data *data)
{
  set_interface(data);
  if (data->area == PLAYBUTTON)
    {
      if (start_engine(data))
	return (EXIT_ON_ERROR);
    }
  if (data->area == EXITBUTTON || data->sock.run == 0)
    return (EXIT_ON_SUCCESS);
  if (data->message.rec == true)
    display_chat_msg(data);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response	client_move(UNUSED const t_bunny_position *relative,
				    t_data *data)
{
  data->mouse_pos = (t_bunny_position *)bunny_get_mouse_position();
  return (GO_ON);
}

int		client(t_data *data)
{
  if ((data->mouse_click = get_mousefunction()) == NULL ||
      (data->keys = get_keys1()) == NULL)
    return (1);
  prepare_client(data);
  ginit_socket(data);
  pre_interface(data->pix);
  bunny_blit(&(data->win->buffer), &(data->pix->clipable), 0);
  bunny_set_key_response((t_bunny_key)client_key);
  bunny_set_move_response((t_bunny_move)client_move);
  bunny_set_click_response((t_bunny_click)client_click);
  bunny_set_loop_main_function((t_bunny_loop)room_loop);
  bunny_loop(data->win, 60, data);
  free_login(data->login);
  free_client(data);
  bunny_set_move_response(&main_move);
  bunny_set_click_response(&main_click);
  bunny_set_key_response(&main_key);
  bunny_set_loop_main_function(&main_loop);
  return (0);
}
