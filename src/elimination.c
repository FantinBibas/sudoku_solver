/*
** elimination.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 22:45:13 2017 Fantin Bibas
** Last update Fri Jun  2 12:31:10 2017 Fantin Bibas
*/

#include "elimination.h"

int	eliminate_cell(t_sudoku *sudoku, int i, int j)
{
  int	k;

  if (sudoku->sudoku[i][j][1] == 0)
    return (0);
  k = -1;
  while (sudoku->sudoku[i][j][++k])
    {
      if (!is_char_possible(sudoku, i, j, sudoku->sudoku[i][j][k]))
	decay_str(sudoku->sudoku[i][j] + k--);
      if (sudoku->sudoku[i][j][1] == 0)
	break;
    }
  if (sudoku->sudoku[i][j][1] != 0)
    return (0);
  sudoku->sudoku[i][j][2] = FOUND_REA;
  return (1);
}

int	elimination_pass(t_sudoku *sudoku)
{
  int	i;
  int	j;
  int	total;

  total = 0;
  i = -1;
  while (++i < sudoku->size)
    {
      j = -1;
      while (++j < sudoku->size)
	total += eliminate_cell(sudoku, i, j);
    }
  return (total);
}

int	simple_elimination(t_sudoku *sudoku)
{
  int	i;

  i = 0;
  while (elimination_pass(sudoku))
    i++;
  printf("Elimination: %i pass\n", i + 1);
  return (i);
}
