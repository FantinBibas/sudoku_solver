/*
** t_sudoku.h for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Thu Jun  1 20:28:11 2017 Fantin Bibas
** Last update Fri Jun  2 12:04:40 2017 Fantin Bibas
*/

#ifndef T_SUDOKU_H_
# define T_SUDOKU_H_

# define DEFAULT_ALPHA	"123456789"
# define READ_SIZE	2048

# define MAP_REA	1
# define FOUND_REA	2
# define POSS_REA	3

typedef struct s_sudoku	t_sudoku;
typedef char*		t_sudoku_cell;

typedef unsigned int	uint;

struct		s_sudoku
{
  int		size;
  int		sqr;
  char		***sudoku;
  const char	*alphabet;
};

#endif /* T_SUDOKU_H_ */
