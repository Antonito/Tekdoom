/*
** inits.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Dec 27 19:38:56 2015 Luka Boulagnon
** Last update Wed Jan 27 06:50:53 2016 Luka Boulagnon
*/

#include "tekdoom.h"

t_bunny_response	close_game(UNUSED void *param, UNUSED int type)
{
  return (EXIT_ON_CROSS);
}

void			err(char *str)
{
#ifdef	DEBUG
  printf(str);
#endif
  (void)str;
  exit(2);
}

void			init_params(t_params *par)
{
  par->config.oculus = 0;
  par->sound_toggle = 50;
  par->curr_opacity = 0;
  par->intro_volume = 100;
  par->intro_sound = bunny_load_music("assets/musics/menu_loop.wav");
  par->menu_sound = bunny_load_music("assets/musics/menu.wav");
  par->window = bunny_start(1920, 1080, 1,
			    "Emmanuel can't, but {DOOM}inique Strauss can");
  par->background = bunny_new_pixelarray(1920, 1080);
  par->game_bg = bunny_new_pixelarray(1920, 1080);
  par->option = bunny_new_pixelarray(500, 70);
  par->cur_pos = *bunny_get_mouse_position();
  if (!(par->option) || !(par->background) || !(par->window)
      || !(par->game_bg))
    err("Error: can't start Doom\n");
  init_buttons(&par->menu_buttons);
  init_connect(&par->connect_buttons);
  par->again = GO_ON;
  par->current = &menu;
  par->fullscreen = 0;
  par->origin.x = (par->origin.y = 0);
  par->data = malloc(sizeof(t_data));
  par->data->win = NULL;
  par->data->message.indice = 200;
  bunny_sound_play(par->intro_sound);
  bunny_sound_volume(par->intro_sound, 60);
}

void		init_connect(t_lst **buttons)
{
  *buttons = new_button("IP address", (1920 - 500) / 2, 200, &input_address);
  add_button("Server port", *buttons, &input_port);
  add_button("Player name", *buttons, &input_pseudo);
  add_button("Connect!", *buttons, &connecting);
  add_button("Go away, I'm alone", *buttons, &menu);
}
void		init_buttons(t_lst **buttons)
{
  *buttons =
    new_button("Connect to server", (1920 - 500) / 2, 200, &connect_srv);
  add_button(my_strdup("Fullscreen: off"), *buttons, &set_fullscreen);
  add_button("Exit", *buttons, &close_game);
}
