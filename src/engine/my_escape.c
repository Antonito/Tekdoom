/*
** my_escape.c for engine in /tek1/semestre_01/test/tekdoom_dev
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Wed Jan 27 06:55:45 2016 Ludovic Petrenko
** Last update Thu Jan 28 13:40:57 2016 Antoine Baché
*/

#include "tekdoom.h"

int	my_escape_(t_bunny_event_state state,
		   t_bunny_keysym keysym,
		   t_wire *wire, t_vertice move)
{
  if (state == GO_DOWN && keysym == BKS_RIGHT)
    {
      wire->world->player[0].pos.dir.x -= move.z / 3;
      wire->world->player[0].pos.dir.z += move.x / 3;
    }
  if (state == GO_DOWN && keysym == BKS_LEFT)
    {
      wire->world->player[0].pos.dir.x += move.z / 3;
      wire->world->player[0].pos.dir.z -= move.x / 3;
    }
  if (state == GO_DOWN && keysym == BKS_O)
    wire->world->player[0].roll += 2;
  if (state == GO_DOWN && keysym == BKS_P)
    wire->world->player[0].roll -= 2;
  if (state == GO_DOWN && keysym == BKS_Z)
    wire->world->player[0].pos.dir.y += 0.2;
  if (state == GO_DOWN && keysym == BKS_S)
    wire->world->player[0].pos.dir.y -= 0.2;
  return (0);
}

t_bunny_response	my_escape(t_bunny_event_state state,
				  t_bunny_keysym keysym,
				  t_wire *wire)
{
  t_vertice	move;

  if (keysym == BKS_UNKNOWN)
    return (GO_ON);
  if (keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  game_key(state, keysym, wire->data);
  move.x = wire->world->player[0].pos.vec.x;
  move.y = 0;
  move.z = wire->world->player[0].pos.vec.z;
  normalize(&move);
  if (state == GO_DOWN && keysym == BKS_UP)
    {
      wire->world->player[0].pos.dir.x += move.x / 3;
      wire->world->player[0].pos.dir.z += move.z / 3;
    }
  if (state == GO_DOWN && keysym == BKS_DOWN)
    {
      wire->world->player[0].pos.dir.x -= move.x / 3;
      wire->world->player[0].pos.dir.z -= move.z / 3;
    }
  if (my_escape_(state, keysym, wire, move))
    return (EXIT_ON_ERROR);
  return (GO_ON);
}
