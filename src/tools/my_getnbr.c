/*
** my_getnbr.c for Tekdoom in /gfx_tekdoom/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Jan 14 22:36:35 2016 Antoine Baché
** Last update Fri Jan 15 00:04:38 2016 Lucas Troncy
*/

int	my_getnbr(char *str)
{
  int	i;
  int	s;
  long	r;

  i = 0;
  s = 1;
  r = 0;
  while (str[i] == 43 || str[i] == 45)
    {
      if (str[i] == 45)
	s = -s;
      i++;
    }
  str += i;
  i = 0;
  while (str[i] > 47 && str[i] < 58)
    {
      r = r * 10;
      r = r + str[i] - 48;
      i++;
    }
  return (r > 2147483647 || r < -2147483648 ? 0 : s * r);
}
