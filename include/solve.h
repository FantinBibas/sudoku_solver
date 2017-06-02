/*********************************************\
|*   Header created by AutoHeader v. 0.6.3   *|
|* https://github.com/FantinBibas/autoHeader *|
\*********************************************/

#ifndef SOLVE_H_
#  define SOLVE_H_

#  include <stdio.h>
#  include "t_sudoku.h"

int           is_sudoku_ok(t_sudoku *);
int           simple_elimination(t_sudoku *);
int           only_possibility(t_sudoku *);

#endif