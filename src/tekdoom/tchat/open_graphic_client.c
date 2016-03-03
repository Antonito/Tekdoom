/*
** connect.c for tekdoom in /home/asphahyre/rendu/tekdoom_dev/src/tekdoom/tchat
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Fri Jan 22 10:04:55 2016 Luka Boulagnon
** Last update Wed Jan 27 06:52:54 2016 Luka Boulagnon
*/

#include "tekdoom.h"

t_bunny_response	graph_connect(void *param)
{
  t_params		*prms;

  prms = param;
  if (!(prms->connect_buttons->next->next->text[0]))
    {
      prms->current = &connect_srv;
      return (GO_ON);
    }
  my_bzero(prms->data, sizeof(t_data));
  if ((prms->data->login = malloc(sizeof(t_login))) == NULL)
    return (EXIT_ON_ERROR);
  prms->data->login->ip = my_strdup(prms->connect_buttons->text);
  prms->data->login->port = my_strdup(prms->connect_buttons->next->text);
  my_strncpy(prms->data->player[0].name,
	     prms->connect_buttons->next->next->text, 14);
  prms->data->player[0].name[15] = '\0';
  prms->data->fullscreen = prms->fullscreen;
  prms->data->mouse_pos = &prms->cur_pos;
  bunny_sound_stop(prms->intro_sound);
  bunny_delete_sound(prms->intro_sound);
  bunny_stop(prms->window);
  if ((client(prms->data) &&
       (prms->window = bunny_start(1920, 1080, 1, "Tekdoom"))))
    return (EXIT_ON_ERROR);
  prms->window = bunny_start(1920, 1080, 1, "Tekdoom");
  return (EXIT_ON_SUCCESS);
}

t_bunny_response	connecting(void *params, int type)
{
  if (type == LOOP)
    return (graph_connect(params));
  return (GO_ON);
}
