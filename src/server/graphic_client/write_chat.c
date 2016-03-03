/*
** write_chat.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Jan 21 22:50:46 2016 Antoine Baché
** Last update Wed Jan 27 03:38:31 2016 Antoine Baché
*/

#include "tekdoom.h"

void	order_chat_msg(t_data *data)
{
  int	i;
  int	j;

  i = -1;
  while (++i < data->max_chat - 1 && (j = -1))
    {
      while (++j < MAX_MSG)
	data->message.foreign[i][j] = data->message.foreign[i + 1][j];
    }
}

void	display_chat_msg(t_data *data)
{
  int	i;

  i = -1;
  while (++i < data->message.indice_foreign)
    {
      draw_msg(data, i);
    }
  data->message.rec = false;
}

void	draw_msg(t_data *data, int i)
{
  t_bunny_pixelarray	*msg_pix;
  t_bunny_position	shift;
  t_bunny_position	pos;

  if ((msg_pix = bunny_new_pixelarray(395, 45)) == NULL)
    return ;
  pos.x = 5;
  pos.y = 5 + i * 34;
  shift.x = 5;
  shift.y = 10;
  transparency_letter(data->pix, msg_pix, &pos);
  write_text_lower(msg_pix, data->message.foreign[i], &shift, false);
  bunny_blit(&data->win->buffer, &msg_pix->clipable, &pos);
  bunny_delete_clipable(&msg_pix->clipable);
}

void	write_chat(t_data *data)
{
#ifdef	DEBUG
  int	j;

  write(1, data->message.foreign[data->message.indice_foreign],
	my_strlen(data->message.foreign[data->message.indice_foreign]));
  write(1, "\n", 1);
  j = -1;
  while (++j < data->message.indice_foreign)
    printf("Msg[%d] = %s\n", j, data->message.foreign[j]);
#endif
  data->message.rec = true;
}
