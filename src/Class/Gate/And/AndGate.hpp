/*
 * File: OrGate.hpp
 * Project: Or
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 4:13:09 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef H_ANDGATE
#define H_ANDGATE

#include "Class/Gate/Gate.hpp"
#include "Operator/Tristate/TristateOperators.hpp"

namespace nts
{
    class AndGate : public Gate {
      public:
        AndGate(Input &a, Input &b);
        virtual ~AndGate() = default;

        Tristate compute(void);
    };
} // namespace nts

#endif