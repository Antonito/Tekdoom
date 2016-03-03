/*
** projection.c for wolf in /home/asphahyre/rendu/gfx_menu/src/perspective
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Thu Dec 17 19:08:02 2015 Luka Boulagnon
** Last update Tue Jan 26 11:12:37 2016 Antoine Baché
*/

#include "tekdoom.h"

void	draw_up(t_bunny_pixelarray *content,
		float *vec, t_color *color)
{
  int	i;
  int	j;

  j = vec[1] - 1;
  while ((j = j + 1) <= vec[6] && j < vec[3])
    if ((i = ((float) j - vec[1]) / vec[4] + vec[0]) <= vec[5])
      if (get_pixel(content, i, vec[6] - j))
	mean_color(get_pixel(content, i, vec[6] - j), *color, 0.9);
}

void	draw_down(t_bunny_pixelarray *content,
		  float *vec, t_color *color)
{
  int	i;
  int	j;

  i = vec[0] - 1;
  while ((i = i + 1) <= vec[5] && i < vec[2])
    if ((j = (((float) i - vec[0]) * vec[4] + vec[1])) <= vec[6])
      if (get_pixel(content, i, vec[6] - j))
	mean_color(get_pixel(content, i, vec[6] - j), *color, 0.9);
}

void	draw_line_game(t_bunny_pixelarray *content,
		  t_bunny_position from, t_bunny_position to,
		  t_color *color)
{
  float	vector[7];

  vector[0] = from.x;
  vector[1] = from.y;
  vector[2] = to.x;
  vector[3] = to.y;
  vector[4] = ((float) (from.y - to.y) / (float) (from.x - to.x));
  vector[5] = content->clipable.clip_width - 1;
  vector[6] = content->clipable.clip_height - 1;
  if (vector[4] > 1 || vector[4] < -1)
    draw_up(content, vector, color);
  else
    draw_down(content, vector, color);
}

void			line(t_bunny_pixelarray *content,
			     t_bunny_position to,
			     t_bunny_position from,
			     t_color *color)
{
  t_bunny_position	tmp;
  float			coef;

  coef = ((float) (to.y - from.y) / (float) (to.x - from.x));
  if ((((to.x > from.x || to.y > from.y) &&
	(!(to.x < from.x && to.y > from.y))) ||
       (coef < -1)) &&
      !(coef < -1 && to.y < from.y))
    {
      tmp = to;
      to = from;
      from = tmp;
    }
  draw_line_game(content, to, from, color);
}

t_coord		project(int x, int y, int z, t_camera cam)
{
  t_coord	result;

  x = x - cam.pos.x;
  y = y - cam.pos.y;
  z = z - cam.pos.z;
  result.y = cos(cam.orientation[1]) *
    (sin(cam.orientation[2]) * y + cos(cam.orientation[2]) * x)
    - sin(cam.orientation[1]) * z;
  result.x = sin(cam.orientation[0]) *
    (cos(cam.orientation[1]) * z + sin(cam.orientation[1]) *
     (sin(cam.orientation[2] * y + cos(cam.orientation[2] * x))))
    + cos(cam.orientation[1]) * (cos(cam.orientation[2]) * y
				 - sin(cam.orientation[2]) * x);
  result.z = cos(cam.orientation[0]) *
    (cos(cam.orientation[1]) * z + sin(cam.orientation[1]) *
     (sin(cam.orientation[2] * y + cos(cam.orientation[2] * x))))
    + sin(cam.orientation[1]) * (cos(cam.orientation[2]) * y
				 - sin(cam.orientation[2]) * x);
  result.y = -result.y;
  return (result);
}
