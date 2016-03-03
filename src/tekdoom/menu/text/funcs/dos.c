/*
** dos.c for tekdoom in /gfx_tekdoom/src/tekdoom/menu/text/funcs
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sat Jan 23 19:59:48 2016 Luka Boulagnon
** Last update Sun Jan 24 23:25:51 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int			menu_print_letter(t_data *data, UNUSED char *letter)
{
  t_bunny_position	pos;

  if (data->message.indice > 20)
    return (--data->message.indice +
	    (data->message.msg[data->message.indice - 1] = 0));
  pos.x = 220;
  pos.y = 7;
  parall(data->pix, 0xE3F6FD);
  write_text(data->pix, data->message.msg, &pos);
  return (0);
}
