/*********************************************\
|*   Header created by AutoHeader v. 0.6.3   *|
|* https://github.com/FantinBibas/autoHeader *|
\*********************************************/

#ifndef MAIN_H_
#  define MAIN_H_

#  include <stdlib.h>
#  include <math.h>
#  include <string.h>
#  include "t_sudoku.h"

int           display_sudoku(t_sudoku, const char *);
void          set_good_cell(t_sudoku_cell, char, char);
void          *n_err(const char *);
t_sudoku      create_sudoku(const char *);
char          *get_next_line(const int);
int           i_err(const char *, int);

#endif