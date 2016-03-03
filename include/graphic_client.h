/*
** graphic_client.h for Tekdoom in /gfx_tekdoom/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Jan 21 13:43:50 2016 Antoine Baché
** Last update Wed Jan 27 07:15:18 2016 Luka Boulagnon
*/

#ifndef GRAPHIC_CLIENT_H_
# define GRAPHIC_CLIENT_H_
# ifndef MAX_CHAT_MSG
#  define MAX_CHAT_MSG 20
# endif /* !MAX_CHAT_MSG */

# include <lapin.h>
# include "tekdoom.h"

/*
** s_tcpc pour le client, il gere les message client/server
*/

typedef	int (**mousetab)(t_data *);

/*
** socket.c
*/

void			g_check_msg_1(t_data *, char *);
void			g_check_msg_2(t_data *, char *);
void			g_check_msg_3(t_data *);
void			glisten_server_more(t_data *, int *);
void			client_init_bool(bool []);
void			ginit_socket(t_data *);
void			*glisten_server(void *);
void			gsend_to_server(t_data *, char *);
void			gcheck_msg(t_data *, char *);
void			send_start(t_data *);
void			display_chat_msg(t_data *);
void			display_cursor(t_data *);

/*
** udp.c
*/

void			*udp_client(void *);
void			send_udpc_server(t_data *, const char *);

/*
** pseudo_handler.c
*/

void			sadd_pseudo(t_data *, char []);
void			sremove_pseudo(t_data *, char []);
int			pseudo_index(t_data *, char *);

/*
** Display received messages
*/

void			left_game_msg(char **, int);
void			joined_game_msg(char **, int);
char			*copy_status(char *, char *);
void			parse_msg(char **, int);
void			write_chat(t_data *);
void			draw_msg(t_data *, int);
void			order_chat_msg(t_data *);

/*
** Prepare client
*/

void			prepare_players(t_data *);
void			prepare_client(t_data *);
void			prepare_window(t_data *);
void			prepare_network(t_data *);
void			prepare_pseudo(t_data *);
t_vertice		pick_random_pos(void);

/*
** GUI
*/

void			free_login(t_login *);
void			set_interface(t_data *);
void			pre_interface(t_bunny_pixelarray *);
void			player_name_global(t_data *);
void			player_name_disp(t_bunny_pixelarray *,
					 t_bunny_window *,
					 t_bunny_position *, char *);
void			transparency_letter(t_bunny_pixelarray *,
					    t_bunny_pixelarray *,
					    t_bunny_position *);
void			status_global(t_data *);
void			status1_text_x(t_bunny_pixelarray *,
				       t_bunny_window *, int);
void			status2_text_x(t_bunny_pixelarray *,
				       t_bunny_window *, int);
void			status3_text_x(t_bunny_pixelarray *,
				       t_bunny_window *, int);
void			status4_text_x(t_bunny_pixelarray *,
				       t_bunny_window *, int);
void			status5_text_x(t_bunny_pixelarray *,
				       t_bunny_window *, int);
void			status6_text_x(t_bunny_pixelarray *,
				       t_bunny_window *, int);
void			status7_text_x(t_bunny_pixelarray *,
				       t_bunny_window *, int);
void			status8_text_x(t_bunny_pixelarray *,
				       t_bunny_window *, int);
void			left_button_text(t_bunny_pixelarray *,
					 t_bunny_window *);
void			right_button_text(t_bunny_pixelarray *,
					  t_bunny_window *);
void			get_keys2(mousetab);
void			get_keys3(mousetab);
void			get_keys4(mousetab);
void			get_keys5(mousetab);
void			free_client(t_data *);
void			button_area(t_data *);
void			chat_area(t_data *);
void			clear_cursor(t_bunny_position *, t_bunny_window *);
void			draw_cursor(t_bunny_position *, t_bunny_window *);
void			cursor(t_data *);
void			player_tab_background(t_bunny_pixelarray *);
void			player_tab_lines(t_bunny_pixelarray *);
void			left_button(t_bunny_pixelarray *);
void			right_button(t_bunny_pixelarray *);
void			background_set(t_bunny_pixelarray *);
void			textbar_set(t_bunny_pixelarray *);
void			chatbox_set(t_bunny_pixelarray *);
mousetab		get_mousefunction(void);
mousetab		get_keys1(void);
int			client(t_data *);
int			do_nothing(t_data *);
int			get_mouse_area(t_data *);
t_bunny_response	client_loop(t_data *);
t_bunny_response	client_key(t_bunny_event_state,
				   t_bunny_keysym, t_data *);
t_bunny_response	client_click(t_bunny_event_state,
				     t_bunny_mousebutton, t_data *);

/*
** Text chat functions
*/

int			print_letter(t_data *, char *);
int			type_a(t_data *);
int			type_b(t_data *);
int			type_c(t_data *);
int			type_d(t_data *);
int			type_e(t_data *);
int			type_f(t_data *);
int			type_g(t_data *);
int			type_h(t_data *);
int			type_i(t_data *);
int			type_j(t_data *);
int			type_k(t_data *);
int			type_l(t_data *);
int			type_m(t_data *);
int			type_n(t_data *);
int			type_o(t_data *);
int			type_p(t_data *);
int			type_q(t_data *);
int			type_r(t_data *);
int			type_s(t_data *);
int			type_t(t_data *);
int			type_u(t_data *);
int			type_v(t_data *);
int			type_w(t_data *);
int			type_x(t_data *);
int			type_y(t_data *);
int			type_z(t_data *);
int			type_backspace(t_data *);
int			type_space(t_data *);
int			type_brackets_open(t_data *);
int			type_brackets_close(t_data *);
int			type_comma(t_data *);
int			type_dot(t_data *);
int			type_question(t_data *);
int			type_enter(t_data *);
int			type_semicolon(t_data *);
int			type_quote(t_data *);
int			type_slash(t_data *);
int			type_backslash(t_data *);
int			type_tilde(t_data *);
int			type_equal(t_data *);
int			type_dash(t_data *);
int			type_add(t_data *);
int			type_multiply(t_data *);
int			type_0(t_data *);
int			type_1(t_data *);
int			type_2(t_data *);
int			type_3(t_data *);
int			type_4(t_data *);
int			type_5(t_data *);
int			type_6(t_data *);
int			type_7(t_data *);
int			type_8(t_data *);
int			type_9(t_data *);
int			(**get_game_keys1(void))(t_data *);
int			can_shot(t_data *data);
int			unset_weapon(t_player *);
void			display_chat(t_data *);
void			game_chat(t_data *);
void			get_game_keys2(mousetab);
void			game_textbar_set(t_bunny_pixelarray *);
int			play_sound(t_data *);

#endif /* !GRAPHIC_CLIENT_H_ */
