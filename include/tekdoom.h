/*
** tekdoom.h for Tekdoom in /gfx_tekdoom/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 11 20:32:49 2016 Antoine Baché
** Last update Thu Jan 28 13:43:22 2016 Antoine Baché
*/

#ifndef	TEKDOOM_H_
# define TEKDOOM_H_
# define LAPIN_ALLOCATOR_DEACTIVATED
# define UNUSED __attribute__((unused))
# define PACKED __attribute__((packed))
# ifndef WIN_X
#  define WIN_X 1280
# endif	/* !WIN_X */
# ifndef WIN_Y
#  define WIN_Y 720
# endif	/* !WIN_Y */
# define MOUSE_BUTTONS 6
# define KEY_BUTTONS 101
# define MAX_PLAYER 8
# define _DEFAULT_SOURCE_
# define STANDARD_RIGHTS S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
# define NB_OBJ 8
# define ZNEAR 0
# define ZFAR 10000
# ifndef MAX_COUNT
#  define MAX_COUNT 510510
# endif
# ifndef FOV
#  define FOV 45
# endif /* !FOV */
# define MIN(A, B) (((A) <= (B)) ? (A) : (B))
# define MAX(A, B) (((A) >= (B)) ? (A) : (B))
# define ABS(A) (A >= 0 ? (A) : -(A))
# define ROUND(A) (((int)(A) - (A) < 0.5) ? (int)(A) : (int)(A) + 1)
# define SIZE_TRIGO_TAB 3600
# ifndef SKY_COLOR
#  define SKY_COLOR 0xFFFFDD00
# endif /* !SKY_COLOR */
# define PYTHA(A, B) (sqrt((A) * (A) + (B) * (B)))
# define POW2(N) ((N) * (N))
# define POW3(N) ((N) * (N) * (N))

typedef enum		e_area
  {
    CHATBOX		= 0,
    TEXTBOX		= 1,
    PLAYBUTTON		= 2,
    EXITBUTTON		= 3,
    OTHER		= 4
  }			t_area;

typedef struct s_player	t_player;
typedef struct s_vector	t_vector;
typedef struct s_pos	t_pos;

# ifdef	DEBUG
#  include <stdio.h>
# endif /* DEBUG */
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdint.h>
# include <lapin.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include <pthread.h>
# include "my_errno.h"
# include "tools.h"
# include "common_structs.h"
# include "server.h"
# include "graphics.h"
# include "graphic_client.h"
# include "menu.h"

int			init_game(t_data *);
int			init_texture_game(t_data *);
int			game_display(t_data *);
int			game_loop(t_data *);
t_bunny_response	game_click(t_bunny_event_state, t_bunny_mousebutton,
				   t_wire *);
t_bunny_response	game_key(t_bunny_event_state, t_bunny_keysym,
				 t_data *);
t_bunny_response	main_game_loop(t_data *);
t_bunny_response	game_wheel(int, int, t_wire *);
t_bunny_response	set_fullscreen(void *, int);

/*
** Interface
*/

void			display_interface(t_data *);
void			display_minimap(t_data *);
void			display_life(t_data *);
void			display_weapon(t_data *);
void			display_crosshair(t_data *);
void			display_game_chat(t_data *);
t_world			*map_loader(const char *);

/*
** backface.c
*/

void			backface(t_object *);
void			clear_zbuf(double *);
int			is_backface(t_polygon *);
int			is_cliped(t_polygon *, double);

/*
** draw_chunk.c
*/

void			draw_chunk(t_bunny_pixelarray *, t_object *, double *);

/*
** draw_polygon.c
*/

void			draw_line(t_bunny_pixelarray *, t_vertice *,
				  double *zbuf, unsigned int);
int			draw_polygon(t_bunny_pixelarray *,
				     t_polygon *, double *);
int			draw_triangle(t_bunny_pixelarray *pi,
				      t_polygon *, double *);
void			*draw_triangle_top(t_bunny_pixelarray *,
					   t_polygon *,
					   double *, double *);
void			*draw_triangle_bot(t_bunny_pixelarray *,
					   t_polygon *p,
					   double *, double *);
void			*_start_draw_triangle(void *);
int			teklineh(t_bunny_pixelarray *, t_position *,
				 unsigned int, double *);
void			tekpixel(t_bunny_pixelarray *, int, int, unsigned int);

/*
** get_line.c
*/

unsigned int		get_color(unsigned int, double);
unsigned int		get_full_color(unsigned char);
void			get_line(t_polygon *, double *, double, t_vertice *);
void			set_palette(unsigned int *);

/*
** get_triangle.c
*/

void			get_triangle(t_polygon *, t_polygon *);
void			swap_vert(t_vertice **, t_vertice **);
void			swap_vert2(t_vertice *, t_vertice *);

/*
** L2V.c
*/

void			view_to_projection(t_object *, double *);
void			world_to_view(t_object *, t_object *, double *);

/*
** launch_doom.c
*/

t_bunny_response	doom_loop(t_wire *);
int			launch_doom(t_wire *, t_data *);
t_bunny_response	my_escape(t_bunny_event_state,
				  t_bunny_keysym, t_wire *);
void			my_move(const t_bunny_position *,
				t_wire *);
int			prepare_gfx(t_wire *, t_data *);

