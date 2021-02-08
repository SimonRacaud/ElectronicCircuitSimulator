/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include <list>
#include <fstream>
#include "Class/Error/ParsingError.hpp"
#include "Class/Circuit/Circuit.hpp"

namespace nts
{
    class Parser
    {
        public :
            static void parsingFile(const std::string &filepath, nts::Circuit &dest);

        private :
            static std::list<std::string> readFile(const std::string &filepath);
            static void cleanComment(std::list<std::string> &file);
    };
}

#endif