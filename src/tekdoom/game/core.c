/*
** core.c for tekdoom in /home/asphahyre/rendu/tekdoom_dev/src/tekdoom/game
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Tue Jan 26 18:15:22 2016 Luka Boulagnon
** Last update Wed Jan 27 07:19:13 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int		can_shot(t_data *data)
{
  if (data->player->knife.is_selected)
    return (1);
  if (data->player->rifle.is_selected && data->player->rifle.remaining)
    return (data->player->rifle.remaining--);
  if (data->player->gun.is_selected && data->player->gun.remaining)
    return (data->player->gun.remaining--);
  return (0);
}

t_vertice	set_pos(double x, double z, double y)
{
  t_vertice	ret;

  ret.x = x;
  ret.y = y;
  ret.z = z;
  return (ret);
}

t_vertice 	pick_random_pos(void)
{
  t_vertice	pos[10];

  pos[0] = set_pos(2.5, -23.5, 2.5);
  pos[1] = set_pos(2.5, -10.5, 2.5);
  pos[2] = set_pos(6, -13.5, 2.5);
  pos[3] = set_pos(8.5, -27.5, 1.5);
  pos[4] = set_pos(8.5, -5.5, 1.5);
  pos[5] = set_pos(8.5, -21.5, 1.5);
  pos[6] = set_pos(19.5, -5.5, 1.5);
  pos[7] = set_pos(23.5, -22.5, 1.5);
  pos[8] = set_pos(26.5, -1.5, 1.5);
  pos[9] = set_pos(26.5, -27.5, 1.5);
  return (pos[rand() % 10]);
}

void		gun_selected(t_data *data, int delta)
{
  if (delta == 1)
    data->player->knife.is_selected = 1;
  else
    data->player->gun.is_selected = 1;
}

int		play_sound(t_data *data)
{
  if (!data->event.bits.shot)
    return (0);
  if (data->player->knife.is_selected)
    bunny_sound_play(data->player->knife.sound);
  else if (data->player->rifle.is_selected)
    bunny_sound_play(data->player->rifle.sound);
  else if (data->player->gun.is_selected)
    bunny_sound_play(data->player->gun.sound);
  return (0);
}
