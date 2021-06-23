##
## EPITECH PROJECT, 2020
## B-PSU-400-BAR-4-1-malloc-alvaro.garcia-bamala
## File description:
## makefile
##

SRC	=	src/malloc.c \
		src/free.c \
		src/calloc.c \
		src/realloc.c

INCLUDE	=	include/

OBJ	=	$(SRC:.c=.o)

CFLAGS	= 	-c -std=gnu11
CFLAGS	+=	-Wall -Wextra
CFLAGS	+= -fPIC
CFLAGS	+= -I$(INCLUDE)

NAME	=	libmy_malloc.so

TESTDIR	=	bonus/tests
TESTNAME	=	test

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -shared -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(TESTDIR)/$(TESTNAME)

test: all

re: fclean all

tests: all
	gcc -g $(TESTDIR)/test.c -L./ -lmy_malloc -o $(TESTDIR)/$(TESTNAME)
	cd ./bonus/; \
		./tests.sh

.PHONY: all clean fclean re tests
