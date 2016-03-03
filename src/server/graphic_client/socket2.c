/*
** socket2.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan 23 21:56:50 2016 Antoine Baché
** Last update Sun Jan 24 15:05:04 2016 Lucas Troncy
*/

#include "tekdoom.h"

void	client_init_bool(bool tab[])
{
  int	i;

  i = 0;
  tab[i] = true;
  while (++i < MAX_CLIENTS)
    tab[i] = false;
}

void		send_start(t_data *data)
{
  static bool	a = false;
  char		tmp[MAX_MSG];

  if (a == false)
    {
      tmp[0] = '\0';
      a = true;
      my_strncpy(tmp, "/start ", 7);
      tmp[7] = '\0';
      my_strncat(tmp, data->player[0].name, my_strlen(data->player[0].name));
      write(data->sock.sock, tmp, my_strlen(tmp));
    }
}
