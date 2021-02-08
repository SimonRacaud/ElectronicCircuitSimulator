/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Parser.hpp
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>
#include <exception>

class ManageError : public std::exception {
  public:
    ManageError(std::string const &message, std::string const &component = "Unknown");
    std::string const &getComponent() const;
    const char *what() const noexcept override;

  protected:
    std::string _component;

  private:
    std::string _message;
};

#endif