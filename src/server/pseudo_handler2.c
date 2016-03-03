/*
** pseudo_handler2.c for check if server is full in /gfx_tekdoom/
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Sun Jan 24 01:06:51 2016 Lucas Troncy
** Last update Tue Jan 26 05:01:22 2016 Lucas Troncy
*/

#include "tekdoom.h"

int		nb_pseudo(t_socket *sock)
{
  int		i;

  i = 0;
  while (sock->pseudo[i] != NULL)
    ++i;
  return (i - 1);
}

int		nb_pseudo_udp(t_udps *udp)
{
  int		i;

  i = 0;
  while (udp->pseudo[i] != NULL)
    ++i;
  return (i - 1);
}
