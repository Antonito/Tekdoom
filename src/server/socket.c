/*
** socket.c for Tekdoom in /gfx_tekdoom/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Jan 12 20:32:29 2016 Antoine Baché
** Last update Wed Jan 27 08:51:55 2016 Antoine Baché
*/

#include "tekdoom.h"

void	socket_send_msg_all(t_socket *socket, char *msg)
{
  int	i;

  i = -1;
  while (++i < socket->cli_nb)
    if (socket->cli_sock[i] != 0)
      socket_send_msg(socket->cli_sock[i], msg);
}

void	socket_send_seed_all(t_socket *socket, unsigned char *msg)
{
  int	i;

  i = -1;
  while (++i < socket->cli_nb)
    if (socket->cli_sock[i] != 0)
      {
	if (write(socket->cli_sock[i], "/z", 2) == -1)
	  {
	    write(2, "Error init seed\n", 16);
	    break;
	  }
	if (write(socket->cli_sock[i], msg, 64) == -1)
	  {
	    write(2, "Error sending seed\n", 19);
	    break;
	  }
      }
}

void	socket_send_player_all(t_socket *socket, t_player *player)
{
  int	i;

  i = -1;
  while (++i < socket->cli_nb)
    if (socket->cli_sock[i] != 0)
      socket_send_player(socket->cli_sock[i], player);
}

int	socket_send_player(int fd, t_player *player)
{
#ifdef	DEBUG
  socket_send_player_debug(player);
#endif
  if (write(fd, player, sizeof(t_player)) == -1)
    {
      write(2, "Error sending player infos\n", 27);
      return (1);
    }
#ifdef	DEBUG
  write(1, "INFOS SENT\n", 11);
#endif
  return (0);
}

int	socket_send_msg(int fd, char *msg)
{
#ifdef	DEBUG
  write(1, "SENDING MESSAGE\nMessage : ", 26);
  write(1, msg, my_strlen(msg));
  write(1, "\n", 1);
#endif
  if (write(fd, msg, my_strlen(msg)) == -1)
    {
      write(2, "Error sending chat message\n", 27);
      return (1);
    }
#ifdef	DEBUG
  write(1, "MESSAGE SENT\n", 13);
#endif
  return (0);
}
