/*
** 56789.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Thu Jan 21 13:59:36 2016 Antoine Baché
*/

#include "tekdoom.h"

int	menu_type_5(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '5';
      data->message.indice++;
      menu_print_letter(data, "5");
    }
  return (0);
}

int	menu_type_6(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '6';
      data->message.indice++;
      menu_print_letter(data, "6");
    }
  return (0);
}

int	menu_type_7(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '7';
      data->message.indice++;
      menu_print_letter(data, "7");
    }
  return (0);
}

int	menu_type_8(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '8';
      data->message.indice++;
      menu_print_letter(data, "8");
    }
  return (0);
}

int	menu_type_9(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '9';
      data->message.indice++;
      menu_print_letter(data, "9");
    }
  return (0);
}
