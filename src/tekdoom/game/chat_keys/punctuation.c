/*
** punctuation.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Tue Jan 26 05:53:28 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_game_brackets_open(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '[';
      data->message.indice++;
      print_game_letter(data, "[");
    }
  return (0);
}

int	type_game_brackets_close(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = ']';
      data->message.indice++;
      print_game_letter(data, "]");
    }
  return (0);
}

int	type_game_comma(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = ',';
      data->message.indice++;
      print_game_letter(data, ",");
    }
  return (0);
}

int	type_game_dot(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '.';
      data->message.indice++;
      print_game_letter(data, "`");
    }
  return (0);
}

int	type_game_question(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '?';
      data->message.indice++;
      print_game_letter(data, "?");
    }
  return (0);
}
