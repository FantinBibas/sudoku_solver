/*
** create_sudoku.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 19:55:11 2017 Fantin Bibas
** Last update Thu Jun  1 22:17:39 2017 Fantin Bibas
*/

#include "create_sudoku.h"

void	set_good_cell(t_sudoku_cell cell, char num, char reason)
{
  cell[0] = num;
  cell[1] = 0;
  cell[2] = reason;
}

void	set_cell(t_sudoku_cell cell, const char *poss)
{
  int	i;

  i = -1;
  while (poss[++i])
    cell[i] = poss[i];
  cell[i] = 0;
}

t_sudoku_cell	get_full_cell(const char *alphabet, int size)
{
  t_sudoku_cell	cell;

  if ((cell = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  set_cell(cell, alphabet);
  return (cell);
}

t_sudoku	create_sudoku(const char *alphabet)
{
  t_sudoku	sudoku;
  int		i;
  int		j;
  int		size;

  size = strlen(alphabet);
  if ((sudoku = malloc(sizeof(char **) * size)) == NULL)
    return (NULL);
  i = -1;
  while (++i < size)
    {
      if ((sudoku[i] = malloc(sizeof(char *) * size)) == NULL)
	return (NULL);
      j = -1;
      while (++j < size)
	if ((sudoku[i][j] = get_full_cell(alphabet, size)) == NULL)
	  return (NULL);
    }
  return (sudoku);
}
