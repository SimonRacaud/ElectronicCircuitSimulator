/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Parser.hpp
*/

#ifndef PARSINGERROR_HPP_
#define PARSINGERROR_HPP_

#include "Error/Error.hpp"

class ParsingError : public ManageError {
  public:
    ParsingError(std::string const &message = "Standard", std::string const &component = "Initialisation") : ManageError(message, component)
    {
    }
};

#endif