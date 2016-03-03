/*
** recalc_dir.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Tue Jan 19 19:11:39 2016 Ludovic Petrenko
** Last update Wed Jan 27 06:11:38 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void		recalc_dir(t_vector *dir, double rot[2])
{
  t_vector	t;

  t.x = 0;
  t.y = 0;
  t.z = -1;
  dir->x = 0;
  dir->y = my_sin(rot[1]);
  dir->z = -my_cos(rot[1]);
  t = *dir;
  dir->x = t.x * my_cos(rot[0]) + t.z * my_sin(rot[0]);
  dir->z = -t.x * my_sin(rot[0]) + t.z * my_cos(rot[0]);
}
