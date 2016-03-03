/*
** my_strncat.c for strncat in /home/troncy_l/rendu/Piscine_C_J07/lib/my
** 
** Made by Lucas TRONCY
** Login   <troncy_l@epitech.net>
** 
** Started on  Tue Oct  6 13:36:16 2015 Lucas TRONCY
** Last update Wed Jan 27 08:16:09 2016 Luka Boulagnon
*/

#include "tekdoom.h"

char	*my_strncat(char *dest, char *src, int n)
{
  int	count;
  int	len;

  count  = 0;
  len = my_strlen(dest);
  while (src[count] != '\0' && count < n)
    {
      dest[len] = src[count];
      len++;
      count++;
    }
  dest[len] = '\0';
  return (dest);
}
