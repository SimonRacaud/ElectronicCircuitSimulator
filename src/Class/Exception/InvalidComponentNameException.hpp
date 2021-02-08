/*
 * File: InvalidComponentNameException.hpp
 * Project: Exception
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Monday, 8th February 2021 9:02:35 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef INVALID_COMPONENT_NAME_HPP_
#define INVALID_COMPONENT_NAME_HPP_

#include "Error.hpp"

class InvalidComponentNameException : public ManageError {
  public:
    InvalidComponentNameException(std::string const &message = "Standard", std::string const &component = "Initialisation") : ManageError(message, component)
    {
    }
};

#endif