/*
** udp.c for udp functions in /home/lokoum/prog/tekdoom_dev
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Sat Jan 23 20:33:00 2016 Lucas Troncy
** Last update Wed Jan 27 07:45:07 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void		udpc_loop(t_data *data)
{
  int		len;
  unsigned int	addrl;
  char		tmp[121];

  my_strncpy(tmp, "/a ", 3);
  tmp[3] = '\0';
  my_strncat(tmp, data->player[0].name, my_strlen(data->player[0].name));
  addrl = sizeof(data->udp.server);
  sendto(data->udp.sock, tmp, my_strlen(tmp),
	 0, (struct sockaddr *)&data->udp.server, addrl);
  while (data->sock.run)
    {
      len = recvfrom(data->udp.sock, tmp, 120, 0,
		     (struct sockaddr *)&data->udp.server, &addrl);
      if (len == 0)
	data->sock.run = 0;
      data->udp.msg[len] = '\0';
    }
}

void			*udp_client(void *datb)
{
  t_data		*data;

  data = (t_data *)datb;
  if ((data->udp.sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 1)
    {
      write(2, "Failed to create UDP client\n", 28);
      return ((void *)0);
    }
  data->udp.server.sin_family = AF_INET;
  data->udp.server.sin_port = htons(my_getnbr(data->login->port) + 1);
  data->udp.server.sin_addr.s_addr = inet_addr(data->login->ip);
  udpc_loop(data);
  return ((void *)0);
}
