/*
** tekdoom.h for Tekdoom in /gfx_tekdoom/src/tekdoom
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 00:44:34 2016 Antoine Baché
** Last update Wed Jan 27 06:46:40 2016 Luka Boulagnon
*/

#include "tekdoom.h"

t_bunny_response	main_loop(void *param)
{
  t_params		*params;
  t_bunny_response	code;

  params = param;
  if (params->current)
    code = params->current(params, LOOP);
  else
    code = menu(params, LOOP);
  bunny_display(params->window);
  return (code);
}

t_bunny_response	main_click(t_bunny_event_state state,
				   t_bunny_mousebutton button, void *param)
{
  t_click		click;
  t_params		*params;

  params = param;
  click.state = state;
  click.button = button;
  click.params = params;
  params->cur_pos = *bunny_get_mouse_position();
  params->current(&click, CLICK);
  return (GO_ON);
}

t_bunny_response	main_move(UNUSED const t_bunny_position *relative,
				  void *param)
{
  t_params		*params;

  params = param;
  params->cur_pos = *bunny_get_mouse_position();
  params->current(param, HOVER);
  return (GO_ON);
}

t_bunny_response	main_key(t_bunny_event_state state,
				 t_bunny_keysym key, void *param)
{
  t_key			k;
  t_params		*params;

  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  params = param;
  k.state = state;
  k.key = key;
  k.params = params;
  params->current(&k, KEY);
  return (GO_ON);
}

int		tekdoom(void)
{
  t_params	param;

  set_max_heap_size(200);
  init_params(&param);
  init_game(param.data);
  param.cur_pos = *bunny_get_mouse_position();
  bunny_set_move_response(&main_move);
  bunny_set_click_response(&main_click);
  bunny_set_key_response(&main_key);
  bunny_set_loop_main_function(&main_loop);
  bunny_loop(param.window, 25, &param);
  bunny_stop(param.window);
  return (0);
}
