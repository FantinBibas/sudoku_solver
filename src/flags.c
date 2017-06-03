/*
** flags.c for Sudoku in /home/neodar/Epitech/CPE_2016/epitech_CPE_2016_sudoku
** 
** Made by Fantin Bibas
** Login   <fantin.bibas@epitech.eu@epitech.net>
** 
** Started on  Sat Jun  3 12:02:23 2017 Fantin Bibas
** Last update Sat Jun  3 12:25:27 2017 Fantin Bibas
*/

#include "flags.h"

int	disp_help(const char *program)
{
  printf("USAGE:\n\t%s [-a 123456789] [-v] [-h]\nDESCRIPTION:\n", program);
  printf("\t-a 123456789\tSet the alphabet to use (def. \"123456789\")\n");
  printf("\t-v\t\tVerbose mode\n");
  printf("\t-h\t\tDisplay this help\n");
  return (1);
}

int	unknown_arg(const char *arg)
{
  printf("Unknown argument \"%s\".\n", arg);
  return (-1);
}

int	missing_alpha()
{
  printf("Argument -a needs an alphabet argument after it. (-h for help)\n");
  return (-1);
}

int	parse_flags(t_sudoku *sudoku, int ac, const char **av)
{
  int	i;

  i = 0;
  while (++i < ac)
    if (i < ac - 1 && !strcmp(av[i], "-a"))
      {
	if (!(sudoku->alphabet = check_alphabet(av[++i])))
	  return (-1);
      }
    else if (!strcmp(av[i], "-a"))
      return (missing_alpha());
    else if (!strcmp(av[i], "-h"))
      return (disp_help(av[0]));
    else if (!strcmp(av[i], "-v"))
      sudoku->verbose = 1;
    else
      return (unknown_arg(av[i]));
  return (0);
}
