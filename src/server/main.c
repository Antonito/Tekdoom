/*
** main.c for Tekdoom in /gfx_tekdoom/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 11 20:52:35 2016 Antoine Baché
** Last update Sat Jan 16 18:58:00 2016 Antoine Baché
*/

#include "tekdoom.h"

int		parse_serv(int ac, char **av)
{
  int		i;

  if (ac != 2 || my_getnbr(av[1]) <= 0)
    {
      write(2, "Usage: ./server_tekdoom port\n", 29);
      return (1);
    }
  i = -1;
  while (av[1][++i] != '\0')
    if (av[1][i] < '0' && av[1][i] > '9')
      {
	write(2, "Invalid port\n", 13);
	return (1);
      }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_socket	sock;

  if ((sock.pseudo = malloc(sizeof(char *))) == NULL)
    return (1);
  sock.pseudo[0] = NULL;
  if (*env == NULL || parse_serv(ac, av) || server(&sock, av[1]) != 0)
    {
#ifdef	DEBUG
      write(2, "SERVER STATUS : KO\n", 19);
#endif
      return (1);
    }
#ifdef	DEBUG
  write(2, "SERVER STATUS : OK\n", 19);
#endif
  return (0);
}
