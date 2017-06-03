/*********************************************\
|*   Header created by AutoHeader v. 0.6.3   *|
|* https://github.com/FantinBibas/autoHeader *|
\*********************************************/

#ifndef MAIN_H_
#  define MAIN_H_

#  include <stdio.h>
#  include <math.h>
#  include <string.h>
#  include <stdlib.h>
#  include "t_sudoku.h"

int           parse_flags(t_sudoku *, int, const char **);
void          solve_sudoku(t_sudoku *);
int           create_sudoku(t_sudoku *);
void          *n_err(const char *);
char          *get_next_line(const int);
void          set_good_cell(t_sudoku_cell, char, char);
int           display_sudoku(t_sudoku *);
int           i_err(const char *, int);

#endif