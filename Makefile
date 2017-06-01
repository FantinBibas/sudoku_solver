## /*********************************************\
## |*  Makefile created by AutoHeader v. 0.6.3  *|
## |* https://github.com/FantinBibas/autoHeader *|
## \*********************************************/

CC	=	gcc

RM	=	rm -f

FLAGS	+=	-Wall -Wextra

CPPFLAGS	+=	-I include/ -Wall -Wextra

NAME	=	sudoku

SRCS	=	src/main.c

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

