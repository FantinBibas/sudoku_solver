/*
** main.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 19:49:12 2017 Fantin Bibas
** Last update Thu Jun  1 22:18:04 2017 Fantin Bibas
*/

#include "main.h"

int	line_parse(t_sudoku sudoku, char *input, int line, const char *alphabet)
{
  int	i;
  uint	size;
  int	j;

  size = strlen(alphabet);
  if (strlen(input) != size)
    return (i_err("The line is not at the good size", -1));
  i = -1;
  while (++i < (int)size)
    if (input[i] != '0')
      {
	j = i;
	while (input[++j])
	  if (input[i] == input[j])
	    return (i_err("The line is invalid (doublon)", -1));
	set_good_cell(sudoku[line][i], input[i], MAP_REA);
      }
  return (0);
}

const char	*check_alphabet(const char *alphabet)
{
  int		i;
  int		j;
  uint		size;
  double	sqr;

  i = -1;
  while (alphabet[++i])
    {
      j = i;
      while (alphabet[++j])
	if (alphabet[i] == alphabet[j] || alphabet[i] == '0')
	  return (n_err("The chars must be unique and must not be 0"));
    }
  size = strlen(alphabet);
  sqr = sqrt((double)size);
  if (sqr != (int)sqr)
    return (n_err("The lenght of the alphabet is not a perfect square"));
  return (alphabet);
}

int		main(int ac, char **av)
{
  t_sudoku	sudoku;
  int		i;
  char		*input;
  const char	*alphabet;
  uint		size;

  alphabet = DEFAULT_ALPHA;
  if ((ac > 1 && (alphabet = check_alphabet(av[1])) == NULL) ||
      (sudoku = create_sudoku(alphabet)) == NULL)
    return (84);
  size = strlen(alphabet);
  i = -1;
  while (++i < (int)size && (input = get_next_line(0)) != NULL)
    if (line_parse(sudoku, input, i, alphabet))
      i--;
  display_sudoku(sudoku, alphabet);
  return (0);
}
