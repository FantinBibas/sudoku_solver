/*
** error.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 22:10:03 2017 Fantin Bibas
** Last update Thu Jun  1 22:12:10 2017 Fantin Bibas
*/

#include "error.h"

int	i_err(const char *err_msg, int return_value)
{
  write(2, err_msg, strlen(err_msg));
  write(2, "\n", 1);
  return (return_value);
}

void	*n_err(const char *err_msg)
{
  write(2, err_msg, strlen(err_msg));
  return (NULL);
}
