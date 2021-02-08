/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Error.cpp
*/

#include "Error.hpp"

ManageError::ManageError(std::string const &message, std::string const &component)
    : _component(component), _message(message)
{
}

const char *ManageError::what() const noexcept
{
    return this->_message.c_str();
}

std::string const &ManageError::getComponent() const
{
    return this->_component;
}