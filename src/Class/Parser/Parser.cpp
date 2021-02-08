/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

void nts::Parser::parsingFile(const std::string &filepath, nts::Circuit &dest)
{
    std::list<std::string> file = nts::Parser::readFile(filepath);
}

void nts::Parser::cleanComment(std::list<std::string> &file)
{
    std::list<std::string>::iterator tmp;
    size_t found = 0;

    for (std::list<std::string>::iterator it = file.begin(); it != file.end();) {
        found = (*it).find('#');
        if (found == 0 || (*it).length() == 0) {
            tmp = it;
            it++;
            file.erase(tmp);
        } else if (found != std::string::npos) {
            (*it).erase(found, (*it).length() - found);
            it++;
        } else {
            it++;
        }
    }
}

std::list<std::string> nts::Parser::readFile(const std::string &filepath)
{
    std::list<std::string> all_file;
    std::ifstream myfile(filepath);
    std::string line;

    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            all_file.push_back(line);
        }
    } else {
        throw ParsingError("Parsing", "Can't open file");
    }
    nts::Parser::cleanComment(all_file);
    return all_file;
}