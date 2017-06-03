/*
** display.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 21:25:16 2017 Fantin Bibas
** Last update Sat Jun  3 12:22:13 2017 Fantin Bibas
*/

#include "display.h"

void	display_cell(t_sudoku_cell cell, int verbose)
{
  char	c;

  if (!(c = get_cell(cell)))
    {
      if (verbose)
	{
	  write(1, "\e[31m", 5);
	  write(1, cell, strlen(cell));
	}
      c = ' ';
    }
  else if (cell[2] == MAP_REA)
    write(1, "\e[39m", 5);
  else if (cell[2] == FOUND_REA)
    write(1, "\e[32m", 5);
  else if (cell[2] == POSS_REA)
    write(1, "\e[35m", 5);
  write(1, &c, 1);
  write(1, "\e[39m", 5);
}

void	disp_sep_line(uint size, uint sqr)
{
  int	i;

  i = -1;
  while (++i < (int)size)
    {
      if (!(i % sqr))
	write(1, "+", 1);
      write(1, "-", 1);
    }
  write(1, "+\n", 2);
}

int	display_sudoku(t_sudoku *sudoku)
{
  int	i;
  int	j;

  i = -1;
  while (++i < sudoku->size)
    {
      if (i % sudoku->sqr == 0)
	disp_sep_line(sudoku->size, sudoku->sqr);
      j = -1;
      while (++j < sudoku->size)
	{
	  if (j % sudoku->sqr == 0)
	    write(1, "|", 1);
	  display_cell(sudoku->sudoku[i][j], sudoku->verbose);
	}
      write(1, "|\n", 2);
    }
  disp_sep_line(sudoku->size, sudoku->sqr);
  write(1, "\n", 1);
  return (0);
}
