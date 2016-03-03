/*
** trigo.c for doom in /home/petren_l/rendu/tek1/semestre_01/doom/src
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Mon Jan 11 16:00:03 2016 Ludovic Petrenko
** Last update Wed Jan 27 07:08:12 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void	set_trigo()
{
  my_sin(0);
  my_cos(0);
  my_tan(0);
}

double		my_tan(double angle)
{
  return (tan(angle * M_PI / 180));
}
