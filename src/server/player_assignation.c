/*
** player_assignation.c for Tekdoom in /gfx_tekdoom/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 12 21:28:22 2016 Antoine Baché
** Last update Fri Jan 15 00:26:29 2016 Antoine Baché
*/

#include "tekdoom.h"

int	accept_player(int fd, char *msg)
{
  clear_serv_msg(msg);
  msg[0] = 'O';
  msg[1] = 'K';
  socket_send_msg(fd, msg);
  return (0);
}

int	accept_master(int fd, char *msg)
{
  clear_serv_msg(msg);
  msg[0] = 'O';
  msg[1] = 'K';
  socket_send_msg(fd, msg);
  return (0);
}

int	room_full(int fd, char *msg)
{
  if (write_message(msg, "Room is full.") == 1)
    return (1);
  socket_send_msg(fd, msg);
  return (0);
}

int	pseudo_exists(int fd, char *msg)
{
  clear_serv_msg(msg);
  if (write_message(msg, "Pseudo already exists, please change it.") == 1)
    return (1);
  socket_send_msg(fd, msg);
  return (0);
}
