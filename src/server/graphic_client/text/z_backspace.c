/*
** z_backspace.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src/text
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 20 17:47:26 2016 Antoine Baché
** Last update Wed Jan 27 06:16:00 2016 Antoine Baché
*/

#include "tekdoom.h"

int	type_z(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = 'z';
      data->message.indice++;
      print_letter(data, "z");
    }
  return (0);
}

int			type_backspace(t_data *data)
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  t_color		*color;
  int			i;

  if ((pos.y = 681) && data->message.indice == MAX_CHAT_MSG - 1)
    pos.x = 382;
  else
    pos.x = 6 + (data->message.indice - 1) * 10;
  if (data->message.indice > 0)
    {
      data->message.indice--;
      clear_cursor(&data->cursor_pos, data->win);
      data->cursor_pos.x -= 10;
      i = -1;
      if ((pix = bunny_new_pixelarray(20, 34)) == NULL)
	return (1);
      color = pix->pixels;
      while (++i < 680)
	color[i].full = 0xE3F6FD;
      bunny_blit(&data->win->buffer, &pix->clipable, &pos);
      bunny_delete_clipable(&pix->clipable);
    }
  data->message.msg[data->message.indice] = '\0';
  return (0);
}

int	type_space(t_data *data)
{
  if (data->message.indice < MAX_CHAT_MSG - 1)
    {
      data->message.msg[data->message.indice] = ' ';
      data->message.indice++;
      print_letter(data, " ");
    }
  return (0);
}

int	type_enter(t_data *data)
{
  int	i;

  if (data->message.msg[0] != '\0')
    gsend_to_server(data, data->message.msg);
  i = -1;
  while (++i < MAX_CHAT_MSG - 1 && !(data->message.msg[i] = '\0'));
  textbar_set(data->pix);
  data->message.indice = 0;
  clear_cursor(&data->cursor_pos, data->win);
  data->cursor_pos.x = 5;
  data->message.rec = true;
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  return (0);
}
