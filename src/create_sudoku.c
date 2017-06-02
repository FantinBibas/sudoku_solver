/*
** create_sudoku.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 19:55:11 2017 Fantin Bibas
** Last update Thu Jun  1 23:13:50 2017 Fantin Bibas
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

int		create_sudoku(t_sudoku *s)
{
  int		i;
  int		j;

  s->size = strlen(s->alphabet);
  s->sqr = sqrt((double)s->size);
  if ((s->sudoku = malloc(sizeof(char **) * s->size)) == NULL)
    return (-1);
  i = -1;
  while (++i < s->size)
    {
      if ((s->sudoku[i] = malloc(sizeof(char *) * s->size)) == NULL)
	return (-1);
      j = -1;
      while (++j < s->size)
	if ((s->sudoku[i][j] = get_full_cell(s->alphabet, s->size)) == NULL)
	  return (-1);
    }
  return (0);
}
