/*
** menu.h for tekdoom in /home/asphahyre/rendu/tekdoom_dev/include
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Wed Jan 13 09:45:38 2016 Luka Boulagnon
** Last update Thu Jan 28 14:48:35 2016 Antoine Baché
*/

#ifndef MENU_H_
# define MENU_H_
# ifndef LOOP
#  define LOOP 1
# endif /* !LOOP */
# ifndef CLICK
#  define CLICK 2
# endif /* !CLICK */
# ifndef HOVER
#  define HOVER 4
# endif /* !HOVER */
# ifndef JOYSTICK
#  define JOYSTICK 8
# endif /* !JOYSTICK */
# ifndef KEY
#  define KEY 16
# endif /* !KEY */

# include "tekdoom.h"

typedef struct		s_lst
{
  char			*text;
  int			hover;
  struct s_lst		*next;
  t_bunny_pixelarray	*background;
  t_bunny_position	pos;
  t_bunny_response	(*action)(void *, int type);
}			t_lst;

typedef struct		s_config
{
  int			oculus;
}			t_config;

typedef struct		s_coord
{
  int			x;
  int			y;
  int			z;
}			t_coord;

typedef struct		s_camera
{
  float			orientation[3];
  t_coord		pos;
}			t_camera;

typedef struct		s_params
{
  int			fullscreen;
  int			glitch;
  int			sound_toggle;
  int			timer;
  t_bunny_music		*intro_sound;
  t_bunny_music		*load_sound;
  t_bunny_music		*loop_sound;
  t_bunny_music		*menu_sound;
  t_bunny_music		*rick_roll;
  t_bunny_pixelarray	*background;
  t_bunny_pixelarray	*message_bg;
  t_bunny_pixelarray	*game_bg;
  t_bunny_pixelarray	*option;
  t_bunny_position	cur_pos;
  t_bunny_position	origin;
  t_bunny_response	(*current)(void *, int);
  t_bunny_response	again;
  t_bunny_window	*window;
  t_lst			*menu_buttons;
  t_lst			*connect_buttons;
  t_config		config;
  char			*n_frame;
  int			intro_volume;
  int			curr_opacity;
  char			*message;
  t_data		*data;
}			t_params;

typedef struct		s_key
{
  t_bunny_keysym	key;
  t_bunny_event_state	state;
  t_params		*params;
}			t_key;

typedef struct		s_click
{
  t_bunny_event_state	state;
  t_bunny_mousebutton	button;
  t_params		*params;
}			t_click;

void			set_inprt_text(t_key *, t_msg *, int *);
void			set_inme_text(t_key *, t_msg *, int *);
void			set_inaddr_text(t_key *, t_msg *, int *);
t_bunny_response	main_loop(void *);
t_bunny_response	main_click(t_bunny_event_state, t_bunny_mousebutton,
				   void *);
t_bunny_response	connecting(void *, int);
t_bunny_response	main_move(const t_bunny_position *, void *);
t_bunny_response	main_key(t_bunny_event_state, t_bunny_keysym, void *);
int			tekdoom(void);
void			init_params(t_params *);
void			init_player(t_player *);
int			set_message(char *, t_params *);
void			set_square(t_bunny_position , t_bunny_pixelarray *,
				   int, int);
void			blit(t_bunny_buffer *, t_bunny_pixelarray *,
			     t_lst *, int);
void			set_pix_clr(t_color *, unsigned int, float);
void			notification(t_bunny_pixelarray *, char *);
t_color			*get_pixel(t_bunny_pixelarray *, int, int);
void			mean_color(t_color *, t_color, float);
void			parall(t_bunny_pixelarray *, unsigned int);
void			coloring(t_bunny_pixelarray *, unsigned int);
void			draw(t_texture *, t_bunny_pixelarray *,
			     t_bunny_position);
t_color			get_pix(t_texture *, int, int);
t_bunny_pixelarray	*copy(t_bunny_pixelarray *cd);
void			draw_up(t_bunny_pixelarray *,
				float *, t_color *);
void			draw_down(t_bunny_pixelarray *,
				  float *, t_color *);
void			draw_line_game(t_bunny_pixelarray *,
				  t_bunny_position, t_bunny_position,
				  t_color *);
void			line(t_bunny_pixelarray *,
			     t_bunny_position,
			     t_bunny_position, t_color *);
void			init_camera(t_camera *);
void			init_textures(t_texture ***);
void			init_musics(t_params *);
void			opacity(t_bunny_pixelarray *,
				unsigned char);
void			mean_col(t_color *, t_color, float);
t_texture		*load_image(const char *, int);
void			set_pix_four(t_texture *,
				     t_bunny_pixelarray *,
				     t_bunny_position,
				     t_bunny_position);
