/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

using namespace nts;

bool Parser::emptyLine(std::string &str)
{
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if ((*it) != ' ')
            return false;
    }
    return true;
}

void Parser::cleanComment(std::list<std::string> &file)
{
    std::list<std::string>::iterator tmp;
    size_t found = 0;

    for (std::list<std::string>::iterator it = file.begin(); it != file.end();) {
        found = (*it).find(COMMENT);
        if (found == 0 || Parser::emptyLine(*it)) {
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

std::list<std::string> Parser::readFile(const std::string &filepath)
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
    Parser::cleanComment(all_file);
    return all_file;
}

void Parser::chipsetLoad(std::map<std::string, std::string> mapChipsets, Circuit &dest)
{
    FactoryComponent *factory = new FactoryComponent();
    IComponent *node = nullptr;
    std::unique_ptr<nts::IComponent> tmp;

    for (const auto& it : mapChipsets) {
        std::cout << it.first << " = " << it.second << ";" << std::endl;
        node = nullptr;
        if (it.second == "input") {
            node = new Component(it.first, INPUT);
        } else if (it.second == "output") {
            node = new Component(it.first, OUTPUT);
        } else {
            tmp = factory->createComponent(it.second);
            node = tmp.release();
        }
        dest.addNode(*node);
    }
    delete factory;
}

void Parser::linkLoad(std::list<std::tuple<std::string, std::string, std::string, std::string>> mapLinks, Circuit &dest)
{
    size_t pinFirst = 0;
    size_t pinSec = 0;

    for (const auto& it : mapLinks) {
        std::cout << std::get<0>(it) << "|" << std::get<1>(it) << "|" << std::get<2>(it) << "|" << std::get<3>(it) << "|" << std::endl;
        try {
            pinFirst = std::stoi(std::get<1>(it).c_str());
            pinSec = std::stoi(std::get<3>(it).c_str());
        } catch (std::invalid_argument const &e) {
            throw ParsingError("Parsing", "is not alphanum");
        } catch (std::out_of_range const &e) {
            throw ParsingError("Parsing", "is too big");
        }
        dest.setNodeLink(std::get<0>(it), pinFirst, std::get<2>(it), pinSec);
        //std::cout << pinFirst << ", " << pinSec << std::endl;
    }
}

void Parser::parsingFile(const std::string &filepath, Circuit &dest)
{
    std::list<std::string> file = Parser::readFile(filepath);
    std::list<std::string>::iterator links = std::find_if(file.begin(), file.end(), [&](std::string str){ return str == LINKS;});
    std::list<std::string>::iterator chipsets = std::find_if(file.begin(),
    file.end(), [&](std::string str){ return str == CHIPSETS;});

    if (links == file.end() || chipsets == file.end())
        throw ParsingError("Parsing", "Wrong format");
    chipsets++;
    std::map<std::string, std::string> mapChipsets = Parser::cutAt(' ', chipsets, links);
    links++;
    std::map<std::string, std::string> mapLinks = Parser::cutAt(' ', links, file.end());
    std::list<std::tuple<std::string, std::string, std::string, std::string>> allLinks = Parser::cleanLink(mapLinks, mapChipsets);

    Parser::chipsetLoad(mapChipsets, dest);
    Parser::linkLoad(allLinks, dest);
}

std::map<std::string, std::string> Parser::cutAt(const char c, std::list<std::string>::iterator start, std::list<std::string>::iterator end)
{
    size_t found;
    std::map<std::string, std::string> map;

    for (std::list<std::string>::iterator it = start; it != end; it++) {
        found = (*it).find(c);
        if (found != std::string::npos) {
            map[(*it).substr(found + 1, (*it).length())] = (*it).substr(0, found);
        } else {
            throw ParsingError("Parsing", "Token not found");
        }
    }
    return map;
}

std::list<std::tuple<std::string, std::string, std::string, std::string>> Parser::cleanLink(
    std::map<std::string, std::string> mapLinks,
    std::map<std::string, std::string> mapChipsets
)
{
    size_t found_one;
    size_t found_two;
    std::string one;
    std::string two;
    std::string three;
    std::string four;
    std::list<std::tuple<std::string, std::string, std::string, std::string>> tuple;

    for (const auto& m : mapLinks) {
        found_one = (m.first).find(TOKEN);
        found_two = (m.second).find(TOKEN);
        if (found_one == std::string::npos || found_two == std::string::npos)
            throw ParsingError("Parsing", "Token not found links");
        one = (m.first).substr(0, found_one);
        two = (m.first).substr(found_one + 1, (m.first).length());
        three = (m.second).substr(0, found_two);
        four = (m.second).substr(found_two + 1, (m.second).length());
        if (mapChipsets.find(one) == mapChipsets.end() || mapChipsets.find(three) == mapChipsets.end())
            throw ParsingError("Parsing", "Undifined variable");
        tuple.push_back(make_tuple(one, two, three, four));
    }
    return tuple;
}