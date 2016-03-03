/*
** mouse.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 18 07:41:28 2016 Antoine Baché
** Last update Thu Jan 21 13:58:31 2016 Antoine Baché
*/

#include "tekdoom.h"

int	do_nothing(UNUSED t_data *data)
{
  return (0);
}

mousetab	get_mousefunction(void)
{
  mousetab	array;

  if ((array = malloc(sizeof(int *) * MOUSE_BUTTONS)) == NULL)
    return (NULL);
  array[BMB_LEFT] = &get_mouse_area;
  array[BMB_RIGHT] = &do_nothing;
  array[BMB_MIDDLE] = &do_nothing;
  array[BMB_EXTRABUTTON0] = &do_nothing;
  array[BMB_EXTRABUTTON1] = &do_nothing;
  array[LAST_BUNNY_MOUSEBUTTON] = &do_nothing;
  return (array);
}
