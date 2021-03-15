##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile malloc
##

SRC_TEST	=	tests/test.c	\
			src/malloc.c	\
			src/free.c	\
			src/realloc.c	\
			src/calloc.c	\
			src/reallocarray.c

SRC_LIB		=	src/malloc.c	\
			src/free.c	\
			src/realloc.c	\
			src/calloc.c	\
			src/reallocarray.c

OBJ_TEST	=	$(SRC_TEST:.c=.o)

OBJ_LIB		=	$(SRC_LIB:.c=.o)

NAME_TEST	=	unit_tests

NAME_LIB	=	libmy_malloc.so

CC		=	gcc

RM		=	rm -f

FLAG_TEST	=	--coverage -lcriterion

FLAG_SEC	=	-Wall

all:		$(NAME_LIB)

$(NAME_LIB):	$(OBJ_LIB)
		$(CC) -c $(FLAG_SEC) -fpic $(SRC_LIB)
		mv *.o src/
		$(CC) -shared -o $(NAME_LIB) $(OBJ_LIB)

clean:
		$(RM) $(NAME_MAIN)

fclean:		clean
		$(RM) $(NAME_LIB)
		$(RM) src/*.o
		$(RM) *~

re:		fclean all

tests_run:	$(OBJ_TEST)
		$(CC) -o $(NAME_TEST) $(SRC_TEST) $(FLAG_TEST)
		./$(NAME_TEST)

rm_test:	fclean
		$(RM) $(NAME_TEST)
		$(RM) *.gcda
		$(RM) *.gcno

all_clean:	fclean rm_test

.PHONY:		all clean fclean re lib tests_run rm_test
