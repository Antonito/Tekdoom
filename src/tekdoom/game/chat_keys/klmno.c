/*
** klmno.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Tue Jan 26 05:53:22 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_game_k(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'k';
      data->message.indice++;
      print_game_letter(data, "k");
    }
  return (0);
}

int	type_game_l(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'l';
      data->message.indice++;
      print_game_letter(data, "l");
    }
  return (0);
}

int	type_game_m(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'm';
      data->message.indice++;
      print_game_letter(data, "m");
    }
  return (0);
}

int	type_game_n(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'n';
      data->message.indice++;
      print_game_letter(data, "n");
    }
  return (0);
}

int	type_game_o(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'o';
      data->message.indice++;
      print_game_letter(data, "o");
    }
  return (0);
}
