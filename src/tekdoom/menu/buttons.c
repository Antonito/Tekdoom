/*
** buttons.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src/menu
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Sun Dec 27 20:24:21 2015 Luka Boulagnon
** Last update Mon Jan 25 05:22:03 2016 Antoine Baché
*/

#include "tekdoom.h"

t_lst			*new_button(char *label, int x, int y,
				    t_bunny_response (*func)(void *, int))
{
  t_bunny_pixelarray	*bg;
  t_bunny_position	pos;
  t_lst			*button;

  button = malloc(sizeof(t_lst));
  button->next = NULL;
  button->text = label;
  button->pos.x = x;
  button->pos.y = y;
  button->action = func;
  button->hover = 0;
  bg = bunny_new_pixelarray(500, 70);
  coloring(bg, 0x322B00);
  parall(bg, 0xE3F6FD);
  button->background = bg;
  pos.x = 220;
  pos.y = 7;
  write_text(bg, label, &pos);
  return (button);
}

void		add_button(char *label, t_lst *to,
			   t_bunny_response (*func)(void *, int))
{
  while (to->next)
    to = to->next;
  to->next = new_button(label, to->pos.x, to->pos.y + 100, func);
}

void			disp_elems(t_params *params, t_lst *element)
{
  t_bunny_pixelarray	*glitched;

  glitched = NULL;
  while (element)
    {
      if (element->hover)
	glitched = glitch(element->background);
      blit(&params->window->buffer,
	   glitched,
	   element,
	   params->config.oculus);
      if (element->hover)
	bunny_delete_clipable(&glitched->clipable);
      element = element->next;
    }
}

void	next_elem(t_lst *menu)
{
  t_lst	*curr;

  curr = menu;
  while (curr)
  {
    if (curr->hover)
      {
	if (curr->next)
	  curr->next->hover = !(curr->hover = 0);
	else
	  menu->hover = !(curr->hover = 0);
	break;
      }
    curr = curr->next;
  }
  if (!curr)
    menu->hover = 1;
}

void	prev_elem(t_lst *menu)
{
  t_lst	*prev;
  t_lst	*curr;

  prev = NULL;
  curr = menu;
  while (curr)
  {
    prev = curr;
    curr = curr->next;
  }
  curr = menu;
  while (curr)
  {
    if (curr->hover)
      {
	prev->hover = !(curr->hover = 0);
	break;
      }
    prev = curr;
    curr = curr->next;
  }
  if (!curr)
    prev->hover = 1;
}
