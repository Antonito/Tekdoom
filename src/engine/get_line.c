/*
** get_line.c for engine in /tek1/semestre_01/tekdoom_dev/src/engine
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Wed Jan 20 18:11:01 2016 Ludovic Petrenko
** Last update Wed Jan 27 06:57:46 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void		get_line(t_polygon *p, double *a, double y, t_vertice *pt)
{
  double	coeff;

  if (y < p->b->y)
    {
      pt[0].x = a[0] * (y - p->b->y) + p->b->x;
      coeff = sqrt((POW2(p->a->x - pt[0].x) + POW2(p->a->y - y)) /
		   (POW2(p->a->x - p->b->x) + POW2(p->a->y - p->b->y)));
      pt[0].z = (1 - coeff) * p->a->z + coeff * p->b->z;
      pt[0].light = (1 - coeff) * p->a->light + coeff * p->b->light;
    }
  else
    {
      pt[0].x = a[1] * (y - p->b->y) + p->b->x;
      coeff = sqrt((POW2(p->b->x - pt[0].x) + POW2(p->b->y - y)) /
		   (POW2(p->b->x - p->c->x) + POW2(p->b->y - p->c->y)));
      pt[0].z = (1 - coeff) * p->b->z + coeff * p->c->z;
      pt[0].light = (1 - coeff) * p->b->light + coeff * p->c->light;
    }
  pt[1].x = a[2] * (y - p->a->y) + p->a->x;
  coeff = sqrt((POW2(p->a->x - pt[1].x) + POW2(p->a->y - y)) /
	       (POW2(p->a->x - p->c->x) + POW2(p->a->y - p->c->y)));
  pt[1].z = (1 - coeff) * p->a->z + coeff * p->c->z;
  pt[1].light = (1 - coeff) * p->a->light + coeff * p->c->light;
  if (pt[0].x > pt[1].x)
    swap_vert2(pt, pt + 1);
  pt[0].y = y;
}

unsigned int		get_full_color(unsigned char c)
{
  static unsigned int   palette[11];
  static bool		is_set = false;
  int			color;
  int			i;

  if (is_set == false)
    {
      set_palette(palette);
      is_set = true;
    }
  color = (int)c;
  i = 0;
  while (i < 11)
    {
      if (color == i)
	return (palette[i]);
      i++;
    }
  return (0xFFFFFFFF);
}

void	set_palette(unsigned int *palette)
{
  palette[0] = 0xFFFFFFFF;
  palette[1] = 0xFF0000FF;
  palette[2] = 0xFF00FF00;
  palette[3] = 0xFFFF0000;
  palette[4] = 0xFF0000FF;
  palette[5] = 0xFFFFFFFF;
  palette[6] = 0xFFFFCC44;
  palette[7] = 0xFFFFFFFF;
  palette[8] = 0xFFFFFFFF;
  palette[9] = 0xFFFFFFFF;
  palette[10] = 0xFFFFFFFF;
}

unsigned int	get_color(unsigned int color, double light)
{
  t_color	c;

  c.full = color;
  c.argb[0] = (unsigned char)(c.argb[0] * light);
  c.argb[1] = (unsigned char)(c.argb[1] * light);
  c.argb[2] = (unsigned char)(c.argb[2] * light);
  return (c.full);
}
