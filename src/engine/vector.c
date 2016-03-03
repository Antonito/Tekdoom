/*
** vector.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Thu Jan 21 22:12:18 2016 Ludovic Petrenko
** Last update Tue Jan 26 18:55:47 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void	cross_vector(t_vector *u, t_vector *v, t_vector *w)
{
  w->x = u->y * v->z - u->z * v->y;
  w->y = u->z * v->x - u->x * v->z;
  w->z = u->x * v->y - u->y * v->z;
}

double	cross_vector_val(t_vector *u, t_vector *v)
{
  return (u->x * v->x + u->y * v->y + u->z * v->z);
}

double	vector_len(t_vector *v)
{
  return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

void	polygon_center(t_polygon *p, t_vertice *v)
{
   v->x = (p->a->x + p->b->x + p->c->x) / 3;
   v->y = (p->a->y + p->b->y + p->c->y) / 3;
   v->z = (p->a->z + p->b->z + p->c->z) / 3;
}

void	vectorize(t_vertice *m, t_vertice *n, t_vector *v)
{
  v->x = n->x - m->x;
  v->y = n->y - m->y;
  v->z = n->z - m->z;
}
