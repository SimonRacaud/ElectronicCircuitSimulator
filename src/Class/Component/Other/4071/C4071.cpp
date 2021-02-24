/*
 * File: C4071.cpp
 * Project: 4071
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 9:22:53 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "Class/Component/Other/4071/C4071.hpp"

using namespace nts;

C4071::C4071(std::string const &name) : Component(name, OTHER), _nbGate(4)
{
    size_t pinIn[] = {1, 2, 5, 6, 13, 12, 9, 8};
    size_t pinOut[] = {3, 4, 11, 10};

    this->createInputs(pinIn, 8);
    this->createOutputs(pinOut, 4);
    this->_gate[3] = new OrGate(*_inputs[1], *_inputs[2]);
    this->_gate[4] = new OrGate(*_inputs[5], *_inputs[6]);
    this->_gate[11] = new OrGate(*_inputs[12], *_inputs[13]);
    this->_gate[10] = new OrGate(*_inputs[8], *_inputs[9]);
}

C4071::~C4071()
{
    for (size_t i = 0; i < _nbGate; i++) {
        delete this->_gate[i];
    }
}

nts::Tristate C4071::compute(std::size_t pin)
{
    if (this->_gate.find(pin) == this->_gate.end()) {
        throw ManageError(
            "Dev error, gate forgotten", "(sub)Component::compute");
    }
    return this->_gate[pin]->compute();
}