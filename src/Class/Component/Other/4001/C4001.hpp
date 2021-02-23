/*
 * File: 4001.hpp
 * Project: 4001
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 10:10:43 am
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef H_C4001
#define H_C4001

#include "Class/Component/Component.hpp"
#include "Class/Gate/Or/OrGate.hpp"

namespace nts
{
    class C4001 : public Component {
      public:
        C4001();
        virtual ~C4001();

        nts::Tristate compute(std::size_t pin);

      private:
        size_t _nbGate;
        OrGate *_gates[4];
    };
} // namespace nts

#endif // !H_C4001