/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include <map>
#include <list>
#include <tuple>
#include <fstream>
#include <algorithm>
#include "Class/Exception/ParsingError.hpp"
#include "Class/Circuit/Circuit.hpp"

#define TOKEN ':'
#define COMMENT '#'
#define INPUT "input "
#define LINKS ".links:"
#define OUTPUT "output "
#define CHIPSETS ".chipsets:"

namespace nts
{
    class Parser
    {
        public :
            static void parsingFile(const std::string &filepath, nts::Circuit *dest);

        private :
            static std::list<std::string> readFile(const std::string &filepath);
            static void cleanComment(std::list<std::string> &file);
            static std::map<std::string, std::string> cutAt(const char c, std::list<std::string>::iterator start, std::list<std::string>::iterator end);
            static std::list<std::tuple<std::string, std::string, std::string, std::string>> cleanLink(std::map<std::string, std::string> mapLinks, std::map<std::string, std::string> mapChipsets);
    };
}

#endif