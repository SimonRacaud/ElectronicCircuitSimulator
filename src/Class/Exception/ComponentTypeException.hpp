/*
 * File: ComponentTypeException.hpp
 * Project: Exception
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Monday, 8th February 2021 9:11:33 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#if !defined(H_COMPONENT_TYPE_EXCEPTION)
#define H_COMPONENT_TYPE_EXCEPTION

#include "Error/Error.hpp"

class ComponentTypeException : public ManageError {
  public:
    ComponentTypeException(std::string const &message = "Standard", std::string const &component = "Initialisation") : ManageError(message, component)
    {
    }
};

#endif // H_COMPONENT_TYPE_EXCEPTION
