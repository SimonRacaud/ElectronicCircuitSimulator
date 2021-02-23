/*
 * File: NotGate.hpp
 * Project: Not
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 6:54:42 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef H_NOTGATE
#define H_NOTGATE

#include "Class/Gate/Gate.hpp"
#include "Operator/Tristate/TristateOperators.hpp"

namespace nts
{
    class NotGate : public Gate {
      public:
        NotGate(Input &a, Output &out);
        virtual ~NotGate() = default;

        void updateOutput(void);
    };
} // namespace nts

#endif