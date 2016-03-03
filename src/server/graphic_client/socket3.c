/*
** socket3.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 25 06:05:29 2016 Antoine Baché
** Last update Wed Jan 27 00:19:59 2016 Antoine Baché
*/

#include "tekdoom.h"

void	g_check_msg_3(t_data *data)
{
  read(data->sock.sock, data->sock.seed, 64);
  write(1, "Generating the MAP\n", 19);
  if (pthread_create(&data->udp.thread, NULL, udp_client ,
		     (void *)data) < 0)
    write(2, "Cannot create thread PIPI\n", 26);
}

void	g_check_msg_2(t_data *data, char *msg)
{
  sremove_pseudo(data, msg);
  my_strncpy(data->message.foreign[data->message.indice_foreign],
	     &msg[3], my_strlen(&msg[3]));
  data->message.foreign[data->message.indice_foreign]
    [my_strlen(&msg[3])] = 0;
  my_strncat(data->message.foreign[data->message.indice_foreign],
	     " has rag quit the game !\0", 25);
  write_chat(data);
#ifdef	DEBUG
  printf("Remove:%s\n", msg);
#endif
}

void	g_check_msg_1(t_data *data, char *msg)
{
  sadd_pseudo(data, msg);
  my_strncpy(data->message.foreign[data->message.indice_foreign],
	     &msg[3], my_strlen(&msg[3]));
  data->message.foreign[data->message.indice_foreign]
    [my_strlen(&msg[3])] = 0;
  my_strncat(data->message.foreign[data->message.indice_foreign],
	     " has joined the game !\0", 23);
#ifdef	DEBUG
  printf("ADDDED:%s\n", msg);
#endif
}

void	glisten_server_more(t_data *data, int *len)
{
  if (data->message.indice_foreign != data->max_chat - 1 &&
      ++data->message.indice_foreign < data->max_chat + 1);
  else
    order_chat_msg(data);
  data->message.foreign[data->message.indice_foreign][MAX_MSG - 1] = '\0';
  *len = read(data->sock.sock, data->sock.msg, MAX_MSG - 1);
  if (*len == 0)
    data->sock.run = 0;
  data->sock.msg[*len] = 0;
#ifdef	DEBUG
  printf("!%s!\n", data->sock.msg);
#endif
}
