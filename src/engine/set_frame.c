/*
** set_frame.c for doom in /home/petren_l/rendu/tek1/semestre_01/doom/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Mon Jan 11 17:41:19 2016 Ludovic Petrenko
** Last update Tue Jan 26 12:09:00 2016 Antoine Baché
*/

#include "tekdoom.h"

int			set_frame(t_wire *wire)
{
  double		cam_mtx[16];
  t_object_container	*obj;

  obj = wire->world->objects;
  set_camera_mtx(cam_mtx, &wire->world->player[0].pos.vec,
		 &wire->world->player[0].pos.dir,
		 wire->world->player[0].roll);
  while (obj != NULL)
    {
      if (wire->world->objects->polygons.nb_polygons > 0)
	{
	  set_shadow(&obj->polygons, wire->world->lights);
	  set_shadow(&obj->transform, wire->world->lights);
	  cp_light(&obj->polygons, &obj->transform);
	  world_to_view(&obj->polygons, &obj->transform, cam_mtx);
	  view_to_projection(&obj->transform, wire->project_mtx);
	  draw_chunk(wire->data->pix, &obj->transform, wire->zbuf);
	}
      obj = obj->next;
    }
  return (0);
}
