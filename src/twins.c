/*
** twins.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Fri Jun  2 13:00:33 2017 Fantin Bibas
** Last update Fri Jun  2 17:16:00 2017 Fantin Bibas
*/

#include "twins.h"

int	field_col_twins(t_sudoku *sudoku, int yf, int x)
{
  int	yo;
  int	i;
  int	total;
  int	j;

  total = 0;
  yo = -1;
  while (++yo < sudoku->sqr && (i = -1) == -1)
    {
      if (!sudoku->sudoku[yf * sudoku->sqr + yo][x][1])
	continue ;
      while (sudoku->sudoku[yf * sudoku->sqr + yo][x][++i])
	if (is_field_col_possibility(sudoku, yf, x,
				     sudoku->sudoku[yf * sudoku->sqr + yo]
				     [x][i]))
	  {
	    j = -1;
	    while (++j < sudoku->size)
	      if (j < yf * sudoku->sqr ||
		  j >= yf * sudoku->sqr + sudoku->sqr)
		total += remove_possibility(sudoku->sudoku[j][x],
					    sudoku->sudoku[yf * sudoku->sqr +
							   yo][x][i]);
	  }
    }
  return (total);
}
  
int	field_line_twins(t_sudoku *sudoku, int xf, int y)
{
  int	xo;
  int	i;
  int	total;
  int	j;

  total = 0;
  xo = -1;
  while (++xo < sudoku->sqr && (i = -1) == -1)
    {
      if (!sudoku->sudoku[y][xf * sudoku->sqr + xo][1])
	continue ;
      while (sudoku->sudoku[y][xf * sudoku->sqr + xo][++i])
	if (is_field_line_possibility(sudoku, xf, y, sudoku->sudoku[y]
				      [xf * sudoku->sqr + xo] [i]))
	  {
	    j = -1;
	    while (++j < sudoku->size)
	      if (j < xf * sudoku->sqr ||
		  j >= xf * sudoku->sqr + sudoku->sqr)
		total += remove_possibility(sudoku->sudoku[y][j],
					    sudoku->sudoku[y]
					    [xf * sudoku->sqr + xo][i]);
	  }
    }
  return (total);
}

int	twins_elimination(t_sudoku *sudoku)
{
  int	total;
  int	i;
  int	j;
  int	k;

  total = 0;
  i = -1;
  while (++i < sudoku->sqr)
    {
      j = -1;
      while (++j < sudoku->sqr)
	{
	  k = -1;
	  while (++k < sudoku->sqr)
	    {
	      total += field_col_twins(sudoku, j, i * sudoku->sqr + k);
	      total += field_line_twins(sudoku, j, i * sudoku->sqr + k);
	    }	  
	}
    }
  printf("Twins removed %i possibilities\n", total);
  return (total);
}
