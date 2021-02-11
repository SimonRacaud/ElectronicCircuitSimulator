/*
 * File: EmptyCircuitException.hpp
 * Project: Exception
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Monday, 8th February 2021 8:58:46 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef EMPTYCIRCUIT_HPP_
#define EMPTYCIRCUIT_HPP_

#include "Error/Error.hpp"

class EmptyCircuitException : public ManageError {
  public:
    EmptyCircuitException(std::string const &message = "Standard", std::string const &component = "Initialisation") : ManageError(message, component)
    {
    }
};

#endif