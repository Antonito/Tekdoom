/*
** get_triangle.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Sat Jan 16 19:37:28 2016 Ludovic Petrenko
** Last update Wed Jan 27 06:57:28 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void	get_triangle(t_polygon *p, t_polygon *t)
{
  *t = *p;

  if (t->c->y < t->b->y)
    swap_vert(&t->c, &t->b);
  if (t->c->y < t->a->y)
    swap_vert(&t->c, &t->a);
  if (t->b->y < t->a->y)
    swap_vert(&t->b, &t->a);
}

void		swap_vert(t_vertice **p1, t_vertice **p2)
{
  t_vertice	*p3;

  p3 = *p1;
  *p1 = *p2;
  *p2 = p3;
}

void		swap_vert2(t_vertice *p1, t_vertice *p2)
{
  t_vertice	p3;

  p3 = *p1;
  *p1 = *p2;
  *p2 = p3;
}
