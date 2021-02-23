/*
 * File: tristateOperators.cpp
 * Project: nts::Tristate
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 4:20:03 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "TristateOperators.hpp"

nts::Tristate operator&(const nts::Tristate &a, const nts::Tristate &b)
{
    if (a == nts::FALSE || b == nts::FALSE)
        return nts::FALSE;
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::TRUE;
}

nts::Tristate operator|(nts::Tristate const &a, nts::Tristate const &b)
{
    if (a == nts::TRUE || b == nts::TRUE)
        return nts::TRUE;
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::FALSE;
}

nts::Tristate operator^(const nts::Tristate &a, const nts::Tristate &b)
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    if ((a == nts::TRUE || b == nts::TRUE) && a != b)
        return nts::TRUE;
    return nts::FALSE;
}

nts::Tristate operator!(const nts::Tristate &a)
{
    if (a == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (a)
        return nts::FALSE;
    return nts::TRUE;
}
