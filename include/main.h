/*********************************************\
|*   Header created by AutoHeader v. 0.6.3   *|
|* https://github.com/FantinBibas/autoHeader *|
\*********************************************/

#ifndef MAIN_H_
#  define MAIN_H_

#  include <stdio.h>
#  include <math.h>
#  include <stdlib.h>
#  include <string.h>
#  include "t_sudoku.h"

void          set_good_cell(t_sudoku_cell, char, char);
int           display_sudoku(t_sudoku *, int);
void          *n_err(const char *);
int           create_sudoku(t_sudoku *);
int           i_err(const char *, int);
char          *get_next_line(const int);
void          solve_sudoku(t_sudoku *);

#endif