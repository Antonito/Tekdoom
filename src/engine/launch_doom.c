/*
** launch_doom.c for doom in /home/petren_l/rendu/tek1/semestre_01/doom/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Mon Jan 11 15:58:46 2016 Ludovic Petrenko
** Last update Wed Jan 27 07:50:25 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int	prepare_gfx(t_wire *wire, UNUSED t_data *data)
{
  if ((wire->zbuf = malloc(WIN_X * WIN_Y * sizeof(double))) == NULL)
    return (1);
  if (load_full_game(wire))
    return (1);
  set_proj_mtx(wire->project_mtx);
  wire->selected = 0;
  if ((wire->world->lights = malloc(3 * sizeof(t_light))) == NULL)
    return (1);
  wire->world->lights[0].next = wire->world->lights + 1;
  wire->world->lights[0].pos.x = 10;
  wire->world->lights[0].pos.y = 20;
  wire->world->lights[0].pos.z = 0;
  wire->world->lights[0].radius = 50;
  wire->world->lights[1].next = wire->world->lights + 2;
  wire->world->lights[1].pos.x = 1;
  wire->world->lights[1].pos.y = 5;
  wire->world->lights[1].pos.z = 10;
  wire->world->lights[1].radius = 10;
  wire->world->lights[2].next = NULL;
  wire->world->lights[2].pos.x = 30;
  wire->world->lights[2].pos.y = 10;
  wire->world->lights[2].pos.z = 1;
  wire->world->lights[2].radius = 30;
  return (0);
}

int	launch_doom(t_wire *wire, t_data *data)
{
  wire->data = data;
  if (prepare_gfx(wire, data))
    return (1);
  init_game(data);
  bunny_sound_play(data->soundtrack);
  bunny_sound_volume(data->soundtrack, 80);
  bunny_set_loop_main_function((t_bunny_loop)&doom_loop);
  bunny_set_key_response((t_bunny_key)&my_escape);
  bunny_set_click_response((t_bunny_click)game_click);
  bunny_set_wheel_response((t_bunny_wheel)game_wheel);
  bunny_set_mouse_visibility(data->win, false);
  bunny_set_mouse_position_window(data->win, WIN_X / 2, WIN_Y / 2);
  bunny_loop(data->win, 200, wire);
  return (0);
}

t_bunny_response	doom_loop(t_wire *wire)
{
  clear_zbuf(wire->zbuf);
  tekfill(wire->data->pix, SKY_COLOR);
  apply_move(wire->world->player);
  if (set_frame(wire))
    return (EXIT_ON_ERROR);
  normalize(&wire->world->player[0].pos.vec);
  my_move(bunny_get_mouse_position(), wire);
  main_game_loop(wire->data);
  bunny_blit(&wire->data->win->buffer,
	     &wire->data->pix->clipable, NULL);
  bunny_display(wire->data->win);
  return (wire->data->player->life > 0 ? GO_ON : EXIT_ON_SUCCESS);
}

void			my_move(const t_bunny_position *pos,
				t_wire *wire)
{
  t_bunny_position	relative;

  relative.x = WIN_X / 2 - pos->x;
  relative.y = WIN_Y / 2 - pos->y;
  if (relative.x || relative.y)
    {
      wire->world->player[0].rotate[0] += (double)relative.x / 10;
      wire->world->player[0].rotate[1] += (double)relative.y / 10;
      if (wire->world->player[0].rotate[1] > 89)
	wire->world->player[0].rotate[1] = 89;
      if (wire->world->player[0].rotate[1] < -89)
	wire->world->player[0].rotate[1] = -89;
      recalc_dir(&wire->world->player[0].pos.vec,
		 wire->world->player[0].rotate);
      normalize(&wire->world->player[0].pos.vec);
      bunny_set_mouse_position_window(wire->data->win, WIN_X / 2,
				      WIN_Y / 2);
      bunny_request_focus(wire->data->win);
    }
}
