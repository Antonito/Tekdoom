/*
** toggle_chat.c for Tekdoom in /gfx_tekdoom/src/tekdoom/game
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 14:37:15 2016 Antoine Baché
** Last update Wed Jan 27 02:09:34 2016 Antoine Baché
*/

#include "tekdoom.h"

/*
** Pixelarray pour le chat
*/

t_bunny_response	chat_key(t_bunny_event_state state, t_bunny_keysym key,
				 t_wire *wire)
{
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      else if (key != BKS_UNKNOWN && key != BKS_LAST_KEY)
	wire->data->keys[key](wire->data);
    }
  return (GO_ON);
}

void			display_game_chat(t_data *data)
{
  if (!(data->chat_toggle))
    {
      bunny_set_key_response((t_bunny_key)chat_key);
      data->chat_toggle = true;
      data->show_chat = true;
#ifdef	DEBUG
      write(1, "Chat key\n", 9);
#endif
    }
  else
    {
      bunny_set_key_response((t_bunny_key)my_escape);
      data->chat_toggle = false;
      data->show_chat = false;
#ifdef	DEBUG
      write(1, "Game key\n", 9);
#endif
    }
}
