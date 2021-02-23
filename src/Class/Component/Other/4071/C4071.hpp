/*
 * File: C4071.hpp
 * Project: 4071
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 9:22:17 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef H_C4071
#define H_C4071

#include "Class/Component/Component.hpp"
#include "Class/Gate/Or/OrGate.hpp"
#include "Error/Error.hpp"
#include <unordered_map>

namespace nts
{
    class C4071 : public Component {
      public:
        C4071(std::string const &name);
        virtual ~C4071();

        nts::Tristate compute(std::size_t pin);

      private:
        size_t _nbGate;
        std::unordered_map<std::size_t, OrGate *> _gate;
    };
} // namespace nts

#endif // !H_C4071