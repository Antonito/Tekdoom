/*
** walls.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/graphics
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Sun Dec 27 20:14:24 2015 Luka Boulagnon
** Last update Wed Jan 27 08:24:49 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void			draw_walls(t_bunny_pixelarray *to,
				   t_proj *proj,
				   t_bunny_position step,
				   t_texture **textures)
{
  int			i;
  int			j;
  float			pas;
  float			altitude;
  t_draw_wall		wall;

  i = to->clipable.clip_width - 1 - step.x;
  while (i-- + step.x)
    {
      j = (1080 / 2 - 30000 / (proj[i].z_buffer /= 2));
      pas = (512 / (60000 / proj[i].z_buffer));
      altitude = 60000.0 / proj[i].z_buffer / 512.0;
      if (++j < 0)
	{
	  altitude -= (float)j * pas;
	  j = 0;
	}
      wall = set(j, altitude, to, proj);
      set_wall(i, wall, textures, pas);
    }
}

t_color		get_pix(t_texture *texture, int longitude, int altitude)
{
  t_color	black;

  black.full = texture->pixels[texture->width * texture->height - 1].full;
  if (altitude >= 512 || altitude < 0)
    return (black);
  (void)texture;
  if (longitude < 0 || altitude < 0)
    return (black);
  return (texture->pixels[altitude * texture->width + longitude]);
}

void			set_wall(int i, t_draw_wall wall, t_texture **textures,
				 float pas)
{
  t_color		*pixels;
  int			height;
  int			width;

  pixels = wall.to->pixels;
  height = wall.to->clipable.clip_height;
  width = wall.to->clipable.clip_width;
  while (++wall.j < (540 + 30000 / wall.proj[i].z_buffer) && wall.j < height)
    {
      if (wall.proj[i].wall > 4 || wall.proj[i].wall < 1)
	err("Error: invalid ini file");
      wall.proj[i].color = get_pix(textures[wall.proj[i].wall - 1], 512 *
			      dec_part(wall.proj[i].to.y) + 512 *
			      dec_part(wall.proj[i].to.x), wall.alt);
      wall.alt += pas;
      if (wall.j >= 0)
	pixels[(wall.j) * width + i].full = wall.proj[i].color.full;
    }
}

t_draw_wall	set(int j, float alt, t_bunny_pixelarray *to, t_proj *proj)
{
  t_draw_wall	wall;

  wall.j = j;
  wall.alt = alt;
  wall.to = to;
  wall.proj = proj;
  return (wall);
}
