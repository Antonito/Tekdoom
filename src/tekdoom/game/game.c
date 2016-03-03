/*
** game.c for Tekdoom in /gfx_tekdoom/src/tekdoom/game
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 13:53:22 2016 Antoine Baché
** Last update Thu Feb  4 12:25:04 2016 Antoine Baché
*/

#include <stdio.h>
#include "tekdoom.h"

t_bunny_response	game_key(t_bunny_event_state state, t_bunny_keysym key,
				 t_data *data)
{
  if (state == GO_DOWN)
    {
      if (key == BKS_RETURN)
	display_game_chat(data);
      else if (key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      else if (key == BKS_1 && unset_weapon(data->player))
	data->player->knife.is_selected = 1;
      else if (key == BKS_2 && unset_weapon(data->player))
	data->player->gun.is_selected = 1;
      else if (key == BKS_3 && unset_weapon(data->player))
	data->player->rifle.is_selected = 1;
    }
  return (GO_ON);
}

t_bunny_response	game_click(t_bunny_event_state state,
				   t_bunny_mousebutton key,
				   t_wire *wire)
{
  t_data *data;

  data = wire->data;
  if (state == GO_DOWN && key == BMB_LEFT && can_shot(data))
    data->event.bits.shot = data->event.bits.shoting = !(data->count = 0);
  else if (state == GO_UP && key == BMB_LEFT)
    data->event.bits.shoting = 0;
  return (GO_ON);
}

t_bunny_response	main_game_loop(t_data *data)
{
  display_interface(data);
  if (data->chat_toggle)
    {
      display_cursor(data);
      ++data->cursor_toggle;
    }
  if (++data->count >= MAX_COUNT)
    data->count = 0;
  if (data->player->knife.is_selected || !(data->count % 4))
    data->event.bits.shot = play_sound(data);
  if (!((data->count + 2) % 4) && data->player->rifle.is_selected &&
      data->event.bits.shoting)
    data->event.bits.shot = ((data->count + 2) % 4) || can_shot(data);
  return (GO_ON);
}

t_bunny_response	game_wheel(UNUSED int id, int delta, t_wire *wire)
{
  t_data *data;

  data = wire->data;
  if (data->player->knife.is_selected
      && !(data->player->knife.is_selected = 0))
  {
    if (delta == 1)
      data->player->gun.is_selected = 1;
    else
      data->player->rifle.is_selected = 1;
  }
  else if (data->player->gun.is_selected
	   && !(data->player->gun.is_selected = 0))
  {
    if (delta == 1)
      data->player->rifle.is_selected = 1;
    else
      data->player->knife.is_selected = 1;
  }
  else if (data->player->rifle.is_selected
	   && !(data->player->rifle.is_selected = 0))
    gun_selected(data, delta);
  return (GO_ON);
}
