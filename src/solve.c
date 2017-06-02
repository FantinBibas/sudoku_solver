/*
** solve.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Fri Jun  2 12:34:01 2017 Fantin Bibas
** Last update Fri Jun  2 12:38:43 2017 Fantin Bibas
*/

#include "solve.h"

void	solve_sudoku(t_sudoku *sudoku)
{
  int	impossible;

  impossible = 0;
  while (!is_sudoku_ok(sudoku) && !impossible)
    {
      impossible = 1;
      impossible = (simple_elimination(sudoku) ? 0 : impossible);
      impossible = (only_possibility(sudoku) ? 0 : impossible);
    }
  if (impossible)
    printf("Can't solve the sudoku\n");
  else
    printf("Sudoku solved!\n");
}
