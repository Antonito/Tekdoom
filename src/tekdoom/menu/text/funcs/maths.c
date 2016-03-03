/*
** abcde.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Thu Jan 21 13:59:58 2016 Antoine Baché
*/

#include "tekdoom.h"

int	menu_type_equal(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '=';
      data->message.indice++;
      menu_print_letter(data, "=");
    }
  return (0);
}

int	menu_type_dash(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '-';
      data->message.indice++;
      menu_print_letter(data, "-");
    }
  return (0);
}

int	menu_type_add(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '+';
      data->message.indice++;
      menu_print_letter(data, "+");
    }
  return (0);
}

int	menu_type_multiply(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '*';
      data->message.indice++;
      menu_print_letter(data, "*");
    }
  return (0);
}
