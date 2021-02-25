/*
 * File: AndGate.cpp
 * Project: And
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 6:54:25 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "AndGate.hpp"

using namespace nts;

AndGate::AndGate(Input &a, Input &b) : Gate(a, b)
{
}

Tristate AndGate::compute(void)
{
    Tristate a = _a ? _a->getState() : UNDEFINED;
    Tristate b = _b ? _b->getState() : UNDEFINED;

    return a & b;
}