void			draw_video(t_texture *,
				   t_bunny_pixelarray *,
				   t_bunny_position);
t_bunny_response	dont_click_4(void *, int);
t_bunny_response	dont_click_3(void *, int);
t_bunny_response	dont_click_2(void *, int);
t_bunny_response	dont_click(void *, int);
t_lst			*new_button(char *, int, int,
				    t_bunny_response (*func)(void *, int));
void			add_button(char *, t_lst *,
				   t_bunny_response (*func)(void *, int));
void			disp_elems(t_params *, t_lst *);
void			next_elem(t_lst *);
void			prev_elem(t_lst *);
t_bunny_response	menu(void *, int);
t_bunny_response	connect_srv(void *, int);
void			print_banner(t_bunny_pixelarray *, t_texture *, int);
t_bunny_response	set_oculus(void *, int);
t_bunny_response	goto_menu(void *, int);
t_bunny_response	(*get_action_by_hover(t_lst *, t_bunny_response
					      (*func)
					      (void *, int)))(void *, int);
t_bunny_response	dont_click_6(void *, int);
t_bunny_response	dont_click_5(void *, int);
t_bunny_response	rick_roll(void *, int);
t_bunny_response	rick_roll(void *, int);
t_bunny_response	set_rick_roll(void *, int);
t_bunny_response	intro(void *, int);
void			init_buttons(t_lst **);
void			init_connect(t_lst **);
void			glitch_line(t_bunny_pixelarray *,
				    t_bunny_pixelarray *, int *, int);
void			glitch_colors(t_bunny_pixelarray *,
				      t_bunny_pixelarray *, int *, int);
t_bunny_pixelarray	*glitch(t_bunny_pixelarray *);
int			tekdoom(void);
t_bunny_response	exit_game(void *, int);
t_bunny_response	loop(void *);
void			err(char *);
t_bunny_response	rebind(void *, int);
t_bunny_response	input_address(void *, int);
t_bunny_response	input_port(void *, int);
t_bunny_response	input_pseudo(void *, int);
void			set(mousetab *, int *, t_lst *);
int			menu_type_a(t_data *);
int			menu_type_b(t_data *);
int			menu_type_c(t_data *);
int			menu_type_d(t_data *);
int			menu_type_e(t_data *);
int			menu_type_f(t_data *);
int			menu_type_g(t_data *);
int			menu_type_h(t_data *);
int			menu_type_i(t_data *);
int			menu_type_j(t_data *);
int			menu_type_k(t_data *);
int			menu_type_l(t_data *);
int			menu_type_m(t_data *);
int			menu_type_n(t_data *);
int			menu_type_o(t_data *);
int			menu_type_p(t_data *);
int			menu_type_q(t_data *);
int			menu_type_r(t_data *);
int			menu_type_s(t_data *);
int			menu_type_t(t_data *);
int			menu_type_u(t_data *);
int			menu_type_v(t_data *);
int			menu_type_w(t_data *);
int			menu_type_x(t_data *);
int			menu_type_y(t_data *);
int			menu_type_z(t_data *);
int			menu_type_backspace(t_data *);
int			menu_type_space(t_data *);
int			menu_type_brackets_open(t_data *);
int			menu_type_brackets_close(t_data *);
int			menu_type_comma(t_data *);
int			menu_type_dot(t_data *);
int			menu_type_question(t_data *);
int			menu_type_enter(t_data *);
int			menu_type_semicolon(t_data *);
int			menu_type_quote(t_data *);
int			menu_type_slash(t_data *);
int			menu_type_backslash(t_data *);
int			menu_type_tilde(t_data *);
int			menu_type_equal(t_data *);
int			menu_type_dash(t_data *);
int			menu_type_add(t_data *);
int			menu_type_multiply(t_data *);
int			menu_type_0(t_data *);
int			menu_type_1(t_data *);
int			menu_type_2(t_data *);
int			menu_type_3(t_data *);
int			menu_type_4(t_data *);
int			menu_type_5(t_data *);
int			menu_type_6(t_data *);
int			menu_type_7(t_data *);
int			menu_type_8(t_data *);
int			menu_type_9(t_data *);
t_bunny_response	menu_mouse(void *);
t_bunny_response	menu_click(void *);
mousetab		menu_get_keys1(void);
void			menu_get_keys2(mousetab);
void			menu_get_keys3(mousetab);
void			menu_get_keys4(mousetab);
void			menu_get_keys5(mousetab);
int			menu_print_letter(t_data *, char *);

#endif /* !MENU_H_ */
