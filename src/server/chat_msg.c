/*
** chat_msg.c for Tekdoom in /tekdoom_dev/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 12 21:57:25 2016 Antoine Baché
** Last update Sat Jan 16 14:37:45 2016 Antoine Baché
*/

#include "tekdoom.h"

void	clear_serv_msg(char *msg)
{
  int	i;

  i = -1;
  while (++i < 201 && (msg[i] = '\0'));
}

int	write_message(char *msg, char *str)
{
  int	i;
  int	len;

  len = my_strlen(str);
  clear_serv_msg(msg);
  if (len > MAX_MSG - 1)
    {
#ifdef	DEBUG
      write(1, "WRITE MESSAGE : Too long\n", 25);
#endif
      return (1);
    }
  i = -1;
  while (++i < MAX_MSG - 1 && (msg[i] = str[i]));
  return (0);
}
