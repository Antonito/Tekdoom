/*
** inits.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/graphics
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Sun Dec 27 19:41:15 2015 Luka Boulagnon
** Last update Wed Jan 27 08:25:04 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void			init_camera(t_camera *cam)
{
  cam->orientation[0] = 0;
  cam->orientation[1] = 0;
  cam->orientation[2] = 0;
  cam->pos.x = 0;
  cam->pos.y = 0;
  cam->pos.z = 0;
}

void			init_textures(t_texture ***textures)
{
  int		i;
  char		*path;

  path = my_strdup("assets/imgs/wall-text00.bmp");
  *textures = malloc(10 * sizeof(t_texture));
  i = 0;
  while (++i < 5)
  {
    path[22] = i + '0';
    (*textures)[i - 1] = load_image(path, 0);
  }
}

void			init_musics(t_params *par)
{
  par->intro_sound = bunny_load_music("assets/videos/introduct.wav");
  par->menu_sound = bunny_load_music("assets/sounds/menu.wav");
  par->rick_roll = bunny_load_music("assets/videos/rick_roll.wav");
  par->load_sound = bunny_load_music("assets/sounds/load.wav");
  par->loop_sound = bunny_load_music("assets/sounds/main.wav");
  if (!(par->menu_sound) || !(par->intro_sound) || !(par->rick_roll) ||
      !(par->load_sound) || !(par->load_sound))
    err("Error: missing assets");
}
