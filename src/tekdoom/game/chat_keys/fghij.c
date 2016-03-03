/*
** fghij.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Tue Jan 26 05:53:14 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_game_f(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'f';
      data->message.indice++;
      print_game_letter(data, "f");
    }
  return (0);
}

int	type_game_g(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'g';
      data->message.indice++;
      print_game_letter(data, "g");
    }
  return (0);
}

int	type_game_h(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'h';
      data->message.indice++;
      print_game_letter(data, "h");
    }
  return (0);
}

int	type_game_i(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'i';
      data->message.indice++;
      print_game_letter(data, "i");
    }
  return (0);
}

int	type_game_j(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'j';
      data->message.indice++;
      print_game_letter(data, "j");
    }
  return (0);
}
