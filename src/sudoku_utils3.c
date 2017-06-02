/*
** sudoku_utils3.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Fri Jun  2 16:09:28 2017 Fantin Bibas
** Last update Fri Jun  2 16:39:54 2017 Fantin Bibas
*/

#include "sudoku_utils3.h"

int	is_field_line_possibility(t_sudoku *sudoku, int xf, int line, char c)
{
  int	yf;
  int	i;
  int	j;

  yf = (line - line % sudoku->sqr) / sudoku->sqr;
  i = -1;
  while (++i < sudoku->sqr)
    {
      if (yf * sudoku->sqr + i == line)
	continue ;
      j = -1;
      while (++j < sudoku->sqr)
	if (!is_possibility(sudoku->sudoku[yf * sudoku->sqr + i]
			    [xf * sudoku->sqr + j], c))
	  return (0);
    }
  return (1);
}
