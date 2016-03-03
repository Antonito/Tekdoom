/*
** pseudo_handler.c for pseudo functions in /home/lokoum/prog/tekdoom_dev
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Sat Jan 23 19:08:42 2016 Lucas Troncy
** Last update Wed Jan 27 06:16:23 2016 Antoine Baché
*/

#include "tekdoom.h"

void		sadd_pseudo(t_data *data, char msg[])
{
  int		i;

  i = 0;
  while (i < MAX_CLIENTS)
    {
      if (my_strncmp(data->player[i].name, &msg[3],
		     my_strlen(&msg[3])) == 0)
	return ;
      ++i;
    }
  i = 1;
  while (i < MAX_CLIENTS)
    {
      if (data->player[i].status == true)
	{
	  my_strncpy(data->player[i].name, &msg[3], my_strlen(&msg[3]));
	  data->player[i].name[my_strlen(&msg[3])] = '\0';
	  data->player[i].status = false;
	  break;
	}
      ++i;
    }
}

void		sremove_pseudo(t_data *data, char msg[])
{
  int		i;

  i = 1;
  while (i < MAX_CLIENTS)
    {
      if (my_strncmp(data->player[i].name, &msg[3],
		     my_strlen(&msg[3])) == 0)
	{
	  my_strncpy(data->player[i].name, "Disconnected", 12);
	  data->player[i].name[12] = '\0';
	  data->player[i].status = true;
	  break;
	}
      ++i;
    }
}

int		pseudo_index(t_data *data, char *msg)
{
  int		i;

  i = -1;
  while (i < MAX_CLIENTS)
    {
      if (my_strncmp(data->player[i].name, &msg[5],
		     my_strlen(&msg[5])) == 0)
	return (i);
    }
  return (-1);
}
