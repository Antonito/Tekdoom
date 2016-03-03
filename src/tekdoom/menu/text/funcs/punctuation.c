/*
** punctuation.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Sun Jan 24 17:34:58 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int	menu_type_brackets_open(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '[';
      data->message.indice++;
      menu_print_letter(data, "[");
    }
  return (0);
}

int	menu_type_brackets_close(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = ']';
      data->message.indice++;
      menu_print_letter(data, "]");
    }
  return (0);
}

int	menu_type_comma(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = ',';
      data->message.indice++;
      menu_print_letter(data, ",");
    }
  return (0);
}

int	menu_type_dot(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '.';
      data->message.indice++;
      menu_print_letter(data, "`");
    }
  return (0);
}

int	menu_type_question(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '?';
      data->message.indice++;
      menu_print_letter(data, "?");
    }
  return (0);
}
