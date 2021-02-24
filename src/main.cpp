/*
 * File: main.cpp
 * Project: src
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Saturday, 20th February 2021 10:23:36 am
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "Class/CommandLine/CommandLine.hpp"

int main(int ac, char **av)
{
    nts::CommandLine cl;
    nts::Circuit *circ = new nts::Circuit;

    if (ac == 2) {
        try {
            nts::Parser::parsingFile(av[1], *circ);
        } catch (const ParsingError &e) {
            std::cerr << e.what() << ": " << e.getComponent() << std::endl;
        }
        //circ->dump();
        cl.setCircuit(circ);
        cl.loop();
    }
    //delete circ;
}