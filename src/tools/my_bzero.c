/*
** my_bzero.c for tekdoom in /home/asphahyre/rendu/tekdoom_dev/src/tools
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Sun Jan 24 19:20:05 2016 Luka Boulagnon
** Last update Sun Jan 24 19:21:28 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void		my_bzero(void *content, int size)
{
  unsigned char	*addr;

  addr = content;
  while (size--)
    addr[size] = 0;
}
