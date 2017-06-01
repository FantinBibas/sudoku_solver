/*
** sudoku_utils.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 21:17:59 2017 Fantin Bibas
** Last update Thu Jun  1 22:06:04 2017 Fantin Bibas
*/

#include "sudoku_utils.h"

char	get_cell(t_sudoku_cell cell)
{
  if (cell[1])
    return (0);
  return (cell[0]);
}
