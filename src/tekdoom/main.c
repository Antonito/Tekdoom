/*
** main.c for Tekdoom in /gfx_tekdoom/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 11 20:37:39 2016 Antoine Baché
** Last update Mon Jan 25 04:19:34 2016 Antoine Baché
*/

#include "tekdoom.h"

t_bunny_response	loop(void *param)
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

t_bunny_response	click(t_bunny_event_state state,
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

t_bunny_response	move(const t_bunny_position *relative, void *param)
{
  t_params		*params;

  (void)relative;
  params = param;
  params->cur_pos = *bunny_get_mouse_position();
  params->current(param, HOVER);
  return (GO_ON);
}

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key, void *param)
{
  t_key			k;
  t_params		*params;

  params = param;
  params->cur_pos = *bunny_get_mouse_position();
  k.state = state;
  k.key = key;
  k.params = param;
  params->current(&k, KEY);
  return (GO_ON);
}

int	main(UNUSED int ac, UNUSED char **av, char **env)
{
  if (*env == NULL || tekdoom() != 0)
    {
#ifdef DEBUG
      write(2, "TEKDOOM STATUS : KO\n", 20);
#endif
      return (1);
    }
#ifdef DEBUG
  write(2, "TEKDOOM STATUS : OK\n", 20);
#endif
  return (0);
}
