/*
** L2V.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Fri Jan 15 12:52:02 2016 Ludovic Petrenko
** Last update Wed Jan 27 08:21:37 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void	world_to_view(t_object *polygons,
		      t_object *transform,
		      double *cam_mtx)
{
  int	i;

  i = 0;
  transform->nb_polygons = polygons->nb_polygons;
  transform->nb_vertex = polygons->nb_vertex;
  while (i < polygons->nb_vertex)
    {
      mtx_mult_vtx_dest(cam_mtx, polygons->vertex + i,
			transform->vertex + i);
      transform->vertex[i].light = polygons->vertex[i].light;
      i++;
    }
}

void	view_to_projection(t_object *transform,
			   double *proj_mtx)
{
  int	i;

  i = 0;
  while (i < transform->nb_vertex)
    {
      mtx_mult_vtx(proj_mtx, transform->vertex + i);
      transform->vertex[i].x = transform->vertex[i].x * WIN_X / 2 /
	transform->vertex[i].w + WIN_X / 2;
      transform->vertex[i].y = transform->vertex[i].y * WIN_Y / 2 /
	transform->vertex[i].w + WIN_Y / 2;
      i++;
    }
}

int		draw_polygon(t_bunny_pixelarray *pix,
			     t_polygon *p, double *zbuf)
{
  t_polygon	t;

  get_triangle(p, &t);
  if (is_cliped(p, -1) == 0 && is_backface(p) == 0)
    draw_triangle(pix, &t, zbuf);
  return (0);
}
