/*
 * File: Gate.hpp
 * Project: Gate
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 4:05:30 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef H_GATE
#define H_GATE

#include "IComponent.hpp"
#include "Modele/Input/Input.hpp"
#include "Modele/Output/Output.hpp"

namespace nts
{
    class Gate {
      public:
        Gate(Input &a, Input &b, Output &out);
        virtual ~Gate();

        virtual void updateOutput(void) = 0;

      protected:
        Input *_a;
        Input *_b;
        Output *_out;
    };
} // namespace nts

#endif