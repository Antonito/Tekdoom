/*
** write_chat.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Jan 21 22:50:46 2016 Antoine Baché
** Last update Wed Jan 27 03:17:20 2016 Antoine Baché
*/

#include "tekdoom.h"

void	display_chat_msg_game(t_data *data)
{
  int	i;

  i = -1;
  while (++i < data->message.indice_foreign)
    {
      draw_msg_game(data, i);
#ifdef	DEBUG
      printf("Msg[%d] = %s\n", i, data->message.foreign[i]);
#endif
    }
}

void			draw_msg_game(t_data *data, int i)
{
  t_bunny_position	pos;
  t_bunny_position	origin;

  origin.x = 0;
  origin.y = 1064;
  pos.x = 5;
  pos.y = i * 34 + 7;
  write_text_lower(data->interface.chat,
		   data->message.foreign[i], &pos, false);
  transp_blit(data->pix, data->interface.chat, origin);
}
