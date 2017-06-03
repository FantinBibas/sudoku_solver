/*********************************************\
|*   Header created by AutoHeader v. 0.6.3   *|
|* https://github.com/FantinBibas/autoHeader *|
\*********************************************/

#ifndef ONLY_POSSIBILITY_H_
#  define ONLY_POSSIBILITY_H_

#  include <stdio.h>
#  include "t_sudoku.h"

int           is_possibility(t_sudoku_cell, char);
int           is_field_possibility(t_sudoku *, int, int, char);
void          set_good_cell(t_sudoku_cell, char, char);

#endif