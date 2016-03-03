/*
** matrix.c for doom in /home/petren_l/rendu/tek1/semestre_01/doom/src
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Mon Jan 11 17:43:32 2016 Ludovic Petrenko
** Last update Wed Jan 27 08:20:27 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void	mtx_clear(double *m)
{
  m[0] = 1;
  m[1] = 0;
  m[2] = 0;
  m[3] = 0;
  m[4] = 0;
  m[5] = 1;
  m[6] = 0;
  m[7] = 0;
  m[8] = 0;
  m[9] = 0;
  m[10] = 1;
  m[11] = 0;
  m[12] = 0;
  m[13] = 0;
  m[14] = 0;
  m[15] = 1;
}

void	mtx_cpy(double *src, double *dest)
{
  dest[0] = src[0];
  dest[1] = src[1];
  dest[2] = src[2];
  dest[3] = src[3];
  dest[4] = src[4];
  dest[5] = src[5];
  dest[6] = src[6];
  dest[7] = src[7];
  dest[8] = src[8];
  dest[9] = src[9];
  dest[10] = src[10];
  dest[11] = src[11];
  dest[12] = src[12];
  dest[13] = src[13];
  dest[14] = src[14];
  dest[15] = src[15];
}

void		mtx_mult_mult(double *m, double *n)
{
  double	tmp[16];

  mtx_cpy(m, tmp);
  m[0] = tmp[0] * n[0] + tmp[1] * n[4] + tmp[2] * n[8] + tmp[3] * n[12];
  m[1] = tmp[0] * n[1] + tmp[1] * n[5] + tmp[2] * n[9] + tmp[3] * n[13];
  m[2] = tmp[0] * n[2] + tmp[1] * n[6] + tmp[2] * n[10] + tmp[3] * n[14];
  m[3] = tmp[0] * n[3] + tmp[1] * n[7] + tmp[2] * n[11] + tmp[3] * n[15];

  m[4] = tmp[4] * n[0] + tmp[5] * n[4] + tmp[6] * n[8] + tmp[7] * n[12];
  m[5] = tmp[4] * n[1] + tmp[5] * n[5] + tmp[6] * n[9] + tmp[7] * n[13];
  m[6] = tmp[4] * n[2] + tmp[5] * n[6] + tmp[6] * n[10] + tmp[7] * n[14];
  m[7] = tmp[4] * n[3] + tmp[5] * n[7] + tmp[6] * n[11] + tmp[7] * n[15];

  m[8] = tmp[8] * n[0] + tmp[9] * n[4] + tmp[10] * n[8] + tmp[11] * n[12];
  m[9] = tmp[8] * n[1] + tmp[9] * n[5] + tmp[10] * n[9] + tmp[11] * n[13];
  m[10] = tmp[8] * n[2] + tmp[9] * n[6] + tmp[10] * n[10] + tmp[11] * n[14];
  m[11] = tmp[8] * n[3] + tmp[9] * n[7] + tmp[10] * n[11] + tmp[11] * n[15];

  m[12] = tmp[12] * n[0] + tmp[13] * n[4] + tmp[14] * n[8] + tmp[15] * n[12];
  m[13] = tmp[12] * n[1] + tmp[13] * n[5] + tmp[14] * n[9] + tmp[15] * n[13];
  m[14] = tmp[12] * n[2] + tmp[13] * n[6] + tmp[14] * n[10] + tmp[15] * n[14];
  m[15] = tmp[12] * n[3] + tmp[13] * n[7] + tmp[14] * n[11] + tmp[15] * n[15];
}

void	mtx_mult_mtx_dest(double *m, double *n, double *res)
{
  res[0] = m[0] * n[0] + m[1] * n[4] + m[2] * n[8] + m[3] * n[12];
  res[1] = m[0] * n[1] + m[1] * n[5] + m[2] * n[9] + m[3] * n[13];
  res[2] = m[0] * n[2] + m[1] * n[6] + m[2] * n[10] + m[3] * n[14];
  res[3] = m[0] * n[3] + m[1] * n[7] + m[2] * n[11] + m[3] * n[15];

  res[4] = m[4] * n[0] + m[5] * n[4] + m[6] * n[8] + m[7] * n[12];
  res[5] = m[4] * n[1] + m[5] * n[5] + m[6] * n[9] + m[7] * n[13];
  res[6] = m[4] * n[2] + m[5] * n[6] + m[6] * n[10] + m[7] * n[14];
  res[7] = m[4] * n[3] + m[5] * n[7] + m[6] * n[11] + m[7] * n[15];

  res[8] = m[8] * n[0] + m[9] * n[4] + m[10] * n[8] + m[11] * n[12];
  res[9] = m[8] * n[1] + m[9] * n[5] + m[10] * n[9] + m[11] * n[13];
  res[10] = m[8] * n[2] + m[9] * n[6] + m[10] * n[10] + m[11] * n[14];
  res[11] = m[8] * n[3] + m[9] * n[7] + m[10] * n[11] + m[11] * n[15];

  res[12] = m[12] * n[0] + m[13] * n[4] + m[14] * n[8] + m[15] * n[12];
  res[13] = m[12] * n[1] + m[13] * n[5] + m[14] * n[9] + m[15] * n[13];
  res[14] = m[12] * n[2] + m[13] * n[6] + m[14] * n[10] + m[15] * n[14];
  res[15] = m[12] * n[3] + m[13] * n[7] + m[14] * n[11] + m[15] * n[15];
}
