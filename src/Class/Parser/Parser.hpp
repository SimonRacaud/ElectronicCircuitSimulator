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
            static void loadLinks(
                std::list<std::string>::iterator start,
                std::list<std::string>::iterator end,
                std::map<std::string, ssize_t> &map_input,
                std::map<std::string, ssize_t> &map_output);
            static std::map<std::string, ssize_t> loadSinceName(std::string key,
                std::list<std::string>::iterator start,
                std::list<std::string>::iterator end);
    };
}

#endif