##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## task01
##

SRC =	src/main.cpp			\

CFLAGS = -std=gnu11 -Wall -Wextra -g

NAME = nanotekspice

OBJ	=	$(SRC:.cpp=.o)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

tests_run:
	echo "No test"
	#g++ -o test $(SRC) -lcriterion --coverage;./test

re:	fclean	all

auteur:
	echo $(USER) > auteur

.PHONY: all clean fclean