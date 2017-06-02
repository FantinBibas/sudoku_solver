/*
** sudoku_utils2.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Fri Jun  2 11:51:00 2017 Fantin Bibas
** Last update Fri Jun  2 12:42:48 2017 Fantin Bibas
*/

#include "sudoku_utils2.h"

int	is_sudoku_ok(t_sudoku *sudoku)
{
  int	i;
  int	j;

  i = -1;
  while (++i < sudoku->size)
    {
      j = -1;
      while (++j < sudoku->size)
	if (sudoku->sudoku[i][j][1] != 0)
	  return (0);
    }
  return (1);
}

int	is_possibility(t_sudoku_cell cell, char c)
{
  int	i;

  i = -1;
  while (cell[++i])
    if (cell[i] == c)
      return (0);
  return (1);
}

int	is_field_possibility(t_sudoku *sudoku, int i, int j, char c)
{
  int	x;
  int	y;
  int	io;
  int	jo;

  x = i - i % sudoku->sqr;
  y = j - j % sudoku->sqr;
  io = -1;
  while (++io < sudoku->sqr)
    {
      jo = -1;
      while (++jo < sudoku->sqr)
	if ((x + io != i || y + jo != j) &&
	    !is_possibility(sudoku->sudoku[x + io][y + jo], c))
	  return (0);
    }
  return (1);
}
