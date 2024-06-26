##
## EPITECH PROJECT, 2023
## Makefiles
## File description:
## solostumper
##

MAIN =		main.c							\

SRC =		src/error_handling.c			\
			src/amazed.c					\
			src/matrix.c					\
			src/display.c					\
			src/free_amazed.c				\
			src/parsing/parsing.c			\
			src/parsing/check_commentary.c	\
			src/parsing/rooms.c				\
			src/parsing/tunnels.c			\
			src/path.c						\
			src/robot_parcour.c				\
			src/my_bfs.c					\

SRCTEST = 	tests/test_lib.c				\
			tests/test_amazed.c

OBJ = $(SRC:.c=.o)	$(MAIN:.c=.o)

OBJTEST = $(SRCTEST:.c=.o)

NAME =		amazed

NAMETEST = 	unit_tests

CFLAGS = -Wall -Wextra -std=c99 -g3

CPPFLAGS	=	-I./include

LDFLAGS = -L./lib/my

LDLIBS = -lmy

CC = gcc

all: buildlib $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

buildlib:
	make -C ./lib/my

buildlibtest: buildlib
	make -C ./lib/my CFLAGS='$(CFLAGS) --coverage'

buildtest: CFLAGS += --coverage
buildtest: buildlibtest $(OBJTEST)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $(NAMETEST) $(OBJTEST) $(SRC) $(LDLIBS)	\
	--coverage -lcriterion

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name "#*#" -delete
	find . -name "vgcore*" -delete
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcov" -delete
	find . -name "coding-style-reports.log" -delete
	find . -name "*.cor" -delete

fclean: clean cleantest
	rm -f $(NAME)
	make fclean -C ./lib/my

cleantest:
		rm -f $(NAMETEST)
		rm -f $(OBJTEST)

re: fclean all

valgrind: buildlib $(OBJ)
	$(CC) -g3 $(LDFLAGS) -o $(NAME) $(OBJ) $(LDLIBS)

unit_tests: buildtest

tests_run: unit_tests
		./unit_tests

.PHONY: all clean fclean re valgrind unit_tests tests_run cleantest
		buildlibtest buildtest buildlib
