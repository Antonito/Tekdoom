/*
** tekdoom.h for Tekdoom in /gfx_tekdoom/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 11 20:32:49 2016 Antoine Baché
** Last update Tue Jan 12 13:18:05 2016 Luka Boulagnon
*/

#ifndef MY_ERRNO_H_
# define MY_ERRNO_H_

int			my_errno;
extern int		my_errno;

const char		*my_strerrno(int error);

#endif	/* !MY_ERRNO_H_ */
