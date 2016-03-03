/*
** load_map_polygon.c for engine in /semestre_01/tekdoom_dev/src/engine
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Mon Jan 25 05:16:57 2016 Ludovic Petrenko
** Last update Wed Jan 27 06:38:31 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

int	load_object(char *file, t_object_container *obj)
{
  my_bzero(obj, sizeof(t_object_container));
  if (load_object_(&obj->original, file) ||
      load_object_(&obj->polygons, file) ||
      load_object_(&obj->transform, file))
    return (1);
  obj->next = obj + 1;
  return (0);
}

int	load_object_(t_object *o, char *file)
{
  int		fd;
  t_face	face;
  int		i;

  i = 0;
  if (((fd = open(file, O_RDONLY)) == -1) || (read(fd, &o->nb_vertex, 4) != 4)
      || ((o->vertex = malloc(o->nb_vertex * sizeof(t_vertice))) == NULL) ||
      (read(fd, o->vertex, o->nb_vertex * sizeof(t_vertice)) !=
       (int)(o->nb_vertex * sizeof(t_vertice))) ||
      (read(fd, &o->nb_polygons, 4) != 4) ||
      ((o->polygons = malloc(o->nb_polygons * sizeof(t_polygon))) == NULL))
    return (1);
  while (i < o->nb_polygons)
    {
      if (read(fd, &face, sizeof(t_face)) != sizeof(t_face))
	return (1);
      o->polygons[i].a = o->vertex + face.a;
      o->polygons[i].b = o->vertex + face.b;
      o->polygons[i].c = o->vertex + face.c;
      o->polygons[i].color = face.color;
      i++;
    }
  close(fd);
  return (0);
}
