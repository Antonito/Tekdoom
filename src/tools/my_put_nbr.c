/*
** my_put_nbr.c for Tekdoom in /gfx_tekdoom/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 15 19:11:49 2016 Antoine Baché
** Last update Sat Jan 16 00:25:24 2016 Antoine Baché
*/

#include "tekdoom.h"

int	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb < 0)
    {
      if (nb == -2147483648)
	{
	  my_putstr("-2147483648");
	  return (11);
	}
      my_putchar('-');
      i++;
      nb = -nb;
    }
  if (nb >= 10)
    i += my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
  return (i);
}
