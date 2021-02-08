/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include "Class/Error/ParsingError.hpp"
#include "Class/Circuit/Circuit.hpp"

namespace nts
{
    class Parser
    {
        public :
            static void parsing_file(const std::string &filepath, nts::Circuit &dest);
    };
}

#endif