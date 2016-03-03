/*
** udp_functions.c for udp functions clent in /home/lokoum/prog/tekdoom_dev
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Mon Jan 25 21:32:47 2016 Lucas Troncy
** Last update Tue Jan 26 19:21:57 2016 Lucas Troncy
*/

#include "tekdoom.h"

void		send_udpc_server(t_data *data, const char *msg)
{
  int		addrl;

  addrl = sizeof(data->udp.server);
  if (data->udp.sock != 0)
    {
      sendto(data->udp.sock, msg, 120, 0,
	     (struct sockaddr *)&data->udp.server, addrl);
    }
}
