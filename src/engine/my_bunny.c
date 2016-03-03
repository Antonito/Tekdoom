/*
** my_bunny.c for rohan in /tek1/semestre_01/gfx_colle_fantasy2/rohan
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Wed Jan 13 19:08:24 2016 Ludovic Petrenko
** Last update Tue Jan 26 09:54:44 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

t_bunny_pixelarray	*my_bunny_load_pixelarray(char *file)
{
  t_bunny_pixelarray	*pix;

  if ((pix = bunny_load_pixelarray(file)) == NULL)
    my_puterr("Cannot open ", file);
  return (pix);
}

t_bunny_pixelarray	*my_bunny_new_pixelarray(int width, int height)
{
  t_bunny_pixelarray	*pix;

  if ((pix = bunny_new_pixelarray(width, height)) == NULL)
    my_puterr("Cannot create the pixelarray", NULL);
  return (pix);
}

t_bunny_window		*my_bunny_start(int width, int height,
					bool fullscreen, char *name)
{
  t_bunny_window	*win;

  if ((win = bunny_start(width, height, fullscreen, name)) == NULL)
    my_puterr("Cannot start the window : ", name);
  return (win);
}

void	*my_malloc(int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    my_puterr("Memory allocation failed", NULL);
  return (ptr);
}
