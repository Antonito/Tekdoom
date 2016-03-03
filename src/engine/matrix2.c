/*
** matrix2.c for doom in /home/petren_l/rendu/tek1/semestre_01/doom/src
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Mon Jan 11 18:19:13 2016 Ludovic Petrenko
** Last update Wed Jan 27 08:20:47 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void		mtx_mult_vtx(double *m, t_vertice *v)
{
  t_vertice	t;

  t = *v;
  v->x = m[0] * t.x + m[1] * t.y + m[2] * t.z + m[3] * t.w;
  v->y = m[4] * t.x + m[5] * t.y + m[6] * t.z + m[7] * t.w;
  v->z = m[8] * t.x + m[9] * t.y + m[10] * t.z + m[11] * t.w;
  v->w = m[12] * t.x + m[13] * t.y + m[14] * t.z + m[15] * t.w;
}

void	mtx_mult_vtx_dest(double *m, t_vertice *v, t_vertice *dest)
{
  dest->x = m[0] * v->x + m[1] * v->y + m[2] * v->z + m[3] * v->w;
  dest->y = m[4] * v->x + m[5] * v->y + m[6] * v->z + m[7] * v->w;
  dest->z = m[8] * v->x + m[9] * v->y + m[10] * v->z + m[11] * v->w;
  dest->w = m[12] * v->x + m[13] * v->y + m[14] * v->z + m[15] * v->w;
}

void	set_camera_mtx_(double *m, t_vector *a, t_vector *pos)
{
  normalize(a + 1);
  normalize(a + 2);
  normalize(a + 3);
  m[0] = a[1].x;
  m[1] = a[1].y;
  m[2] = a[1].z;
  m[3] = -pos->x * a[1].x - pos->y * a[1].y - pos->z * a[1].z;
  m[4] = a[2].x;
  m[5] = a[2].y;
  m[6] = a[2].z;
  m[7] = -pos->x * a[2].x - pos->y * a[2].y - pos->z * a[2].z;
  m[8] = a[3].x;
  m[9] = a[3].y;
  m[10] = a[3].z;
  m[11] = -pos->x * a[3].x - pos->y * a[3].y - pos->z * a[3].z;
  m[12] = 0;
  m[13] = 0;
  m[14] = 0;
  m[15] = 1;
}

void		set_camera_mtx(double *m, t_vector *dir, t_vector *pos, double roll)
{
  t_vector	a[4];

  a[0].x = my_sin(roll);
  a[0].y = -my_cos(roll);
  a[0].z = 0;
  normalize(a);
  normalize(dir);
  a[3].x = -dir->x;
  a[3].y = -dir->y;
  a[3].z = -dir->z;
  a[1].x = a[3].z * a[0].y - a[3].y * a[0].z;
  a[1].y = a[3].x * a[0].z - a[3].z * a[0].x;
  a[1].z = a[3].y * a[0].x - a[3].x * a[0].y;
  a[2].x = a[1].y * a[3].z - a[1].z * a[3].y;
  a[2].y = a[1].z * a[3].x - a[1].x * a[3].z;
  a[2].z = a[1].x * a[3].y - a[1].y * a[3].x;
  set_camera_mtx_(m, a, pos);
}
