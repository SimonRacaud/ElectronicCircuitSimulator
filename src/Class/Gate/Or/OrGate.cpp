/*
 * File: OrGate.cpp
 * Project: Or
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 4:16:19 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "OrGate.hpp"

using namespace nts;

OrGate::OrGate(Input &a, Input &b) : Gate(a, b)
{
}

Tristate OrGate::compute(void)
{
    Tristate a = _a ? _a->getState() : UNDEFINED;
    Tristate b = _b ? _b->getState() : UNDEFINED;

    return a | b;
}