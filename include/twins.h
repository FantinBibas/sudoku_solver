/*********************************************\
|*   Header created by AutoHeader v. 0.6.3   *|
|* https://github.com/FantinBibas/autoHeader *|
\*********************************************/

#ifndef TWINS_H_
#  define TWINS_H_

#  include <stdio.h>
#  include "t_sudoku.h"

int           is_field_col_possibility(t_sudoku *, int, int, char);
int           is_field_line_possibility(t_sudoku *, int, int, char);
int           remove_possibility(t_sudoku_cell, char);

#endif