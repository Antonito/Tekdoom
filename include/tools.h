/*
** tools.h for Tekdoom in /gfx_tekdoom/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 11 20:32:49 2016 Antoine Baché
** Last update Mon Jan 25 04:13:24 2016 Antoine Baché
*/

#ifndef	TOOLS_H_
# define TOOLS_H_

int	my_put_nbr(int);
char	*my_strncpy(char *, char *, int);
int	my_strncmp(char *, char *, int);
int	my_strcmp(char *, char *);
int	my_getnbr(char *);
char	*my_strdup(char *);
char	*my_strndup(char *, int);
void	my_putchar(char);
void	my_putstr(char *);
int	my_strlen(const char *);
char	*my_strncat(char *, char *, int);
char	*my_strcpy(char *, const char *);
void	my_bzero(void *, int);

#endif	/* !TOOLS_H_ */
