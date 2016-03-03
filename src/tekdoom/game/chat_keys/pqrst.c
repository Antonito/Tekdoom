/*
** pqrst.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Tue Jan 26 05:53:33 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_game_p(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'p';
      data->message.indice++;
      print_game_letter(data, "p");
    }
  return (0);
}

int	type_game_q(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'q';
      data->message.indice++;
      print_game_letter(data, "q");
    }
  return (0);
}

int	type_game_r(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'r';
      data->message.indice++;
      print_game_letter(data, "r");
    }
  return (0);
}

int	type_game_s(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 's';
      data->message.indice++;
      print_game_letter(data, "s");
    }
  return (0);
}

int	type_game_t(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 't';
      data->message.indice++;
      print_game_letter(data, "t");
    }
  return (0);
}
