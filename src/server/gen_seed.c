/*
** gen_seed.c for Tekdoom in /gfx_tekdoom/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan 16 16:34:15 2016 Antoine Baché
** Last update Mon Jan 18 21:15:32 2016 Antoine Baché
*/

#include "tekdoom.h"

unsigned char	*gen_seed(void)
{
  unsigned char	*key;
  int		i;

  i = -1;
  srand(time(NULL));
  if ((key = malloc(sizeof(char) * 64)) == NULL)
    return (NULL);
  while (++i < 64)
    key[i] = rand() % 256;
  return (key);
}
