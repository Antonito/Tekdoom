/*
** server.c for server main function in /gfx_tekdoom/src/server
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Tue Jan 12 22:56:32 2016 Lucas Troncy
** Last update Mon Jan 25 07:54:42 2016 Lucas Troncy
*/

#include "tekdoom.h"

void			init_socket(t_socket *sock)
{
  int			i;

  i = 0;
  while (i < MAX_CLIENTS)
    {
      sock->cli_sock[i] = 0;
      i++;
    }
  i = 0;
  while (i < 8)
    {
      sock->status[i] = true;
      ++i;
    }
}

int			server_loop(t_socket *sock,
				    struct sockaddr_in addr,
				    fd_set readfds,
				    int run)
{
  char			*all;

  all = malloc(sizeof(char) * MAX_MSG);
  sock->seed = gen_seed();
  while (run && all != NULL)
    {
      FD_ZERO(&readfds);
      FD_SET(sock->main_sock, &readfds);
      sock->cli_nb = sock->main_sock;
      add_child_fd(sock, &readfds, 0);
#ifdef	DEBUG
      printf("nb:%d\n", sock->cli_nb);
#endif
      sock->action = select(sock->cli_nb + 1, &readfds, NULL, NULL, NULL);
      if ((sock->action < 0 && write(2, "Error waiting action\n", 21) != -2) ||
	  (FD_ISSET(sock->main_sock, &readfds) && treat_action(sock, addr) &&
	   write(2, "Cannot add new connection\n", 26) != -2));
      else
	check_msg_leave(sock, all, &readfds);
    }
  free(sock->seed);
  free(all);
  return (0);
}

int			server(t_socket *sock, char *port)
{
  struct sockaddr_in	addr;
  int			i;
  fd_set		readfds;

  i = 1;
  sock->port = port;
  init_socket(sock);
  if ((sock->main_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    write(2, "Cannot create main socket\n", 26);
  if (setsockopt(sock->main_sock,
		 SOL_SOCKET, SO_REUSEADDR, (char *)&i, sizeof(i)) < 0)
    write(2, "Failed to init main socket to handle multiple entries\n", 54);
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(my_getnbr(port));
  if (bind(sock->main_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    write(2, "Bind on main socket failed\n", 27);
  if (listen(sock->main_sock, 2) != 0)
    write(2, "Listen on main socket failed\n", 29);
  return (server_loop(sock, addr, readfds, 1));
}
