/*
** abcde.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Thu Jan 21 13:59:41 2016 Antoine Baché
*/

#include "tekdoom.h"

int	menu_type_a(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'a';
      data->message.indice++;
      menu_print_letter(data, "a");
    }
  return (0);
}

int	menu_type_b(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'b';
      data->message.indice++;
      menu_print_letter(data, "b");
    }
  return (0);
}

int	menu_type_c(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'c';
      data->message.indice++;
      menu_print_letter(data, "c");
    }
  return (0);
}

int	menu_type_d(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'd';
      data->message.indice++;
      menu_print_letter(data, "d");
    }
  return (0);
}

int	menu_type_e(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'e';
      data->message.indice++;
      menu_print_letter(data, "e");
    }
  return (0);
}
