/*
** fghij.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Sat Jan 23 18:54:02 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_f(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'f';
      data->message.indice++;
      print_letter(data, "f");
    }
  return (0);
}

int	type_g(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'g';
      data->message.indice++;
      print_letter(data, "g");
    }
  return (0);
}

int	type_h(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'h';
      data->message.indice++;
      print_letter(data, "h");
    }
  return (0);
}

int	type_i(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'i';
      data->message.indice++;
      print_letter(data, "i");
    }
  return (0);
}

int	type_j(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'j';
      data->message.indice++;
      print_letter(data, "j");
    }
  return (0);
}
