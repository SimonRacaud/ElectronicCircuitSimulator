/*
 * File: NotGate.cpp
 * Project: Not
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 6:55:24 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "NotGate.hpp"

using namespace nts;

NotGate::NotGate(Input &a, Output &out) : Gate(a, a, out)
{
}

void NotGate::updateOutput(void)
{
    this->_out->setState(!_a->getState());
}