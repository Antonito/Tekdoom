/*
** common_structs.h for Tekdoom in /gfx_tekdoom/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 03:04:27 2016 Antoine Baché
** Last update Sat Feb 13 14:26:08 2016 Antoine Baché
*/

#ifndef COMMON_STRUCTS_H_
# define COMMON_STRUCTS_H_

# include <lapin.h>
# include <stdint.h>
# include "server.h"

struct			s_vector
{
  double		x;
  double		y;
  double		z;
  double		w;
  double		light;
};

typedef	t_vector	t_vertice;
typedef	t_vector	t_position;
typedef	t_vector	t_rotation;

struct			s_pos
{
  t_vector		dir;
  t_vector		vec;
};

typedef struct		s_msg
{
  char			msg[200];
  unsigned char		indice;
  unsigned char		indice_foreign;
  bool			rec;
  char			**foreign;
  bool			master;
}			t_msg;

typedef struct		s_weapon
{
  bool			is_selected;
  int			load;
  int			power;
  int			remaining;
  t_bunny_pixelarray	*shot;
  t_bunny_pixelarray	*texture;
  t_bunny_sound		*sound;
}			t_weapon;

typedef struct		s_polygon
{
  t_vertice		*a;
  t_vertice		*b;
  t_vertice		*c;
  unsigned char		clip_type;
  unsigned char		color;
  double		light;
}			t_polygon;

typedef struct		s_face
{
  int			a;
  int			b;
  int			c;
  unsigned char		color;
}			t_face;

typedef struct		s_object
{
  int			nb_vertex;
  int			nb_polygons;
  t_vertice		*vertex;
  t_polygon		*polygons;
}			t_object;

typedef struct		s_bullet
{
  t_position		pos;
  t_vector		dir;
  int			velocity;
  char			shooter[20];
}			t_bullet;

typedef struct		s_object_container
{
  t_object		transform;
  t_object		polygons;
  t_object		original;
  t_object		projected;
  bool			shadow_utd;
  t_position		pos;
  t_rotation		rot;
  struct s_object_container	*next;
}			t_object_container;

struct			s_player
{
  char			name[20];
  char			life;
  t_vector		movement;
  bool			status;
  t_pos			pos;
  int32_t		events;
  double		rotate[2];
  double		roll;
  t_object_container	*object;
  t_weapon		rifle;
  t_weapon		gun;
  t_weapon		knife;
};

typedef struct		s_light
{
  t_vertice		pos;
  double		radius;
  struct s_light	*next;
}			t_light;

typedef struct		s_world
{
  char			name[32];
  char			path[32];
  t_object_container	*objects;
  t_player		*player;
  t_light		*lights;
  t_vertice		*spawn_player;
  t_vertice		*spawn_packs;
  t_object_container	*pack1;
  t_object_container	*pack2;
}			t_world;

typedef struct		s_tcpc
{
  int			sock;
  pthread_t		thread;
  struct sockaddr_in	server;
  int			run;
  char			msg[MAX_MSG];
  unsigned char		seed[64];
}			t_tcpc;

typedef struct		s_udpc
{
  pthread_t		thread;
  struct sockaddr_in	server;
  int			sock;
  char			msg[MAX_MSG];
}			t_udpc;

typedef struct		s_login
{
  char			*ip;
  char			*port;
}			t_login;

typedef struct		s_interface
{
  t_bunny_pixelarray	*map;
  t_bunny_pixelarray	*chat;
  t_bunny_pixelarray	*life;
  t_bunny_pixelarray	*weapon;
  t_bunny_pixelarray	*crosshair;
}			t_interface;

typedef struct		s_bitfield
{
  int			shot : 1;
  int			shoting : 1;
  int			pack1 : 1;
  int			pack2 : 1;
  int			w : 1;
  int			alive : 1;
  int			dmg : 5;
  int			stab : 1;
  int			weapon : 2;
  int			music : 1;
}			t_bitfield;

typedef union		u_event
{
  t_bitfield		bits;
  short			event;
}			t_event;

typedef struct		s_data
{
  bool			chat_toggle;
  bool			show_chat;
  int			(**keys)(struct s_data *);
  int			(**mouse_click)(struct s_data *);
  int			count;
  int			cursor_toggle;
  int			fullscreen : 1;
  int			max_chat;
  t_area		area;
  t_bunny_pixelarray	*blur;
  t_bunny_pixelarray	*pix;
  t_bunny_position	*mouse_pos;
  t_bunny_position	cursor_pos;
  t_bunny_sound		*soundtrack;
  t_bunny_window	*win;
  t_event		event;
  t_interface		interface;
  t_login		*login;
  t_msg			message;
  t_player		player[8];
  t_tcpc		sock;
  t_udpc		udp;
}			t_data;

typedef struct		s_wire
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_world		*world;
  t_data		*data;
  double		*zbuf;
  int			nb_models;
  double		project_mtx[16];
  int			selected;
}			t_wire;

#endif /* !COMMON_STRUCTS_H_ */
