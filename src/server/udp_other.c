/*
** udp_other.c for func for set udp in /home/lokoum/prog/tekdoom_dev
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Tue Jan 26 04:42:23 2016 Lucas Troncy
** Last update Tue Jan 26 23:20:51 2016 Lucas Troncy
*/

#include "tekdoom.h"

void	set_ms(t_udps *udp)
{
  udp->ms.tv_usec = 15000;
  udp->ms.tv_sec = 2;
}

void	init_udp(t_udps *udp)
{
  set_ms(udp);
  if ((udp->pseudo = malloc(sizeof(char *))) == NULL)
    write(2, "Oops I'll segfault LMAO\n", 24);
  udp->pseudo[0] = NULL;
}
