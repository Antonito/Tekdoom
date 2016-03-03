/*
** udp_msg_tools2.c for Tekdoom in /gfx_tekdoom/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan 16 00:40:36 2016 Antoine Baché
** Last update Wed Jan 27 08:29:28 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int	check_udp(char *msg)
{
  if (msg[0] != 'N' || msg[1] != 'A' || msg[2] != 'M' || msg[3] != 'E' ||
      msg[4] != ':' || msg[25] != '\0' || msg[26] != 'E' || msg[27] != 'N' ||
      msg[28] != ':' || msg[33] != '\0' || msg[34] != 'X' || msg[35] != ':' ||
      msg[44] != '\0' || msg[45] != 'Y' || msg[46] != ':' || msg[55] != '\0' ||
      msg[56] != 'Z' || msg[57] != ':' || msg[66] != '\0' || msg[67] != 'V' ||
      msg[68] != 'e' || msg[69] != 'c' || msg[70] != 'X' || msg[71] != ':' ||
      msg[80] != '\0' || msg[81] != 'V' || msg[82] != 'e' || msg[83] != 'c' ||
      msg[84] != 'Y' || msg[85] != ':' || msg[94] != '\0' || msg[95] != 'V' ||
      msg[96] != 'e' || msg[97] != 'c' || msg[98] != 'Z' || msg[99] != ':' ||
      msg[108] != '\0' || msg[119] != '\0' || msg[110] != ':' ||
      msg[109] != 'R')
    return (1);
  return (0);
}

void	udp_to_infos_vec(t_vector *vec, char *msg, char *tmp_double, int i)
{
  int	j;

  j = 0;
  tmp_double = (char *)&vec->x;
  while (i < 72 && (tmp_double[j] = msg[i]) && (++j) && (++i));
  vec->x = *(double *)tmp_double;
  j = 0;
  i += 6;
  tmp_double = (char *)&vec->y;
  while (i < 94 && (tmp_double[j] = msg[i]) && (++j) && (++i));
  vec->y = *(double *)tmp_double;
  j = 0;
  i += 6;
  tmp_double = (char *)&vec->z;
  while (i < 108 && (tmp_double[j] = msg[i]) && (++j) && (++i));
  vec->z = *(double *)tmp_double;
}

void	udp_to_infos_pos(t_pos *pos, char *msg, char *tmp_double, int i)
{
  int	j;

  j = 0;
  while (i < 44 && (tmp_double[j] = msg[i]) && (++j) && (++i));
  pos->dir.x = *(double *)tmp_double;
  j = 0;
  i += 3;
  tmp_double = (char *)&pos->dir.y;
  while (i < 55 && (tmp_double[j] = msg[i]) && (++j) && (++i));
  pos->dir.y = *(double *)tmp_double;
  j = 0;
  i += 3;
  tmp_double = (char *)&pos->dir.z;
  while (i < 66 && (tmp_double[j] = msg[i]) && (++j) && (++i));
  pos->dir.z = *(double *)tmp_double;
  i += 6;
  udp_to_infos_vec(&pos->vec, msg, tmp_double, i);
}

int	udp_to_infos(t_player *player, char *msg)
{
  int  	i;
  int	j;
  char	*tmp_double;
  char	*tmp_int;

  i = 5;
  j = 0;
  if ((tmp_int = malloc(sizeof(char) * sizeof(int32_t))) == NULL)
    return (1);
  if ((tmp_double = malloc(sizeof(char) * sizeof(double))) == NULL)
    return (1);
  while (i < 25 && (player->name[j] = msg[i]) && (++j) && (++i));
  j = 0;
  i += 4;
  while (i < 33 && (tmp_int[j] = msg[i]) && (++j) && (++i));
  player->events = *(int *)tmp_int;
  i = 111;
  j = 0;
  while (i < 119 && (tmp_double[j] = msg[i]) && (++j) && (++i));
  player->rotate[1] = *(double *)tmp_double;
  free(tmp_int);
  udp_to_infos_pos(&player->pos, msg, tmp_double, i);
  free(tmp_double);
  return (0);
}
