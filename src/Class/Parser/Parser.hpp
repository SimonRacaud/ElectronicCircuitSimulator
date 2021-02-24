/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include <algorithm>
#include <fstream>
#include <list>
#include <map>
#include <tuple>
#include "Class/Circuit/Circuit.hpp"
#include "Class/Exception/ParsingError.hpp"
#include "Class/Component/Factory/Factory.hpp"

#define TOKEN    ':'
#define COMMENT  '#'
#define PINPUT   "input "
#define LINKS    ".links:"
#define POUTPUT  "output "
#define CHIPSETS ".chipsets:"

namespace nts
{
    class Parser {
      public:
        static void parsingFile(
            const std::string &filepath, nts::Circuit &dest);

      private:
        static void chipsetLoad(std::map<std::string, std::string> mapChipsets, Circuit &dest);
        static void linkLoad(std::list<std::tuple<std::string, std::string, std::string, std::string>> mapLinks, std::map<std::string, std::string> mapChipsets, Circuit &dest);
        static std::list<std::string> readFile(const std::string &filepath);
        static bool emptyLine(std::string &str);
        static void cleanComment(std::list<std::string> &file);
        static std::map<std::string, std::string> cutAt(const char c,
            std::list<std::string>::iterator start,
            std::list<std::string>::iterator end);
        static std::list<
            std::tuple<std::string, std::string, std::string, std::string>>
        cleanLink(std::map<std::string, std::string> mapLinks,
            std::map<std::string, std::string> mapChipsets);
    };
} // namespace nts

#endif