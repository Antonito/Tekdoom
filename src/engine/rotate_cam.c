/*
** rotate_cam.c for motor3d in /home/petren_l/rendu/tek1/semestre_01/motor3d
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Mon Jan  4 01:19:12 2016 Ludovic Petrenko
** Last update Wed Jan 27 06:11:23 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void		rotate_cam_x(t_vector *dir, double angle)
{
  t_vector	t;

  t = *dir;
  dir->x = t.x * my_cos(angle) + t.z * my_sin(angle);
  dir->z = -t.x * my_sin(angle) + t.z * my_cos(angle);
}

void		rotate_cam_y(t_vector *dir, double angle)
{
  t_vector	u;
  t_vector	t;
  double	len;

  len = dir->x * dir->x + dir->z * dir->z;
  u.x = -dir->z / len;
  u.y = 0;
  u.z = dir->x / len;
  t = *dir;
  dir->x = t.x * (u.x * u.x * (1 - my_cos(angle)) + my_cos(angle)) +
    t.y * (u.x * u.y * (1 - my_cos(angle)) - u.z * my_sin(angle)) +
    t.z * (u.x * u.z * (1 - my_cos(angle)) + u.y * my_sin(angle));
  dir->y = t.x * (u.x * u.y * (1 - my_cos(angle)) + u.z * my_sin(angle)) +
    t.y * (u.y * u.y * (1 - my_cos(angle)) + my_cos(angle)) +
    t.z * (u.y * u.z * (1 - my_cos(angle)) - u.x * my_sin(angle));
  dir->z = t.x * (u.x * u.z * (1 - my_cos(angle)) - u.y * my_sin(angle)) +
    t.y * (u.y * u.z * (1 - my_cos(angle)) + u.x * my_sin(angle)) +
    t.z * (u.z * u.z * (1 - my_cos(angle)) + my_cos(angle));
}

void		normalize(t_vector *v)
{
  double	len;

  len = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
  if (len > 0.00)
    {
      v->x /= len;
      v->y /= len;
      v->z /= len;
    }
  else
    {
      v->x = 0;
      v->y = 0;
      v->z = 0;
    }
}
