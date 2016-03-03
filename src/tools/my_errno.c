/*
** my_errno.c for tekdoom in /home/asphahyre/rendu/gfx_tekdoom/src/my_errno
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Mon Jan 11 23:28:26 2016 Luka Boulagnon
** Last update Sun Jan 17 11:52:21 2016 Luka Boulagnon
*/

#include "my_errno.h"

static const char	*err[] = {
  "Everything visibly okay",
  "You really are a genious to make the worse mistake of the world",
  "No such file or directory",
  "Corrupted file",
  "Invalid malloc"
};

const char	*my_strerrno(int error)
{
  return (err[error]);
}
