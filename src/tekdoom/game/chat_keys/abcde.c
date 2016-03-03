/*
** abcde.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Tue Jan 26 05:53:09 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_game_a(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'a';
      data->message.indice++;
      print_game_letter(data, "a");
    }
  return (0);
}

int	type_game_b(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'b';
      data->message.indice++;
      print_game_letter(data, "b");
    }
  return (0);
}

int	type_game_c(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'c';
      data->message.indice++;
      print_game_letter(data, "c");
    }
  return (0);
}

int	type_game_d(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'd';
      data->message.indice++;
      print_game_letter(data, "d");
    }
  return (0);
}

int	type_game_e(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'e';
      data->message.indice++;
      print_game_letter(data, "e");
    }
  return (0);
}
