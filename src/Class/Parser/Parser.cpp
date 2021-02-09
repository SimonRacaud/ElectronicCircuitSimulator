/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

void nts::Parser::cleanComment(std::list<std::string> &file)
{
    std::list<std::string>::iterator tmp;
    size_t found = 0;

    for (std::list<std::string>::iterator it = file.begin(); it != file.end();) {
        found = (*it).find(COMMENT);
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

void nts::Parser::parsingFile(const std::string &filepath, nts::Circuit *dest)
{
    std::list<std::string> file = nts::Parser::readFile(filepath);
    std::list<std::string>::iterator links = std::find_if(file.begin(),
    file.end(), [&](std::string str){ return str == LINKS;});
    std::list<std::string>::iterator chipsets = std::find_if(file.begin(),
    file.end(), [&](std::string str){ return str == CHIPSETS;});

    if (links == file.end() || chipsets == file.end())
        throw ParsingError("Parsing", "Wrong format");
    chipsets++;
    std::map<std::string, std::string> mapChipsets = nts::Parser::cutAt(' ', chipsets, links);
    links++;
    std::map<std::string, std::string> mapLinks = nts::Parser::cutAt(' ', links, file.end());
    //std::tuple<std::string, std::string, std::string, std::string> nts::Parser::cleanLink(mapLinks, mapChipsets);
    /*for (const auto& m : mapChipsets) {
        std::cout << m.first << " = " << m.second << ";" << std::endl;
    }
    for (const auto& m : mapLinks) {
        std::cout << m.first << " = " << m.second << ";" << std::endl;
    }
    std::cout << mapChipsets.size() << "|" << mapLinks.size() << std::endl;*/
}

std::map<std::string, std::string> nts::Parser::cutAt(const char c, std::list<std::string>::iterator start, std::list<std::string>::iterator end)
{
    size_t found;
    std::map<std::string, std::string> map;

    for (std::list<std::string>::iterator it = start; it != end; it++) {
        found = (*it).find(c);
        if (found != std::string::npos) {
            //std::cout << (*it).substr(0, found) << "|" << (*it).substr(found + 1, (*it).length()) << std::endl;
            //map[(*it).substr(0, found)] = (*it).substr(found, (*it).length());
            map[(*it).substr(found, (*it).length())] = (*it).substr(0, found);
        } else {
            throw ParsingError("Parsing", "Token not found");
        }
    }
    return map;
}