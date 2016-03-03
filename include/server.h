/*
** server.h for Tekdoom in /gfx_tekdoom/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 12 22:36:57 2016 Antoine Baché
** Last update Wed Jan 27 02:19:25 2016 Antoine Baché
*/

#ifndef SERVER_H_
# define SERVER_H_
# ifndef MAX_CLIENTS
#  define MAX_CLIENTS 8
# endif /* !MAX_CLIENTS */
# ifndef MAX_MSG
#  define MAX_MSG 40
# endif /* !MAX_MSG */

# include <lapin.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <netinet/in.h>
# include <sys/time.h>
# include "tekdoom.h"

/*
** s_socket pour le server, il gere le tchate est la sync des clients
** avec le lancement des games
*/

typedef struct	s_socket
{
  int		main_sock;
  int		tmp_sock;
  int		cli_sock[MAX_CLIENTS];
  int		cli_nb;
  int		action;
  char		*port;
  char		**pseudo;
  bool		status[8];
  unsigned char	*seed;
  pthread_t	thread;
}		t_socket;

/*
** s_udp pour le server, il gere toutes les postions des clients
*/

typedef struct		s_udps
{
  int			main_sock;
  struct sockaddr_in	tmp_sock;
  int			my_addrl;
  int			cli_addrl;
  int			action;
  struct sockaddr_in	cli_sock[MAX_CLIENTS];
  char			**pseudo;
  char			cli_buff[8][109];
  char			buff[120];
  struct sockaddr_in	my_addr;
  fd_set		readfds;
  struct timeval	ms;
}			t_udps;

/*
** chat_msg.c
*/

void		clear_serv_msg(char *);
int		write_message(char *, char *);

/*
** player_assignation.c
*/

int		accept_player(int, char *);
int		accept_master(int, char *);
int		room_full(int, char *);
int		pseudo_exists(int, char *);

/*
** socket.c
*/

void		socket_send_msg_all(t_socket *, char *);
void		socket_send_seed_all(t_socket *, unsigned char *);
void		socket_send_player_all(t_socket *, t_player *);
int		socket_send_msg(int, char *);
int		socket_send_player(int, t_player *);
void		socket_send_player_debug(t_player *);

/*
** socket.c
*/

void		send_list_cli(t_socket *, int, char *);

/*
** server.c
*/

int		server(t_socket *, char *);
void		init_socket(t_socket *);
int		server_loop(t_socket *, struct sockaddr_in, fd_set, int);

/*
** server_functions.c
*/

void		add_child_fd(t_socket *, fd_set *, int);
int		treat_action(t_socket *, struct sockaddr_in);
int		check_msg_leave(t_socket *, char *, fd_set *);

/*
** pseudo_handler.c
*/

char		**add_pseudo(char **, char []);
int		compare_pseudo(char **, char []);
int		check_pseudo(t_socket *, char []);
void		remove_pseudo(char **, int);
void		remove_pseudoc(char **, char *);
int		nb_pseudo(t_socket *);
int		nb_pseudo_udp(t_udps *);

/*
** client_test/chat.c
*/

void		str_to_sock(char *, char *, char *);

/*
** udp.c
*/

void		*udp_thread(void *);
void		udp_loop(t_socket *, t_udps *);

/*
** udp_function.c
*/

void		udp_check_msg(t_udps *);
void		udp_update_buff(t_udps *);
void		udp_check_pseudo(t_udps *);
void		udp_send_all(t_udps *);

/*
** udp_other.c
*/

void		set_ms(t_udps *);
void		init_udp(t_udps *);

/*
** udp_msg_tools.c
*/

void		infos_to_udp(t_player *, char *);
void		infos_to_udp_add(char *);
void		infos_to_udp_vector(char *);
void		infos_to_udp_add_vec(t_vector *, char *, int);
int		check_udp_msg(char *);

/*
** udp_msg_tools2.c
*/

void		udp_to_infos_vec(t_vector *, char *, char *, int);
void		udp_to_infos_pos(t_pos *, char *, char *, int);
int		udp_to_infos(t_player *, char *);
int		check_udp(char *);

/*
** gen_seed.c
*/

unsigned char	*gen_seed(void);

#endif /* !SERVER_H_ */
