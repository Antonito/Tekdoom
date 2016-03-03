/*
** debug_tools.c for Tekdoom in /gfx_tekdoom/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 12 20:16:22 2016 Antoine Baché
** Last update Fri Jan 15 21:05:40 2016 Antoine Baché
*/

#include "tekdoom.h"

void	socket_send_player_debug(t_player *player)
{
  write(1, "Player: ", 8);
  write(1, player->name, my_strlen(player->name));
  write(1, "\nPosX: ", 7);
  my_put_nbr(player->pos.dir.x);
  write(1, "\nPosY: ", 7);
  my_put_nbr(player->pos.dir.y);
  write(1, "\nPosZ: ", 7);
  my_put_nbr(player->pos.dir.z);
  write(1, "\nVecX: ", 7);
  my_put_nbr(player->pos.vec.x);
  write(1, "\nVecY: ", 7);
  my_put_nbr(player->pos.vec.y);
  write(1, "\nVecZ: ", 7);
  my_put_nbr(player->pos.vec.z);
  write(1, "\nEvent: ", 8);
  my_put_nbr(player->events);
  write(1, "\n", 1);
}
