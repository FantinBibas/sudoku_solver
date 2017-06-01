/*
** get_next_line.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 20:38:24 2017 Fantin Bibas
** Last update Thu Jun  1 20:38:25 2017 Fantin Bibas
*/

#include "get_next_line.h"

char		*my_strcat(char *a, char *b)
{
  int		i;
  int		j;
  char		*c;

  i = -1;
  if (b == NULL)
    return (a);
  while (a[++i] != '\0');
  j = -1;
  while (b[++j] != '\0');
  if ((c = malloc(sizeof(char) * (j + i + 1))) == NULL)
    return (NULL);
  c[i + j] = '\0';
  while (--j >= 0)
    c[i + j] = b[j];
  while (--i >= 0)
    c[i] = a[i];
  return (c);
}

int		extend(char **buffer, int fd)
{
  char		*temp;
  int		i;

  if ((temp = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL ||
      (i = read(fd, temp, READ_SIZE)) <= 0)
    return (1);
  temp[i] = '\0';
  if (*buffer != NULL)
    *buffer = my_strcat(*buffer, temp);
  else
    *buffer = temp;
  return (0);
}

char		*auto_cpy(char **buffer, int i, int end)
{
  char		*result;
  int		j;

  j = i;
  if ((result = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  result[i] = '\0';
  while (--i >= 0)
    result[i] = (*buffer)[i];
  *buffer += j + 1;
  if (end == 1)
    *buffer = NULL;
  return (result);
}

char		*get_next_strline(char **buffer, int end)
{
  int		i;

  i = 0;
  if (*buffer == NULL || *buffer[0] == '\0')
    return (NULL);
  while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
    i++;
  if ((*buffer)[i] == '\n' || end == 1)
    return (auto_cpy(buffer, i, end));
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	*buffer = NULL;
  char		*result;
  int		end;

  end = 0;
  while ((result = get_next_strline(&buffer, end)) == NULL && end == 0)
    end = extend(&buffer, fd);
  if (result == NULL && end == 1)
    return (NULL);
  return (result);
}
