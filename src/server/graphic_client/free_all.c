/*
** free_all.c for Tekdoom in /tekdoom_dev/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 18 08:24:57 2016 Antoine Baché
** Last update Thu Jan 21 22:49:50 2016 Antoine Baché
*/

#include "tekdoom.h"

void	free_client(t_data *data)
{
  bunny_stop(data->win);
  bunny_delete_clipable(&data->pix->clipable);
  free(data->mouse_click);
  free(data->keys);
  free(data);
}

void	free_login(t_login *login)
{
  free(login->ip);
  free(login->port);
  free(login);
}
