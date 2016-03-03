/*
** init_game.c for Tekdoom in /gfx_tekdoom/src/tekdoom/game
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Jan 24 14:46:52 2016 Antoine Baché
** Last update Wed Jan 27 07:31:56 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void		init_game1(t_data *data)
{
  if ((data->interface.crosshair =
       bunny_load_pixelarray("assets/imgs/misc/crosshair.png")) == NULL)
    return ;
  if ((data->interface.life = bunny_new_pixelarray(450, 60)) == NULL)
    return ;
  data->interface.chat = NULL;
  data->interface.weapon = NULL;
  data->blur = bunny_load_pixelarray("assets/imgs/misc/blur.png");
  data->cursor_toggle = 0;
  data->cursor_pos.x = 1;
  data->cursor_pos.y = 688;
  data->message.indice = 0;
  my_bzero(data->message.msg, MAX_MSG);
  data->chat_toggle = false;
  data->show_chat = false;
  data->keys = get_game_keys1();
  get_game_keys2(data->keys);
  data->count = -1;
  data->max_chat = 6;
  my_bzero(&data->event, sizeof(t_event));
}

int		init_game(t_data *data)
{
  t_player	*t;

  init_game1(data);
  t = data->player;
  t->pos.dir = pick_random_pos();
  t->rifle.is_selected = t->gun.is_selected = 0;
  t->rifle.remaining = (t->life = 100) + 50;
  t->gun.remaining = 10 * (t->knife.is_selected = 1);
  t->gun.texture =
    bunny_load_pixelarray("assets/imgs/misc/gun.png");
  t->gun.shot =
    bunny_load_pixelarray("assets/imgs/misc/gun_shot.png");
  t->rifle.texture =
    bunny_load_pixelarray("assets/imgs/misc/rifle.png");
  t->rifle.shot =
    bunny_load_pixelarray("assets/imgs/misc/rifle_shot.png");
  t->knife.texture =
    bunny_load_pixelarray("assets/imgs/misc/knife.png");
  t->knife.shot =
    bunny_load_pixelarray("assets/imgs/misc/knife_shot.png");
  t->gun.sound = t->rifle.sound = bunny_load_music("assets/musics/gun.wav");
  t->knife.sound = bunny_load_music("assets/musics/knife.wav");
  data->soundtrack = bunny_load_music("assets/musics/soundtrack.wav");
  return ((data->interface.crosshair && t->gun.texture &&
	  t->rifle.texture && t->knife.texture) ? 0 : 1);
}
