/*
** z_backspace.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Sun Jan 24 17:44:59 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int	menu_type_z(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'z';
      data->message.indice++;
      menu_print_letter(data, "z");
    }
  return (0);
}

int	menu_type_backspace(t_data *data)
{
  if (data->message.indice > 0)
    data->message.msg[--data->message.indice] = '\0';
  menu_print_letter(data, "\0");
  return (0);
}

int	menu_type_space(t_data *data)
{
  if (data->message.indice < MAX_MSG - 1)
    {
      data->message.msg[data->message.indice] = ' ';
      data->message.indice++;
      menu_print_letter(data, " ");
    }
  return (0);
}

int	menu_type_enter(UNUSED t_data *data)
{
  return (0);
}
