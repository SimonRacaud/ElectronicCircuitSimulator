##
## EPITECH PROJECT, 2021
## makefile
## File description:
## project makefile
##

SRC =   src/main.cpp						\
		src/Class/Circuit/Circuit.cpp		\
		src/Class/Component/Component.cpp	\

OBJ =   $(SRC:.cpp=.o)

NAME =	nanotekspice

INCLUDE =	-I include -I include/Interface
CXXFLAGS =	$(INCLUDE) -Wall -Wextra

all:    $(NAME)

$(NAME):    $(OBJ)
		g++ -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(OBJ)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean