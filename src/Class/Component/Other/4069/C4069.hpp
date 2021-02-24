/*
 * File: C4069.hpp
 * Project: 4069
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 9:26:56 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef H_C4069
#define H_C4069

#include "Class/Component/Component.hpp"
#include "Class/Gate/Not/NotGate.hpp"
#include "Error/Error.hpp"
#include <unordered_map>

namespace nts
{
    class C4069 : public Component {
      public:
        C4069(std::string const &name);
        virtual ~C4069();

        nts::Tristate compute(std::size_t pin);

      private:
        size_t _nbGate;
        std::unordered_map<std::size_t, NotGate *> _gate;
    };
} // namespace nts

#endif // !H_C4069