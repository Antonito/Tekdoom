/*
** udp_function.c for udp functions in /home/lokoum/prog/tekdoom_dev
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Sun Jan 24 03:00:55 2016 Lucas Troncy
** Last update Wed Jan 27 02:20:01 2016 Lucas Troncy
*/

#include "tekdoom.h"

void		udp_check_msg(t_udps *udp)
{
  if (udp->buff[0] == '/')
    udp_check_pseudo(udp);
  else
    udp_update_buff(udp);
}

void		udp_update_buff(t_udps *udp)
{
  int		i;

  i = -1;
  while (udp->pseudo[++i] != NULL)
    {
      if (my_strncmp(udp->pseudo[i], &udp->buff[4], 14) == 0)
	{
	  my_strncpy(udp->cli_buff[i], udp->buff, 109);
	  break;
	}
    }
}

void		udp_check_pseudo(t_udps *udp)
{
  if (udp->buff[1] == 'a')
    {
      udp->pseudo = add_pseudo(udp->pseudo, &udp->buff[5]);
      udp->cli_sock[nb_pseudo_udp(udp)] = udp->tmp_sock;
    }
  if (udp->buff[1] == 'r')
    {
      remove_pseudoc(udp->pseudo, udp->buff);
      write(1, "Fuck YOU, dont leave\n", 21);
    }
}

void		udp_send_all(t_udps *udp)
{
  int		i;
  int		j;

  i = -1;
  while (udp->pseudo[++i] != NULL)
    {
      j = -1;
      while (++j < 8)
	{
	  sendto(udp->main_sock, &udp->buff[j], 109, 0,
		 (struct sockaddr *)&udp->cli_sock[i], udp->cli_addrl);
	}
    }
}