/*
** load_map.c
*/

int			load_map(t_wire *);

/*
** main.c
*/

void			free_doom(t_wire *);

/*
** matrix.c
*/

void			mtx_clear(double *);
void			mtx_cpy(double *, double *);
void			mtx_mult_mult(double *, double *);
void			*mtx_col(void *);
void			mtx_mult_mtx_dest(double *, double *, double *);

/*
** matrix2.c
*/

void			mtx_mult_vtx(double *, t_vertice *);
void			mtx_mult_vtx_dest(double *, t_vertice *,
					  t_vertice *);
void			set_camera_mtx(double *, t_vector *,
				       t_vector *, double);

/*
** my_bunny.c
*/

t_bunny_pixelarray	*my_bunny_load_pixelarray(char *);
t_bunny_pixelarray	*my_bunny_new_pixelarray(int, int);
t_bunny_window		*my_bunny_start(int, int, bool, char *);

/*
** my_puterr.c
*/

void			my_puterr(char *, char *);

/*
** recalc_dir.c
*/

void			recalc_dir(t_vector *, double *);

/*
** rotate_cam.c
*/

void			normalize(t_vector *);
void			rotate_cam_x(t_vector *, double);
void			rotate_cam_y(t_vector *, double);

/*
** set_frame.c
*/

int			set_frame(t_wire *);

/*
** set_proj_mtx.c
*/

void			set_proj_mtx(double *);

/*
** set_shadow.c
*/

void			cp_light(t_object *, t_object *);
void			set_shadow(t_object *, t_light *);
void			set_shadow_vertex(t_vertice *, t_light *);
void			set_shadow_polygons(t_polygon *, t_light *);

/*
** tekfill.c
*/

void			tekfill(t_bunny_pixelarray *, unsigned int);

/*
** trigo.c
*/

double			my_cos(double);
double			my_sin(double);
double			my_tan(double);
void			set_trigo(void);

/*
** vector.c
*/

void			cross_vector(t_vector *, t_vector *, t_vector *);
double			cross_vector_val(t_vector *, t_vector *);
void			polygon_center(t_polygon *, t_vertice *);
void			vectorize(t_vertice *, t_vertice *, t_vector *);
double			vector_len(t_vector *);
int			map_load_headers(t_world *, const char *);
t_world			*map_loader(const char *);
void			load_chunk(t_world *, t_bunny_position);
void			write_foo_map(const char *);
int			load_object_(t_object *, char *);
char			*my_putnbr_str(int);
char			*my_strcat_int(char *, int);
char			*my_strcat(char *, char *);
char			*my_strdup(char *);
int			load_full_game(t_wire *);
void			apply_move(t_player *);
int			load_object(char *, t_object_container *);
int			load_object_(t_object *, char *);
int			start_engine(t_data *);
int			type_game_a(t_data *);
int			type_game_b(t_data *);
int			type_game_c(t_data *);
int			type_game_d(t_data *);
int			type_game_e(t_data *);
int			type_game_f(t_data *);
int			type_game_g(t_data *);
int			type_game_h(t_data *);
int			type_game_i(t_data *);
int			type_game_j(t_data *);
int			type_game_k(t_data *);
int			type_game_l(t_data *);
int			type_game_m(t_data *);
int			type_game_n(t_data *);
int			type_game_o(t_data *);
int			type_game_p(t_data *);
int			type_game_q(t_data *);
int			type_game_r(t_data *);
int			type_game_s(t_data *);
int			type_game_t(t_data *);
int			type_game_u(t_data *);
int			type_game_v(t_data *);
int			type_game_w(t_data *);
int			type_game_x(t_data *);
int			type_game_y(t_data *);
int			type_game_z(t_data *);
int			type_game_backspace(t_data *);
int			type_game_space(t_data *);
int			type_game_brackets_open(t_data *);
int			type_game_brackets_close(t_data *);
int			type_game_comma(t_data *);
int			type_game_dot(t_data *);
int			type_game_question(t_data *);
int			type_game_enter(t_data *);
int			type_game_semicolon(t_data *);
int			type_game_quote(t_data *);
int			type_game_slash(t_data *);
int			type_game_backslash(t_data *);
int			type_game_tilde(t_data *);
int			type_game_equal(t_data *);
int			type_game_dash(t_data *);
int			type_game_add(t_data *);
int			type_game_multiply(t_data *);
int			type_game_0(t_data *);
int			type_game_1(t_data *);
int			type_game_2(t_data *);
int			type_game_3(t_data *);
int			type_game_4(t_data *);
int			type_game_5(t_data *);
int			type_game_6(t_data *);
int			type_game_7(t_data *);
int			type_game_8(t_data *);
int			type_game_9(t_data *);
int			print_game_letter(t_data *, char *);
mousetab		get_game_keys1(void);
void			get_game_keys2(mousetab);
void			get_game_keys3(mousetab);
void			get_game_keys4(mousetab);
void			get_game_keys5(mousetab);
void			order_chat_msg_game(t_data *);
void			display_chat_msg_game(t_data *);
void			draw_msg_game(t_data *, int);
void			inaddr_text_add(t_key *, t_key *);
void			inprt_text_add(t_key *, t_key *);
void			gun_selected(t_data *, int);

#endif	/* !TEKDOOM_H_ */
