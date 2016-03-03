/*
** klmno.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Sat Jan 23 18:54:13 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_k(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'k';
      data->message.indice++;
      print_letter(data, "k");
    }
  return (0);
}

int	type_l(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'l';
      data->message.indice++;
      print_letter(data, "l");
    }
  return (0);
}

int	type_m(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'm';
      data->message.indice++;
      print_letter(data, "m");
    }
  return (0);
}

int	type_n(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'n';
      data->message.indice++;
      print_letter(data, "n");
    }
  return (0);
}

int	type_o(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'o';
      data->message.indice++;
      print_letter(data, "o");
    }
  return (0);
}
