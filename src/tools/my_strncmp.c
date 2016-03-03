/*
** my_strncmp.c for Tekdoom in /gfx_tekdoom/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 15 19:01:40 2016 Antoine Baché
** Last update Fri Jan 15 19:02:14 2016 Antoine Baché
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j == 0 && s1[i] && s2[i] && i < n)
    {
      if (s1[i] != s2[i])
	j = s1[i] - s2[i];
      i = i + 1;
    }
  return (j);
}
