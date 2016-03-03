/*
** my_strncpy.c for Tekdoom in /gfx_tekdoom/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan 15 19:02:38 2016 Antoine Baché
** Last update Fri Jan 15 19:02:54 2016 Antoine Baché
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
