/*
** write_chat2.c for Tekdoom in /tekdoom_dev/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 22 13:08:59 2016 Antoine Baché
** Last update Sat Jan 23 18:45:04 2016 Antoine Baché
*/

#include "tekdoom.h"

char	*copy_status(char *pseudo, char *status)
{
  char	*msg;
  int	len;
  int	tmp;
  int	i;
  int	j;

  len = my_strlen(pseudo) + my_strlen(status) + 1;
  if ((msg = malloc(sizeof(char) * len)) == NULL)
    return (NULL);
  tmp = my_strlen(pseudo);
  i = -1;
  while (++i < tmp && (msg[i] = pseudo[i]));
  j = -1;
  tmp = my_strlen(status);
  while (++j < tmp && (msg[i] = status[j]) && (++i));
  msg[len] = '\0';
  return (msg);
}
