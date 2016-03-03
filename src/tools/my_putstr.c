/*
** my_putstr.c for Tekdoom in /gfx_tekdoom/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Jan 14 22:30:35 2016 Antoine Baché
** Last update Fri Jan 15 20:33:51 2016 Antoine Baché
*/

#include <tekdoom.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
}
