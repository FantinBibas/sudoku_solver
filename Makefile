## /*********************************************\
## |*  Makefile created by AutoHeader v. 0.6.3  *|
## |* https://github.com/FantinBibas/autoHeader *|
## \*********************************************/

CC	=	gcc

RM	=	rm -f

FLAGS	+=	-lm -Wall -Wextra

CPPFLAGS	+=	-I include/ -Wall -Wextra

NAME	=	sudoku

SRCS	=	src/create_sudoku.c	\
		src/display.c	\
		src/elimination.c	\
		src/error.c	\
		src/get_next_line.c	\
		src/main.c	\
		src/my_string.c	\
		src/only_possibility.c	\
		src/solve.c	\
		src/sudoku_utils.c	\
		src/sudoku_utils2.c	\
		src/sudoku_utils3.c	\
		src/twins.c

OBJDIR	=	objs/

OBJS	=	$(SRCS:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o:	%.c
	mkdir -p $(OBJDIR)
	mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CPPFLAGS)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

