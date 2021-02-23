##
## EPITECH PROJECT, 2021
## makefile
## File description:
## project makefile
##

SRC =   src/main.cpp																\
		src/Class/Circuit/Circuit.cpp												\
		src/Class/Parser/Parser.cpp													\
		src/Class/Exception/Error/Error.cpp											\
		src/Class/CommandLine/CommandLine.cpp										\
		src/Modele/Output/Output.cpp												\
		src/Modele/Input/Input.cpp													\
		src/Modele/ComponentContent/ComponentContent.cpp							\
		src/Operator/Tristate/TristateOperators.cpp									\
		src/Class/Gate/Gate.cpp														\
		src/Class/Gate/Or/OrGate.cpp												\
		src/Class/Gate/And/AndGate.cpp												\
		src/Class/Gate/Not/NotGate.cpp												\
		src/Class/Gate/Xor/XorGate.cpp												\
		$(addprefix $(DIR_COMPONENT), $(SRC_COMPONENT))																				\

DIR_COMPONENT = src/Class/Component

SRC_COMPONENT = /Component.cpp											\
				/Output/OutputComponent.cpp								\
				/Input/InputComponent.cpp								\
				/Input/ClockComponent/ClockComponent.cpp				\
				/Input/FalseComponent/FalseComponent.cpp				\
				/Input/TrueComponent/TrueComponent.cpp					\
				/Output/LoggerComponent/LoggerComponent.cpp				\
				/Factory/Factory.cpp									\
				/Other/4001/C4001.cpp									\
				/Other/4011/C4011.cpp									\
				/Other/4030/C4030.cpp									\
				/Other/4069/C4069.cpp									\
				/Other/4071/C4071.cpp									\
				/Other/4081/C4081.cpp									\

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