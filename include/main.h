/*********************************************\
|*   Header created by AutoHeader v. 0.6.3   *|
|* https://github.com/FantinBibas/autoHeader *|
\*********************************************/

#ifndef MAIN_H_
#  define MAIN_H_

#  include <stdlib.h>
#  include <math.h>
#  include <stdio.h>
#  include <string.h>
#  include "t_sudoku.h"

int           create_sudoku(t_sudoku *);
int           display_sudoku(t_sudoku *, int);
int           i_err(const char *, int);
void          solve_sudoku(t_sudoku *);
void          *n_err(const char *);
void          set_good_cell(t_sudoku_cell, char, char);
char          *get_next_line(const int);

#endif