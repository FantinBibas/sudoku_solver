/*
** only_possibility.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Fri Jun  2 11:47:41 2017 Fantin Bibas
** Last update Sat Jun  3 12:27:01 2017 Fantin Bibas
*/

#include "only_possibility.h"

int	line_possibility(t_sudoku *sudoku, int line, int col)
{
  int	i;
  int	j;

  if (!sudoku->sudoku[line][col][1])
    return (0);
  i = -1;
  while (sudoku->sudoku[line][col][++i])
    {
      j = -1;
      while (++j < sudoku->size)
	if (j != col && !is_possibility(sudoku->sudoku[line][j],
					sudoku->sudoku[line][col][i]))
	  break;
      if (j == sudoku->size)
	{
	  set_good_cell(sudoku->sudoku[line][col],
			sudoku->sudoku[line][col][i], POSS_REA);
	  return (1);
	}
    }
  return (0);
}

int	column_possibility(t_sudoku *sudoku, int line, int col)
{
  int	i;
  int	j;

  if (!sudoku->sudoku[line][col][1])
    return (0);
  i = -1;
  while (sudoku->sudoku[line][col][++i])
    {
      j = -1;
      while (++j < sudoku->size)
	if (j != line && !is_possibility(sudoku->sudoku[j][col],
					 sudoku->sudoku[line][col][i]))
	  break;
      if (j == sudoku->size)
	{
	  set_good_cell(sudoku->sudoku[line][col],
			sudoku->sudoku[line][col][i], POSS_REA);
	  return (1);
	}
    }
  return (0);
}

int	field_possibility(t_sudoku *sudoku, int line, int col)
{
  int	i;

  if (!sudoku->sudoku[line][col][1])
    return (0);
  i = -1;
  while (sudoku->sudoku[line][col][++i])
    if (is_field_possibility(sudoku, line, col, sudoku->sudoku[line][col][i]))
      {
	set_good_cell(sudoku->sudoku[line][col],
		      sudoku->sudoku[line][col][i], POSS_REA);
	return (1);
      }
  return (0);
}

int	possibility_pass(t_sudoku *sudoku)
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
	{
	  total += line_possibility(sudoku, i, j);
	  total += column_possibility(sudoku, i, j);
	  total += field_possibility(sudoku, i, j);
	}
    }
  return (total);
}

int	only_possibility(t_sudoku *sudoku)
{
  int	i;

  i = 0;
  while (possibility_pass(sudoku))
    i++;
  if (sudoku->verbose)
    printf("Possibility: %i pass\n", i + 1);
  return (i);
}
