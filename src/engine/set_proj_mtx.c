/*
** set_proj_mtx.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Fri Jan 15 19:43:01 2016 Ludovic Petrenko
** Last update Tue Jan 26 07:20:19 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void	set_proj_mtx(double *m)
{
  m[0] = 1 / (my_tan(FOV / 2.0) * 16 / 9.0);
  m[1] = 0;
  m[2] = 0;
  m[3] = 0;
  m[4] = 0;
  m[5] = 1 / (my_tan(FOV / 2.0));
  m[6] = 0;
  m[7] = 0;
  m[8] = 0;
  m[9] = 0;
  m[10] = (-ZNEAR - ZFAR) / (ZNEAR - ZFAR);
  m[11] = 2 * ZFAR * ZNEAR / (ZNEAR - ZFAR);
  m[12] = 0;
  m[13] = 0;
  m[14] = 1;
  m[15] = 0;
}
