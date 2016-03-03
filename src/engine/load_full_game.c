/*
** load_full_game.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Tue Jan 26 04:23:16 2016 Ludovic Petrenko
** Last update Wed Jan 27 06:42:37 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void	load_full_game_(t_player *p)
{
  p->pos.vec.x = 0;
  p->pos.vec.y = 0;
  p->pos.vec.z = -1;
  p->pos.dir.x = 0;
  p->pos.dir.y = 0;
  p->pos.dir.z = 8;
  p->roll = 0;
  p->rotate[0] = 0;
  p->rotate[1] = 0;
}

int	load_full_game(t_wire *wire)
{
  int	i;

  i = -1;
  if ((wire->world = malloc(sizeof(t_world))) == NULL)
    return (1);
  wire->world->player = wire->data->player;
  if ((wire->world->objects = malloc(NB_OBJ * sizeof(t_object_container)))
      == NULL)
    return (1);
  if (load_object("world.dat", wire->world->objects))
    return (1);
  while (++i < 8)
    {
      if (i)
	{
      if (load_object("player.dat", wire->world->objects + i))
	return (1);
      wire->world->player[i].object = wire->world->objects + i;
	}
      else
	wire->world->player[i].object = NULL;
      load_full_game_(wire->world->player + i);
    }
  wire->world->objects[NB_OBJ - 1].next = NULL;
  return (0);
}
