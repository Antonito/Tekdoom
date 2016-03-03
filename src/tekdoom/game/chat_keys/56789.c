/*
** 56789.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Tue Jan 26 05:53:01 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_game_5(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '5';
      data->message.indice++;
      print_game_letter(data, "5");
    }
  return (0);
}

int	type_game_6(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '6';
      data->message.indice++;
      print_game_letter(data, "6");
    }
  return (0);
}

int	type_game_7(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '7';
      data->message.indice++;
      print_game_letter(data, "7");
    }
  return (0);
}

int	type_game_8(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '8';
      data->message.indice++;
      print_game_letter(data, "8");
    }
  return (0);
}

int	type_game_9(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '9';
      data->message.indice++;
      print_game_letter(data, "9");
    }
  return (0);
}
