/*
 * File: Input.cpp
 * Project: Input
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 11:24:20 am
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "Input.hpp"

using namespace nts;

Input::Input() : _pinOut(0), _component(nullptr)
{
}

void Input::initialize(size_t pinOut, IComponent &component)
{
    _pinOut = pinOut;
    _component = &component;
}

size_t Input::getPinOut() const
{
    return this->_pinOut;
}

IComponent &Input::getComponent() const
{
    return *this->_component;
}

void Input::setPinOut(size_t pinOut)
{
    this->_pinOut = pinOut;
}

void Input::setComponent(IComponent &component)
{
    this->_component = &component;
}

Tristate Input::getState(void)
{
    return dynamic_cast<Component *>(_component)->getState(_pinOut);
}