/*
** uvwxy.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Tue Jan 26 05:52:43 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_game_u(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'u';
      data->message.indice++;
      print_game_letter(data, "u");
    }
  return (0);
}

int	type_game_v(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'v';
      data->message.indice++;
      print_game_letter(data, "v");
    }
  return (0);
}

int	type_game_w(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'w';
      data->message.indice++;
      print_game_letter(data, "w");
    }
  return (0);
}

int	type_game_x(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'x';
      data->message.indice++;
      print_game_letter(data, "x");
    }
  return (0);
}

int	type_game_y(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'y';
      data->message.indice++;
      print_game_letter(data, "y");
    }
  return (0);
}
