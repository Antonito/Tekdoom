/*
** graphics.h for Tekdoom in /gfx_tekdoom/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 11 20:32:49 2016 Antoine Baché
** Last update Mon Feb 15 16:37:27 2016 Antoine Baché
*/

#ifndef	GRAPHICS_H_
# define GRAPHICS_H_

# include <lapin.h>

typedef struct		s_texture
{
  int			width;
  int			height;
  t_color		*pixels;
}			t_texture;

typedef struct					s_bmp
{
  __attribute__((packed)) unsigned short	type;
  __attribute__((packed)) unsigned int		size;
  __attribute__((packed)) unsigned int		reserved;
  __attribute__((packed)) unsigned int		offset;
  __attribute__((packed)) unsigned int		size_struct;
  __attribute__((packed)) int			width;
  __attribute__((packed)) int			height;
  __attribute__((packed)) unsigned short	one;
  __attribute__((packed)) unsigned short	color_resolution;
  __attribute__((packed)) unsigned int		compression;
  __attribute__((packed)) unsigned int		byte_size;
  __attribute__((packed)) int			resolution_hor;
  __attribute__((packed)) int			resolution_ver;
  __attribute__((packed)) unsigned int		nb_colors;
  __attribute__((packed)) unsigned int		nb_imp_colors;
}						t_bmp;

void		write_text_lower(t_bunny_pixelarray *, char *,
				 t_bunny_position *, bool);
void		write_text(t_bunny_pixelarray *, char *, t_bunny_position *);
void		read_pixels(t_texture *, t_bmp, int, int);
t_texture	*load_image(const char *, int);
void		mean_color(t_color *, t_color, float);
void		draw(t_texture *, t_bunny_pixelarray *, t_bunny_position);
void		set_max_heap_size(size_t);
void		transp_blit(t_bunny_pixelarray *,
			    t_bunny_pixelarray *, t_bunny_position);
void		generate_map(void);
void		generate_player(void);

#endif	/* !GRAPHICS_H_ */
