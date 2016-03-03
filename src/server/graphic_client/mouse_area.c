/*
** mouse_area.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 18 07:08:56 2016 Antoine Baché
** Last update Thu Jan 21 13:58:37 2016 Antoine Baché
*/

#include "tekdoom.h"

void	chat_area(t_data *data)
{
  if (data->mouse_pos->y >= 680 && data->mouse_pos->y <= 715)
    {
      data->area = TEXTBOX;
    }
  else if (data->mouse_pos->y >= 5 && data->mouse_pos->y <= 679)
    {
      data->area = CHATBOX;
    }
}

void	button_area(t_data *data)
{
  if (data->mouse_pos->x >= 520 && data->mouse_pos->x <= 720)
    {
      data->area = PLAYBUTTON;
    }
  else if (data->mouse_pos->x >= 980 && data->mouse_pos->x <= 1180)
    {
      data->area = EXITBUTTON;
    }
}

int	get_mouse_area(t_data *data)
{
  if (data->mouse_pos->x >= 5 && data->mouse_pos->x <= 400)
    {
      chat_area(data);
    }
  else if (data->mouse_pos->y >= 680 && data->mouse_pos->y <= 715)
    {
      button_area(data);
    }
  else
    {
      data->area = OTHER;
    }
  return (0);
}
