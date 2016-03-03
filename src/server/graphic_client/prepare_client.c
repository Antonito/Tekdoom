/*
** prepare_client.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 18 08:27:25 2016 Antoine Baché
** Last update Wed Jan 27 06:13:50 2016 Antoine Baché
*/

#include "tekdoom.h"

void	prepare_window(t_data *data)
{
  get_keys2(data->keys);
  data->win = bunny_start(WIN_X, WIN_Y, data->fullscreen, "TekDoom");
  data->pix = bunny_new_pixelarray(WIN_X, WIN_Y);
  data->interface.map = NULL;
  data->interface.chat = NULL;
  data->interface.life = NULL;
  data->interface.weapon = NULL;
  data->interface.crosshair = NULL;
  data->cursor_toggle = 0;
  data->cursor_pos.x = 5;
  data->cursor_pos.y = 681;
  data->max_chat = MAX_CHAT_MSG;
  data->area = OTHER;
}

void	prepare_network(t_data *data)
{
  int	i;
  int	j;

  data->message.indice = 0;
  data->message.rec = true;
  if (!(data->message.foreign = malloc(sizeof(char *) * MAX_CHAT_MSG)))
    return ;
  i = -1;
  while (++i < MAX_CHAT_MSG && (j = -1))
    {
      if ((data->message.foreign[i] = malloc(sizeof(char) * MAX_MSG))
	  == NULL)
	return ;
      while (++j < MAX_MSG && !(data->message.foreign[i][j] = '\0'));
    }
  i = -1;
  while (++i < MAX_MSG && !(data->message.msg[i] = 0));
}

void	prepare_pseudo(t_data *data)
{
  data->player[0].status = false;
}

void	prepare_players(t_data *data)
{
  int	i;

  i = 0;
  while (++i < 8)
    {
      data->player[i].name[0] = 'D';
      data->player[i].name[1] = 'i';
      data->player[i].name[2] = 's';
      data->player[i].name[3] = 'c';
      data->player[i].name[4] = 'o';
      data->player[i].name[5] = 'n';
      data->player[i].name[6] = 'n';
      data->player[i].name[7] = 'e';
      data->player[i].name[8] = 'c';
      data->player[i].name[9] = 't';
      data->player[i].name[10] = 'e';
      data->player[i].name[11] = 'd';
      data->player[i].name[12] = '\0';
      data->player[i].status = true;
    }
}

void	prepare_client(t_data *data)
{
  prepare_players(data);
  prepare_window(data);
  prepare_network(data);
  prepare_pseudo(data);
}
