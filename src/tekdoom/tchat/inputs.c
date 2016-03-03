/*
** inputs.c for Tekdoom in /tekdoom_dev/src/tekdoom/tchat
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 27 05:30:10 2016 Antoine Baché
** Last update Wed Jan 27 06:40:59 2016 Antoine Baché
*/

#include "tekdoom.h"

void	inaddr_text_add(t_key *key, t_key *send)
{
  key->params->current = &input_port;
  send->key = BKS_BACKSPACE;
  send->state = GO_DOWN;
  send->params = key->params;
  key->params->current(send, KEY);
}

void	inprt_text_add(t_key *key, t_key *send)
{
  key->params->current = &input_pseudo;
  send->key = BKS_BACKSPACE;
  send->state = GO_DOWN;
  send->params = key->params;
  key->params->current(send, KEY);
}
