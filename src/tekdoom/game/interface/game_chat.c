/*
** game_chat.c for Tekdoom in /gfx_tekdoom/src/tekdoom/game/interface
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 14:27:32 2016 Antoine Baché
** Last update Wed Jan 27 03:02:04 2016 Antoine Baché
*/

#include "tekdoom.h"

void		game_textbar_set(t_bunny_pixelarray *pix)
{
  int		j;
  int		i;
  t_color	*colors;

  colors = pix->pixels;
  j = 180;
  while (++j < 215 && (i = -1))
    {
      while (++i < 395)
	colors[j * 395 + i].full = 0xD0E3F6FD;
    }
}

void		game_chatbox_set(t_bunny_pixelarray *pix)
{
  int		j;
  int		i;
  t_color	*colors;

  colors = pix->pixels;
  j = -1;
  while (++j < 180 && (i = -1))
    {
      while (++i < 395)
	colors[j * 395 + i].full = 0xA080808c;
    }
  i = -1;
  while (++i < 395)
    {
      colors[i].full = 0x000000;
      colors[180 * 395 + i].full = 0xA0000000;
      colors[395 * 395 + i].full = 0xA0000000;
    }
}

void			display_chat(t_data *data)
{
  t_bunny_position	origin;
  t_bunny_position	pos;

  if (!data->interface.chat)
    data->interface.chat = bunny_new_pixelarray(395, 215);
  game_chatbox_set(data->interface.chat);
  game_textbar_set(data->interface.chat);
  origin.x = 0;
  origin.y = 507;
  pos.x = -9;
  pos.y = 187;
  if (data->message.msg[0] != '\0')
    write_text_lower(data->interface.chat, data->message.msg,
		     &pos, false);
  display_chat_msg_game(data);
  transp_blit(data->pix, data->interface.chat, origin);
}
