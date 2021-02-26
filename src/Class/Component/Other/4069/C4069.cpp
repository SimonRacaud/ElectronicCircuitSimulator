/*
 * File: C4069.cpp
 * Project: 4069
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 9:31:34 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "Class/Component/Other/4069/C4069.hpp"

using namespace nts;

C4069::C4069(std::string const &name) : Component(name, OTHER), _nbGate(6)
{
    size_t pinIn[] = {1, 3, 5, 13, 11, 9};
    size_t pinOut[] = {2, 4, 6, 12, 10, 8};

    this->createInputs(pinIn, 6);
    this->createOutputs(pinOut, 6);
    this->_gate[2] = new NotGate(*_inputs[1]);
    this->_gate[4] = new NotGate(*_inputs[3]);
    this->_gate[6] = new NotGate(*_inputs[5]);
    this->_gate[12] = new NotGate(*_inputs[13]);
    this->_gate[10] = new NotGate(*_inputs[11]);
    this->_gate[8] = new NotGate(*_inputs[9]);
}

C4069::~C4069()
{
    while (this->_gate.empty() == false) {
        delete this->_gate.begin()->second;
        this->_gate.erase(this->_gate.begin());
    }
}

nts::Tristate C4069::compute(std::size_t pin)
{
    if (this->_gate.find(pin) == this->_gate.end()) {
        throw ManageError(
            "Dev error, gate forgotten", "(sub)Component::compute");
    }
    return this->_gate[pin]->compute();
}