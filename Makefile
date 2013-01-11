NAME	=	gtk
SRCS	=	main.c				\
		init.c				\
		terrain_coord.c			\
		check_verti_haut.c		\
		check_verti_haut_white.c	\
		check_verti_bas_white.c		\
		check_verti_bas.c		\
		horizontal_black.c		\
		horizontal_white.c		\
		vertical_black.c		\
		diagonal_black.c		\
		diagonal_white.c		\
		tools_diagonal_black_top.c	\
		tools_diagonal_white_top.c	\
		tools_diagonal_black_bot.c	\
		tools_diagonal_white_bot.c	\
		check_end_line.c		\
		check_case.c			\
		tools_check.c			\

OBJS	=	$(SRCS:.c=.o)
LDFLAGS	= `pkg-config --libs gtk+-2.0`
CFLAGS	= -Wall -W -Werror `pkg-config --cflags gtk+-2.0`

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

distclean:	clean
	rm -f $(NAME)

rebuild:	distclean all

debug: CFLAGS += -D___DEBUG -g3
debug: rebuild
