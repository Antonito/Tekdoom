/*
** socket.c for socket functions in /gfx_tekdoom/src/server/graphic_client
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Thu Jan 21 20:08:22 2016 Lucas Troncy
** Last update Wed Feb  3 12:18:39 2016 Antoine Baché
*/

#include "tekdoom.h"

void		gcheck_msg(t_data *data, char *msg)
{
  if (msg[1] == 'a')
    g_check_msg_1(data, msg);
  else if (msg[1] == 'r')
    g_check_msg_2(data, msg);
  else if (msg[1] == 'z')
    {
      g_check_msg_3(data);
    }
 else if (msg[1] == 's')
   {
     write(1, "TO FIXXXXXXX Setting status for ", 32);
     write(1, msg, my_strlen(msg));
     write(1, "\n", 1);
   }
 else
   write(1, "ready\n", 6);
}

void		gsend_to_server(t_data *data, char *msg)
{
  char		*str;

  if ((str = malloc(sizeof(char) * (my_strlen(msg) + 23))) == NULL)
    return ;
  str[0] = 0;
  str = my_strncpy(str, data->player[0].name, my_strlen(data->player[0].name));
  str[my_strlen(data->player[0].name)] = 0;
  str = my_strncat(str, ": \0", 3);
  str = my_strncat(str, msg, my_strlen(msg));
  str = my_strncat(str, "\0", 1);
  write(data->sock.sock, str, my_strlen(str));
  free(str);
}

void		*glisten_server(void *datb)
{
  int		len;
  t_data	*data;

  data = (t_data *)datb;
  data->message.indice_foreign = -1;
  data->sock.run = 1;
  while (data->sock.run)
    {
      glisten_server_more(data, &len);
      if (data->sock.msg[0] == '/')
	{
	  if (data->sock.msg[0] == '\0')
	    continue;
	  gcheck_msg(data, data->sock.msg);
	}
      else
	{
	  my_strncpy(data->message.foreign[data->message.indice_foreign],
		     data->sock.msg, my_strlen(data->sock.msg));
	  data->message.foreign[data->message.indice_foreign][len] = '\0';
	  write_chat(data);
	}
    }
  return ((void *)0);
}

void		ginit_socket(t_data *data)
{
  if ((data->sock.sock = socket(AF_INET , SOCK_STREAM , 0)) == -1 &&
      write(2, "Error creating the socket, moreel_a isn't happy\n", 47) != -2)
    return ;
#ifdef	DEBUG
  printf("ip!%s!\n", data->login->ip);
#endif
  data->sock.server.sin_addr.s_addr = inet_addr(data->login->ip);
  data->sock.server.sin_family = AF_INET;
  data->sock.server.sin_port = htons(my_getnbr(data->login->port));
  if (connect(data->sock.sock, (struct sockaddr *)&data->sock.server,
	      sizeof(data->sock.server)) < 0 &&
      write(2, "Cannot connect, moreel_a not happy :(\n", 38) != -2)
    return ;
  srand(time(NULL));
  write(data->sock.sock, data->player[0].name,
	my_strlen(data->player[0].name));
  if (pthread_create(&data->sock.thread, NULL,
		     glisten_server, (void *)data) < 0)
    write(2, "Cannot create thread PIPI\n", 26);
}
