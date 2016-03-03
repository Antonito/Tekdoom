/*
** set.c for tekdoom in /home/asphahyre/rendu/tekdoom_dev/src/tekdoom/tchat
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Jan 24 21:20:01 2016 Luka Boulagnon
** Last update Wed Jan 27 03:00:19 2016 Luka Boulagnon
*/

#include "tekdoom.h"

void		set_inprt_text(t_key *key, t_msg *msg, int *unsetted)
{
  my_bzero(msg->msg, 200 + (msg->indice = *unsetted = 0));
  my_strcpy(msg->msg, key->params->connect_buttons->next->text);
  msg->indice = my_strlen(msg->msg);
  key->params->data->pix = key->params->connect_buttons->next->background;
}

void		set_inme_text(t_key *key, t_msg *msg, int *unsetted)
{
  my_bzero(msg->msg, 200 + (msg->indice = *unsetted = 0));
  my_strcpy(msg->msg, key->params->connect_buttons->next->next->text);
  msg->indice = my_strlen(msg->msg);
  key->params->data->pix =
    key->params->connect_buttons->next->next->background;
}

void		set_inaddr_text(t_key *key, t_msg *msg, int *unsetted)
{
  my_bzero(msg->msg, 200 + (msg->indice = *unsetted = 0));
  my_strcpy(msg->msg, key->params->connect_buttons->text);
  msg->indice = my_strlen(msg->msg);
  key->params->data->pix = key->params->connect_buttons->background;
}

void		set(mousetab *array, int *setted, t_lst *button)
{
  button->text = my_strdup("");
  if (array)
    {
      *array = menu_get_keys1();
      menu_get_keys2(*array);
    }
  *setted = 0;
}
