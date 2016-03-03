/*
** apply_move.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Tue Jan 26 08:26:52 2016 Ludovic Petrenko
** Last update Tue Jan 26 18:52:44 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void	apply_move(t_player *players)
{
  int	i;
  int	j;

  i = 1;
  while (i < 8)
    {
      j = 0;
      while (j < players[i].object->original.nb_vertex)
	{
	  players[i].object->polygons.vertex[j].x =
	    players[i].object->original.vertex[j].x + players[i].pos.dir.x;
	  players[i].object->polygons.vertex[j].y =
	    players[i].object->original.vertex[j].y + players[i].pos.dir.y;
	  players[i].object->polygons.vertex[j].z =
	    players[i].object->original.vertex[j].z + players[i].pos.dir.z;
	  j++;
	}
      i++;
    }
}
