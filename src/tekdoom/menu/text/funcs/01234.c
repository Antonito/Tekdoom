/*
** 01234.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Thu Jan 21 13:59:30 2016 Antoine Baché
*/

#include "tekdoom.h"

int	menu_type_0(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '0';
      data->message.indice++;
      menu_print_letter(data, "0");
    }
  return (0);
}

int	menu_type_1(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '1';
      data->message.indice++;
      menu_print_letter(data, "1");
    }
  return (0);
}

int	menu_type_2(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '2';
      data->message.indice++;
      menu_print_letter(data, "2");
    }
  return (0);
}

int	menu_type_3(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '3';
      data->message.indice++;
      menu_print_letter(data, "3");
    }
  return (0);
}

int	menu_type_4(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = '4';
      data->message.indice++;
      menu_print_letter(data, "4");
    }
  return (0);
}
