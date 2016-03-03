/*
** count_render_test.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Fri Jan 15 21:28:21 2016 Ludovic Petrenko
** Last update Tue Jan 26 17:18:30 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

int	is_backface(t_polygon *p)
{
  if ((p->a->x - p->b->x) * (p->c->y - p->b->y) -
      (p->a->y - p->b->y) * (p->c->x - p->b->x) < 0)
    return (1);
  return (0);
}

int	is_cliped(t_polygon *p, double z)
{
  int	out;

  out = 0;
  if (p->a->w > z)
    out++;
  if (p->b->w > z)
    out++;
  if (p->c->w > z)
    out++;
  p->clip_type = out;
  return (out);
}
