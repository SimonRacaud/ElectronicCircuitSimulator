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

void Parser::cleanLine(std::string &str)
{
    std::string::iterator next;

    for (std::string::iterator it = str.begin(); it != str.end();) {
        next = it + 1;
        if ((*it) == ' ' && it == str.begin()) {
            str.erase(it);
        } else if ((*it) == ' ' && next == str.end()) {
            str.erase(it);
        } else if ((*it) == ' ' && (*next) == ' ') {
            str.erase(it);
        } else
            it++;
    }
}

void Parser::cleanComment(std::list<std::string> &file)
{
    std::list<std::string>::iterator tmp;
    size_t found = 0;

    for (std::list<std::string>::iterator it = file.begin(); it != file.end();) {
        for (std::string::iterator string = (*it).begin(); string != (*it).end(); string++)
            if (iswspace(*string) != 0)
                *string = ' ';
        found = (*it).find(COMMENT);
        if (found == 0 || Parser::emptyLine(*it)) {
            tmp = it;
            it++;
            file.erase(tmp);
        } else if (found != std::string::npos) {
            (*it).erase(found, (*it).length() - found);
            Parser::cleanLine(*it);
            it++;
        } else {
            Parser::cleanLine(*it);
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
        for (size_t i = 0; std::getline(myfile, line) && i < MAXLOAD; i++) {
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
        //std::cout << it.second << ", " << it.first << std::endl;
        tmp = factory->callFactory(it.second, it.first);
        node = tmp.release();
        dest.addNode(*node);
    }
    delete factory;
}

void Parser::linkLoad(std::list<std::tuple<std::string, std::string, std::string, std::string>> mapLinks, std::map<std::string, std::string> mapChipsets, Circuit &dest)
{
    size_t pinFirst = 0;
    size_t pinSec = 0;

    for (const auto& it : mapLinks) {
        //std::cout << std::get<0>(it) << "|" << std::get<1>(it) << "|" << std::get<2>(it) << "|" << std::get<3>(it) << "|" << std::endl;
        try {
            pinFirst = std::stoi(std::get<1>(it).c_str());
            pinSec = std::stoi(std::get<3>(it).c_str());
        } catch (std::invalid_argument const &e) {
            throw ParsingError("Parsing", "is not alphanum");
        } catch (std::out_of_range const &e) {
            throw ParsingError("Parsing", "is too big");
        }
        if (mapChipsets[std::get<0>(it)] == "output")
            dest.setNodeLink(std::get<2>(it), pinSec, std::get<0>(it), pinFirst);
        else
            dest.setNodeLink(std::get<0>(it), pinFirst, std::get<2>(it), pinSec);
    }
}

bool Parser::getSens(std::list<std::string>::iterator links, std::list<std::string>::iterator end)
{
    std::list<std::string>::iterator tmp = std::find_if(links, end, [&](std::string str){ return str == CHIPSETS;});

    if (tmp == end)
        return true;
    return false;
}

void Parser::parsingFile(const std::string &filepath, Circuit &dest)
{
    std::map<std::string, std::string> mapLinks;
    std::map<std::string, std::string> mapChipsets;
    std::list<std::string> file = Parser::readFile(filepath);
    std::list<std::string>::iterator links = std::find_if(file.begin(), file.end(), [&](std::string str){ return str == LINKS;});
    std::list<std::string>::iterator chipsets = std::find_if(file.begin(),
    file.end(), [&](std::string str){ return str == CHIPSETS;});

    if (links == file.end() || chipsets == file.end())
        throw ParsingError("Parsing", "Wrong format");
    if (Parser::getSens(links, file.end())) {
        chipsets++;
        mapChipsets = Parser::cutAt(' ', chipsets, links);
        links++;
        mapLinks = Parser::cutAt(' ', links, file.end());
    } else {
        chipsets++;
        mapChipsets = Parser::cutAt(' ', chipsets, file.end());
        chipsets--;
        links++;
        mapLinks = Parser::cutAt(' ', links, chipsets);
    }
    if (mapChipsets.size() == 0 || mapLinks.size() == 0)
        throw ParsingError("Parsing", "you must have chipsets ans links");
    std::list<std::tuple<std::string, std::string, std::string, std::string>> allLinks = Parser::cleanLink(mapLinks, mapChipsets);
    Parser::chipsetLoad(mapChipsets, dest);
    Parser::linkLoad(allLinks, mapChipsets, dest);
}

std::map<std::string, std::string> Parser::cutAt(const char c, std::list<std::string>::iterator start, std::list<std::string>::iterator end)
{
    size_t found;
    std::map<std::string, std::string> map;

    for (std::list<std::string>::iterator it = start; it != end; it++) {
        found = std::count((*it).begin(), (*it).end(), c);
        if (found != 1)
            throw ParsingError("Parsing", "Too much token found");
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
    size_t count = 0;
    size_t found_one;
    size_t found_two;
    std::string one;
    std::string two;
    std::string three;
    std::string four;
    std::list<std::tuple<std::string, std::string, std::string, std::string>> tuple;

    for (const auto& m : mapLinks) {
        count = std::count(m.first.begin(), m.first.end(), TOKEN);
        if (count != 1)
            throw ParsingError("Parsing", "format error");
        count = std::count(m.second.begin(), m.second.end(), TOKEN);
        if (count != 1)
            throw ParsingError("Parsing", "format error");
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
        if (Parser::emptyLine(one) || Parser::emptyLine(two) || Parser::emptyLine(three) || Parser::emptyLine(four))
            throw ParsingError("Parsing", "Error link");
        tuple.push_back(make_tuple(three, four, one, two));
    }
    return tuple;
}