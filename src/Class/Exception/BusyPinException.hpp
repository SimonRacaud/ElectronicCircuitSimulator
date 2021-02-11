/*
 * File: UndefinedPinException.hpp
 * Project: Exception
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Monday, 8th February 2021 9:03:14 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef BUSY_PIN_HPP_
#define BUSY_PIN_HPP_

#include "Error/Error.hpp"

class BusyPinException : public ManageError {
  public:
    BusyPinException(std::string const &message = "Standard", std::string const &component = "Initialisation") : ManageError(message, component)
    {
    }
};

#endif