/*
** server_functions.c for server functions in /gfx_tekdoom/src/server
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Tue Jan 12 23:28:59 2016 Lucas Troncy
** Last update Tue Jan 26 07:26:51 2016 Antoine Baché
*/

#include "tekdoom.h"

void		notify_all(t_socket *sock, char *pseudo, int todo)
{
  char		tmp[24];

  tmp[0] = 0;
  if (todo == 1)
    my_strncpy(tmp, "/a ", 3);
  else if (todo == 2)
    my_strncpy(tmp, "/r ", 3);
  else
    my_strncpy(tmp, "/s ", 3);
  tmp[3] = '\0';
  if (pseudo != NULL)
    {
      my_strncat(tmp, pseudo, my_strlen(pseudo));
      socket_send_msg_all(sock, tmp);
    }
}

void		add_child_fd(t_socket *sock, fd_set *readfds, int tmp)
{
  int		i;

  i = -1;
  while (++i < MAX_CLIENTS)
    {
      tmp = sock->cli_sock[i];
      if (tmp > 0)
	FD_SET(tmp, readfds);
      if (tmp > sock->cli_nb)
	sock->cli_nb = tmp;
    }
}

int		treat_action(t_socket *sock,
			     struct sockaddr_in addr)
{
  int		i;
  int		addrl;
  char		buff[21];

  addrl = sizeof(addr);
  if ((sock->tmp_sock = accept(sock->main_sock,
			       (struct sockaddr *)&addr,
			       (socklen_t *)&addrl)) < 0)
    write(2, "Accept new connection failed\n", 29);
  i = read(sock->tmp_sock, buff, 20);
  buff[i] = '\0';
  if ((i = -1) && check_pseudo(sock, buff) == -1)
    return (-1);
  if (write(1, buff, my_strlen(buff)) < 0 ||
      write(1, " is now connected\n", 18) < 0)
    return (-1);
  while (++i < MAX_CLIENTS)
    if (sock->cli_sock[i] == 0 && !(sock->status[i] = 0))
      {
	sock->cli_sock[i] = sock->tmp_sock;
	send_list_cli(sock, sock->cli_sock[i], sock->pseudo[i]);
	notify_all(sock, sock->pseudo[i], 1);
	break;
      }
  return (0);
}

void		close_sock(t_socket *sock, int i)
{
  notify_all(sock, sock->pseudo[i], 2);
  write(1, sock->pseudo[i], my_strlen(sock->pseudo[i]));
  write(1, " has quit\n", 10);
  close(sock->cli_sock[i]);
  sock->cli_sock[i] = 0;
#ifdef	DEBUG
  printf("indexed:%d\n", i);
#endif
  if (sock->pseudo[i] == NULL)
    write(1, "NULLED\n", 7);
  remove_pseudoc(sock->pseudo, sock->pseudo[i]);
  while (i + 1 < MAX_CLIENTS)
    {
      sock->cli_sock[i] = sock->cli_sock[i + 1];
      ++i;
    }
  write(1, "closeSockEnded\n", 15);
}

int		check_msg_leave(t_socket *sock,
				char *all,
				fd_set *readfds)
{
  int		i;
  int		len;

  i = -1;
  while (++i < MAX_CLIENTS)
    if (FD_ISSET(sock->cli_sock[i], readfds))
      {
	len = read(sock->cli_sock[i], all, MAX_MSG - 1);
	all[len] = '\0';
	if (len == 0)
	    close_sock(sock, i);
	else
	  {
	    if (my_strncmp(all, "/start ", 7) == 0 &&
		my_strncmp(sock->pseudo[0], &all[7],
			   my_strlen(sock->pseudo[0])) == 0)
	      socket_send_seed_all(sock, sock->seed);
	    else
	      socket_send_msg_all(sock, all);
	  }
      }
  return (0);
}
