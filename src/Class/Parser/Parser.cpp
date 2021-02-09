/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

static bool strIsNum(const std::string &str)
{
    for (char const &c : str)
        if (c >= '0' && c <= '9')
            return false;
    return true;
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
    std::map<std::string, ssize_t> map_input = nts::Parser::loadSinceName(INPUT, chipsets, links);
    std::map<std::string, ssize_t> map_output = nts::Parser::loadSinceName(OUTPUT, chipsets, links);
    //std::cout << "input: " << map_input.size() << std::endl;
    //std::cout << "output: " << map_output.size() << std::endl;
    if (map_output.size() + map_input.size() + 1 != (size_t) std::distance(chipsets, links))
        throw ParsingError("Parsing", "too much line in chipset");
    links++;
    nts::Parser::loadLinks(links, file.end(), map_input, map_output);
    for (const auto& m : map_input) {
        std::cout << m.first << " = " << m.second << ";" << std::endl;
    }
    for (const auto& m : map_output) {
        std::cout << m.first << " = " << m.second << ";" << std::endl;
    }
}

void nts::Parser::loadLinks(
std::list<std::string>::iterator start,
std::list<std::string>::iterator end,
std::map<std::string, ssize_t> &map_input,
std::map<std::string, ssize_t> &map_output)
{
    std::string key;
    std::string key_next;
    size_t found;
    size_t found_next;

    for (std::list<std::string>::iterator it = start; it != end; it++) {
        found = (*it).find(TOKEN);
        found_next = (found != std::string::npos) ? (*it).find(" gate:", found + 1) + 6 : std::string::npos;
        if (found != std::string::npos && found_next != std::string::npos) {
            std::cout << (*it).substr(0, found) << " in " << (*it) << std::endl;
            key = (*it).substr(0, found);
            key_next = (*it).substr(found_next, (*it).length());
            std::cout << "next: '" << key_next << "'" << " in " << (*it) << std::endl;
            if (strIsNum(key_next))
                throw ParsingError("Parsing", "Key is not Num");
            if (map_input.find(key) != map_input.end()) {
                //std::cout << "input: " << key << std::endl;
                map_input[key] = atoi(key_next.c_str());
            } else if (map_output.find(key) != map_output.end()) {
                //std::cout << "output: " << key << std::endl;
                map_output[key] = atoi(key_next.c_str());
            } else {
                throw ParsingError("Parsing", "Variable name not define");
            }
        } else {
            throw ParsingError("Parsing", "no parser Token");
        }
    }
}

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

std::map<std::string, ssize_t> nts::Parser::loadSinceName(std::string key,
std::list<std::string>::iterator start, std::list<std::string>::iterator end)
{
    std::map<std::string, ssize_t> links;
    std::string tmp;
    size_t found;

    for (std::list<std::string>::iterator it = start; it != end; it++) {
        found = (*it).find(key);
        if (found != std::string::npos) {
            tmp = (*it).erase(0, key.length());
            links.insert({tmp, -1});
        }
    }
    return links;
}