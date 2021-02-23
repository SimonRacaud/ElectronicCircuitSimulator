/*
 * File: Input.hpp
 * Project: Input
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 11:24:14 am
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef INPUT_H
#define INPUT_H
#pragma once

#include "Class/Component/Component.hpp"
#include "IComponent.hpp"

namespace nts
{
    class Input {
      public:
        Input(size_t pinOut, IComponent &component);

        size_t getPinOut() const;
        IComponent &getComponent() const;

        void setPinOut(size_t pin);
        void setComponent(IComponent &component);

        Tristate getState(void);

      private:
        size_t _pinOut;
        IComponent &_component;
    };

} // namespace nts
#endif