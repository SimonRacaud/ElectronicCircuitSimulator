/*
 * File: Gate.cpp
 * Project: Gate
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 4:11:41 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "Gate.hpp"

using namespace nts;

Gate::Gate(Input &a, Input &b, Output &out) : _a(&a), _b(&b), _out(&out)
{
}

Gate::~Gate()
{
}
