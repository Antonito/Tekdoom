/*
** draw_polygon.c for doom in /home/petren_l/rendu/tek1/semestre_01/doom
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Mon Jan 11 23:24:36 2016 Ludovic Petrenko
** Last update Wed Jan 27 08:21:32 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int		draw_triangle(t_bunny_pixelarray *pix,
			      t_polygon *p, double *zbuf)
{
  double	a[3];

  if (p->a->y != p->b->y)
    a[0] = (p->a->x - p->b->x) / (p->a->y - p->b->y);
  else
    a[0] = (p->a->x - p->b->x) / 0.000001;
  if (p->b->y != p->c->y)
    a[1] = (p->b->x - p->c->x) / (p->b->y - p->c->y);
  else
    a[1] = (p->b->x - p->c->x) / 0.000001;
  if (p->c->y != p->a->y)
    a[2] = (p->c->x - p->a->x) / (p->c->y - p->a->y);
  else
    a[2] = (p->c->x - p->a->x) / 0.000001;
  draw_triangle_top(pix, p, a, zbuf);
  draw_triangle_bot(pix, p, a, zbuf);
  return (0);
}

void		*draw_triangle_top(t_bunny_pixelarray *pix, t_polygon *p,
			  double *a, double *zbuf)
{
  t_vertice	pt[2];
  unsigned int	color;
  double	y;

  color = get_full_color(p->color);
  color = get_color(color, p->light * 0.7 + 0.3);
  y = p->a->y;
  if (y < 0.00)
    y = 0;
  while (y < p->b->y && ROUND(y) < pix->clipable.clip_width)
    {
      get_line(p, a, y, pt);
      draw_line(pix, pt, zbuf, color);
      y += 1;
    }
  return (NULL);
}

void		*draw_triangle_bot(t_bunny_pixelarray *pix, t_polygon *p,
			  double *a, double *zbuf)
{
  t_vertice	pt[2];
  unsigned int	color;
  double	y;

  color = get_full_color(p->color);
  color = get_color(color, p->light * 0.7 + 0.3);
  y = p->b->y;
  if (y < 0.00)
    y = 0;
  while (y <= p->c->y && y < pix->clipable.clip_height)
    {
      get_line(p, a, y, pt);
      draw_line(pix, pt, zbuf, color);
      y += 1;
    }
  return (NULL);
}

void		draw_line(t_bunny_pixelarray *pix, t_vertice *pt,
		  double *zbuf, unsigned int color)
{
  double	x;
  double	y;
  double	coeff;
  double	dist;

  x = (pt[0].x > 0.00) ? ROUND(pt[0].x): 0;
  y = ROUND(pt->y);
  while (x <= pt[1].x && x < (double)pix->clipable.clip_width)
    {
      coeff = (x - pt[0].x) / (pt[1].x - pt[0].x);
      dist = (1 - coeff) * pt[0].z + coeff * pt[1].z;
      if (x >= 0.0 && x < (double)pix->clipable.clip_width &&
	  y >= 0.0 && y < (double)pix->clipable.clip_height &&
	  dist >= zbuf[ROUND(x) + pix->clipable.clip_width * ROUND(y)] && dist < 0)
      	{
	  tekpixel(pix, ROUND(x), ROUND(y),
		   get_color(color, ((1 - coeff) * pt[0].light +
				     coeff * pt[1].light) * 0.7 + 0.3));
	  zbuf[ROUND(x) + pix->clipable.clip_width * ROUND(y)] = dist;
	}
      x += 1;
    }
}

void		tekpixel(t_bunny_pixelarray *pix, int x,
			 int y, unsigned int color)
{
  unsigned int	*pixels;

  pixels = (unsigned int*)pix->pixels;
  pixels[x + y * pix->clipable.clip_width] = color;
}
