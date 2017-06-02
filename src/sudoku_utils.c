/*
** sudoku_utils.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 21:17:59 2017 Fantin Bibas
** Last update Fri Jun  2 12:33:44 2017 Fantin Bibas
*/

#include "sudoku_utils.h"

char	get_cell(t_sudoku_cell cell)
{
  if (cell[1])
    return (0);
  return (cell[0]);
}

int	is_line_char_possible(t_sudoku *sudoku, int line, char c)
{
  int	i;

  i = - 1;
  while (++i < sudoku->size)
    if (get_cell(sudoku->sudoku[i][line]) == c)
      return (0);
  return (1);
}

int	is_column_char_possible(t_sudoku *sudoku, int col, char c)
{
  int	i;

  i = - 1;
  while (++i < sudoku->size)
    if (get_cell(sudoku->sudoku[col][i]) == c)
      return (0);
  return (1);
}

int	is_field_char_possible(t_sudoku *sudoku, int i, int j, char c)
{
  int	io;
  int	jo;

  i -= i % sudoku->sqr;
  j -= j % sudoku->sqr;
  io = -1;
  while (++io < sudoku->sqr)
    {
      jo = -1;
      while (++jo < sudoku->sqr)
	if (get_cell(sudoku->sudoku[i + io][j + jo]) == c)
	  return (0);
    }
  return (1);
}

int	is_char_possible(t_sudoku *sudoku, int i, int j, char c)
{
  if (!is_line_char_possible(sudoku, j, c) ||
      !is_column_char_possible(sudoku, i, c) ||
      !is_field_char_possible(sudoku, i, j, c))
    return (0);
  return (1);
}
