/*
** udp_msg_tools.c for Tekdoom in /gfx_tekdoom/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 15 15:15:54 2016 Antoine Baché
** Last update Wed Jan 27 01:54:52 2016 Lucas Troncy
*/

#include "tekdoom.h"

int	check_udp_msg(char *msg)
{
  int	i;

  i = 0;
  while (i <= 94)
    {
      if (msg[i] == '\0' && (i != 25 && i != 33 && i != 44 && i != 55 &&
			     i != 66 && i != 80 && i != 94 && i != 108))
	return (1);
      ++i;
    }
  return (0);
}

void	infos_to_udp_vector(char *msg)
{
  msg[67] = 'V';
  msg[68] = 'e';
  msg[69] = 'c';
  msg[70] = 'X';
  msg[71] = ':';
  msg[80] = '\0';
  msg[81] = 'V';
  msg[82] = 'e';
  msg[83] = 'c';
  msg[84] = 'Y';
  msg[85] = ':';
  msg[94] = '\0';
  msg[95] = 'V';
  msg[96] = 'e';
  msg[97] = 'c';
  msg[98] = 'Z';
  msg[99] = ':';
  msg[108] = '\0';
  msg[109] = 'R';
  msg[110] = ':';
  msg[119] = '\0';
}

void	infos_to_udp_add(char *msg)
{
  int	i;

  i = -1;
  while (++i < 108 && (msg[i] = '\0'));
  msg[0] = 'N';
  msg[1] = 'A';
  msg[2] = 'M';
  msg[3] = 'E';
  msg[4] = ':';
  msg[25] = '\0';
  msg[26] = 'E';
  msg[27] = 'N';
  msg[28] = ':';
  msg[33] = '\0';
  msg[34] = 'X';
  msg[35] = ':';
  msg[44] = '\0';
  msg[45] = 'Y';
  msg[46] = ':';
  msg[55] = '\0';
  msg[56] = 'Z';
  msg[57] = ':';
  msg[66] = '\0';
  infos_to_udp_vector(msg);
}

void	infos_to_udp_add_vec(t_vector *vec, char *msg, int i)
{
  char	*tmp;
  int	j;

  tmp = (char *)&vec->x;
  j = 0;
  while (++i < 72 && (msg[i] = tmp[j]) && (++j));
  tmp = (char *)&vec->y;
  j = 0;
  while (++i < 94 && (msg[i] = tmp[j]) && (++j));
  tmp = (char *)&vec->z;
  j = 0;
  while (++i < 108 && (msg[i] = tmp[j]) && (++j));
}

void	infos_to_udp(t_player *player, char *msg)
{
  int	i;
  int	j;
  char	*tmp;

  i = 5;
  j = 0;
  infos_to_udp_add(msg);
  while (i < 25 && (msg[i] = player->name[j]) && (++j) && (++i));
  j = 0;
  tmp = (char *)&player->events;
  while (++i < 33 && (msg[i] = tmp[j]) && (++j));
  j = 0;
  tmp = (char *)&player->pos.dir.x;
  while (++i < 44 && (msg[i] = tmp[j]) && (++j));
  j = 0;
  tmp = (char *)&player->pos.dir.y;
  while (++i < 55 && (msg[i] = tmp[j]) && (++j));
  j = 0;
  tmp = (char *)&player->pos.dir.z;
  while (++i < 66 && (msg[i] = tmp[j]) && (++j));
  j = 0;
  i = 110;
  tmp = (char *)&player->rotate[1];
  while (++i < 119 && (msg[i] = tmp[j]) && (++j));
  infos_to_udp_add_vec(&player->pos.vec, msg, i);
}
