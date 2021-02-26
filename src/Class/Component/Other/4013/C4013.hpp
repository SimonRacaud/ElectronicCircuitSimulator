/*
 * File: C4013.hpp
 * Project: 4013
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Thursday, 25th February 2021 4:58:34 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef H_C4013
#define H_C4013

#include "Class/Component/Component.hpp"
#include "Operator/Tristate/TristateOperators.hpp"
#include "UndefinedPinException.hpp"

namespace nts
{
    typedef struct flipFlopInputs {
        size_t clock;
        size_t data;
        size_t set;
        size_t reset;
        size_t id;
    } flipFlopInputs_t;

    class C4013 : public Component {
      public:
        C4013(std::string const &name);
        virtual ~C4013();

        nts::Tristate compute(std::size_t pin);

        nts::Tristate computeQPin(flipFlopInputs_t &inputs, size_t pinOut);
        nts::Tristate computeNQPin(flipFlopInputs_t &inputs, size_t pinOut);

      private:
        Tristate _prevClockState[2];
        Tristate _prevClockStateN[2];
    };
} // namespace nts

#endif // !H_C4013