/*
 * File: Output.cpp
 * Project: Output
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Thursday, 11th February 2021 10:22:00 am
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "Output.hpp"

using namespace nts;

Output::Output(Tristate state, IComponent &component)
    : _state(state), _component(component)
{
    
}

Tristate Output::getState() const
{
	return _state;
}

IComponent &Output::getComponent() const
{
	return _component;
}

void Output::setState(Tristate state)
{
	this->_state = state;
}

void Output::setComponent(IComponent &component)
{
	this->_component = component;
}