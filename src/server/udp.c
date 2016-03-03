/*
** udp.c for udp functions in /home/lokoum/prog/tekdoom_dev
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Wed Jan 20 10:11:34 2016 Lucas Troncy
** Last update Wed Jan 27 06:11:11 2016 Antoine Baché
*/

#include "tekdoom.h"

void			*udp_thread(void *data)
{
  t_udps		udp;
  t_socket		*sock;
  int			i;

  i = 1;
  sock = (t_socket *)data;
  if ((udp.main_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 1)
    {
      write(2, "Failed to create UDP main socket\n", 33);
      return ((void *)0);
    }
  if (setsockopt(udp.main_sock,
		 SOL_SOCKET, SO_REUSEADDR, (char *)&i, sizeof(i)) < 0)
    write(2, "Failed to init main UDP socket to handle multiple entries\n",
	  58);
  udp.my_addr.sin_family = AF_INET;
  udp.my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  udp.my_addr.sin_port = htons(my_getnbr(sock->port) + 1);
  udp.my_addrl = sizeof(udp.my_addr);
  if (bind(udp.main_sock, (struct sockaddr *)&udp.my_addr, udp.my_addrl) < 0)
    write(2, "bind on UDP failed\n", 19);
  udp_loop(sock, &udp);
  return ((void *)0);
}

void		udp_loop(UNUSED t_socket *sock, t_udps *udp)
{
  int			len;

  udp->cli_addrl = sizeof(udp->tmp_sock);
  init_udp(udp);
  len = 1;
  while (len)
    {
      FD_ZERO(&udp->readfds);
      FD_SET(udp->main_sock, &udp->readfds);
      udp->action = select(udp->main_sock + 1, &udp->readfds, NULL,
			   NULL, &udp->ms);
      if (udp->action > 0)
	{
	  len = recvfrom(udp->main_sock, udp->buff, 120, 0,
			 (struct sockaddr *)&udp->tmp_sock, (socklen_t *)&udp->cli_addrl);
	  udp->buff[len] = '\0';
	  udp_check_msg(udp);
	}
      if (udp->ms.tv_usec <= 0 && udp->ms.tv_sec <= 0)
	{
	  set_ms(udp);
	  udp_send_all(udp);
	}
    }
}
