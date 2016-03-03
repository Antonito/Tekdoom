/*
** abcde.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Sat Jan 23 18:55:04 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_semicolon(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = ';';
      data->message.indice++;
      print_letter(data, ";");
    }
  return (0);
}

int	type_quote(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '\'';
      data->message.indice++;
      print_letter(data, "'");
    }
  return (0);
}

int	type_slash(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '/';
      data->message.indice++;
      print_letter(data, "$");
    }
  return (0);
}

int	type_backslash(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '\\';
      data->message.indice++;
      print_letter(data, "\\");
    }
  return (0);
}

int	type_tilde(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = '~';
      data->message.indice++;
      print_letter(data, "~");
    }
  return (0);
}
