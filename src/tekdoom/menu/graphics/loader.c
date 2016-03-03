/*
** loader.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/graphics
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Dec 27 20:27:25 2015 Luka Boulagnon
** Last update Sun Jan 24 00:17:08 2016 Antoine Baché
*/

#include "tekdoom.h"

void			read_pixels(t_texture *pic, t_bmp header,
				    int fd, int menu_type)
{
  t_color		buffer;

  while (--header.height >= 0)
    {
      header.width = 0;
      while (header.width < pic->width)
	{
	  read(fd, &buffer, sizeof(t_color) - menu_type);
	  pic->pixels[header.height * pic->width + header.width].argb[0] =
	    buffer.argb[3 - menu_type];
	  pic->pixels[header.height * pic->width + header.width].argb[1] =
	    buffer.argb[2 - menu_type];
	  pic->pixels[header.height * pic->width + header.width].argb[2] =
	    buffer.argb[1 - menu_type];
	  pic->pixels[header.height * pic->width + header.width].argb[3] =
	    (menu_type) ? 255 : buffer.argb[0];
	  ++header.width;
	}
    }
}

t_texture		*load_image(const char *path, int menu_type)
{
  int			fd;
  t_bmp			hd;
  t_texture		*pic;
  t_color		buffer;

  if ((fd = open(path, O_RDONLY)) == -1)
    {
#ifdef DEBUG
      printf("\033[31mError: image %s not found\n\033[0m", path);
#endif
      exit(2);
    }
  read(fd, &hd, sizeof(t_bmp));
  if (!(pic = malloc(sizeof(t_color *) + 2 * sizeof(int))))
    err("Error: can't malloc");
  pic->width = hd.width;
  pic->height = hd.height;
  if (!(pic->pixels = malloc(hd.width * hd.height * sizeof(t_color))))
    err("Error: can't malloc");
  hd.width = 0;
  while (++hd.width < 22 * !menu_type)
    read(fd, &buffer, sizeof(t_color) - menu_type);
  read_pixels(pic, hd, fd, menu_type);
  close(fd);
  return (pic);
}
