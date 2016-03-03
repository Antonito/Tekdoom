/*
** socket2.c for socket functions two in /home/lokoum/prog/tekdoom_dev
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Tue Jan 19 20:15:16 2016 Lucas Troncy
** Last update Wed Jan 27 02:18:50 2016 Lucas Troncy
*/

#include "tekdoom.h"

void		send_list_cli(t_socket *sock, int fd, char *pseudo)
{
  int		i;
  char		tmp[24];

  i = -1;
  while (sock->pseudo[++i] != NULL)
    {
      if (my_strncmp(pseudo, sock->pseudo[i], my_strlen(sock->pseudo[i])) == 0)
	continue;
      my_strncpy(tmp, "/a ", 3);
      tmp[3] = '\0';
      my_strncat(tmp, sock->pseudo[i], my_strlen(sock->pseudo[i]));
      write(fd, tmp, my_strlen(tmp));
    }
}
