/*********************************************\
|*   Header created by AutoHeader v. 0.6.3   *|
|* https://github.com/FantinBibas/autoHeader *|
\*********************************************/

#ifndef MAIN_H_
#  define MAIN_H_

#  include <math.h>
#  include <stdio.h>
#  include <string.h>
#  include <stdlib.h>
#  include "t_sudoku.h"

int           only_possibility(t_sudoku *);
int           display_sudoku(t_sudoku *);
int           is_sudoku_ok(t_sudoku *);
int           simple_elimination(t_sudoku *);
int           i_err(const char *, int);
void          set_good_cell(t_sudoku_cell, char, char);
char          *get_next_line(const int);
int           create_sudoku(t_sudoku *);
void          *n_err(const char *);

#endif