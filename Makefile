##
## EPITECH PROJECT, 2021
## makefile
## File description:
## project makefile
##

SRC =   src/main.cpp																\
		src/Class/Circuit/Circuit.cpp												\
		src/Class/Component/Component.cpp											\
		src/Class/Component/Output/OutputComponent.cpp								\
		src/Class/Component/Input/InputComponent.cpp								\
		src/Class/Component/Input/ClockComponent/ClockComponent.cpp					\
		src/Class/Component/Input/FalseComponent/FalseComponent.cpp					\
		src/Class/Component/Input/TrueComponent/TrueComponent.cpp					\
		src/Class/Parser/Parser.cpp													\
		src/Class/Exception/Error/Error.cpp											\
		src/Class/CommandLine/CommandLine.cpp										\
		src/Modele/Output/Output.cpp												\
		src/Modele/ComponentContent/ComponentContent.cpp							\
		src/Class/Component/Output/LoggerComponent/LoggerComponent.cpp				\
		src/Class/Component/Factory/Factory.cpp										\

OBJ =   $(SRC:.cpp=.o)

NAME =	nanotekspice

INCLUDE =	-I include -I include/Interface -I src/ -I src/Class/Exception
CXXFLAGS =	$(INCLUDE) -Wall -Wextra -g

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