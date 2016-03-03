/*
** main.c for doom in /home/petren_l/rendu/tek1/semestre_01/doom/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Mon Jan 11 15:50:38 2016 Ludovic Petrenko
** Last update Wed Jan 27 08:37:18 2016 Luka Boulagnon
*/

#include "tekdoom.h"

int	start_engine(t_data *data)
{
  t_wire	*wire;

  if ((wire = malloc(sizeof(t_wire))) == NULL)
    return (1);
  srand(time(NULL));
  set_trigo();
  if (launch_doom(wire, data))
    return (1);
  free_doom(wire);
  return (0);
}

void	free_doom(t_wire *wire)
{
  if ((long)wire->win < 0xFF)
    return ;
}
