NAME	=	gtk
SRCS	=	main.c	\
		terrain_coord.c	\
		check_verti_haut.c	\
		check_verti_bas.c	\
		horizontal_black.c	\
		horizontal_white.c	\
		check_case.c


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
