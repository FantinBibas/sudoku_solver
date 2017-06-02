/*
** my_string.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 23:36:46 2017 Fantin Bibas
** Last update Thu Jun  1 23:37:45 2017 Fantin Bibas
*/

#include "my_string.h"

void	decay_str(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    str[i] = str[i + 1];
}
