/*
** pseudo_handler.c for functions to check pseudo in /gfx_tekdoom
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Sat Jan 16 17:57:52 2016 Lucas Troncy
** Last update Mon Jan 25 06:37:32 2016 Lucas Troncy
*/

#include "tekdoom.h"

char		**add_pseudo(char **pseudo, char new[])
{
  char		**table;
  int		i;

#ifdef	DEBUG
  printf("E:%s\n", new);
#endif
  i = -1;
  while (pseudo[++i] != NULL);
  table = malloc(sizeof(char *) * (i + 2));
  i = -1;
  while (pseudo[++i] != NULL)
    {
      table[i] = malloc(sizeof(char) * 21);
      my_strncpy(table[i], pseudo[i], my_strlen(pseudo[i]));
      table[i][my_strlen(pseudo[i])] = '\0';
    }
  table[i] = malloc(sizeof(char) *  21);
  my_strncpy(table[i], new, my_strlen(new));
  table[i][my_strlen(new)] = '\0';
  table[++i] = NULL;
  free(pseudo);
  return (table);
}

int		compare_pseudo(char **pseudo, char str[])
{
  int		i;

  i = 0;
  while (pseudo[i] != NULL)
    {
      if (my_strncmp(pseudo[i], str, my_strlen(str)) == 0)
	return (1);
      ++i;
    }
  return (0);
}

int		check_pseudo(t_socket *sock, char buff[])
{
  if (compare_pseudo(sock->pseudo, buff) == 1 || my_strlen(buff) > 20 ||
      buff[0] == '/' || nb_pseudo(sock) >= 8)
    {
      write(sock->tmp_sock,
	    "Pseudo  not avalaible, too long or the server is full:(\n", 56);
      close(sock->tmp_sock);
      write(1, "Rejected someone for wrong pseudo\n", 34);
      return (-1);
    }
    sock->pseudo = add_pseudo(sock->pseudo, buff);
    return (0);
}

void		remove_pseudo(char **pseudo, int i)
{
  int		j;

  j = 0;
  while (pseudo[i][j] != '\0')
    pseudo[i][j++] = '\0';
  j = 0;
  while (pseudo[i + 1] != NULL)
    {
      my_strncpy(pseudo[i], pseudo[i + 1], my_strlen(pseudo[i + 1]));
      ++i;
    }
  pseudo[i] = NULL;
}

void		remove_pseudoc(char **pseudo, char *rm)
{
  int		j;
  int		i;

  j = 0;
  i = 0;
  while (pseudo[i] != NULL && my_strncmp(pseudo[i], rm, my_strlen(rm)) != 0)
    ++i;
  while (pseudo[i][j] != '\0')
    pseudo[i][j++] = '\0';
  j = 0;
  while (pseudo[i + 1] != NULL)
    {
      my_strncpy(pseudo[i], pseudo[i + 1], my_strlen(pseudo[i + 1]));
      ++i;
    }
  pseudo[i] = NULL;
}
