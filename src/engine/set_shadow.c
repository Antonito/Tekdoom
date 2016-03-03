/*
** set_shadow.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Thu Jan 21 00:06:50 2016 Ludovic Petrenko
** Last update Wed Jan 27 06:09:54 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void	set_shadow(t_object *obj, t_light *light)
{
  int	i;

  i = 0;
  while (i < obj->nb_vertex)
    {
      set_shadow_vertex(obj->vertex + i, light);
      i++;
    }
  i = 0;
  while (i < obj->nb_polygons)
    {
      set_shadow_polygons(obj->polygons + i, light);
      i++;
    }
}

void		set_shadow_vertex(t_vertice *v, t_light *light)
{
  double	total;
  double	dist;
  double	nb;

  total = 0;
  nb = 0;
  while (light != NULL)
    {
      dist = sqrt(POW2(v->x - light->pos.x) +
		  POW2(v->y - light->pos.y) +
		  POW2(v->z - light->pos.z));
      if (dist < light->radius)
	{
	  total += (light->radius - dist) / light->radius;
	  nb++;
	}
      light = light->next;
    }
  v->light = total / ((nb == 0) ? 1 : nb);
}

void		set_shadow_polygons(t_polygon *p, t_light *light)
{
  double	total;
  double	dist;
  t_vector	v[4];
  int		nb;
  t_vertice	center;

  total = 0;
  nb = 0;
  while (light != NULL)
    {
      polygon_center(p, &center);
      vectorize(&center, &light->pos, v);
      if ((dist = vector_len(v)) < light->radius)
	{
 	  normalize(v);
	  vectorize(p->a, p->b, v + 2);
	  vectorize(p->a, p->c, v + 3);
	  cross_vector(v + 2, v + 3, v + 1);
	  normalize(v + 1);
	  total += MAX(0, cross_vector_val(v, v + 1));
	  nb++;
	}
      light = light->next;
    }
  p->light = total / ((nb == 0) ? 1 : nb);
}

void	cp_light(t_object *polygons, t_object *transform)
{
  int	i;

  i = 0;
  while (i < polygons->nb_polygons)
    {
      transform->polygons[i].light = polygons->polygons[i].light;
      i++;
    }
}
