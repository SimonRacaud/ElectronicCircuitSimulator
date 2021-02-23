/*
 * File: C4001.cpp
 * Project: 4001
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 10:15:21 am
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "Class/Component/Other/4001/C4001.hpp"

using namespace nts;

C4001::C4001() : Component("4001", OTHER), _nbGate(4)
{
    size_t pinIn[] = {1, 2, 5, 6, 13, 12, 9, 8};
    size_t pinOut[] = {3, 4, 11, 10};

    this->createInputs(pinIn, 8);
    this->createOutputs(pinOut, 4);
    this->_gates[0] = new OrGate(*_inputs[1], *_inputs[2], *_outputs[3]);
    this->_gates[1] = new OrGate(*_inputs[5], *_inputs[6], *_outputs[4]);
    this->_gates[2] = new OrGate(*_inputs[12], *_inputs[13], *_outputs[11]);
    this->_gates[3] = new OrGate(*_inputs[8], *_inputs[9], *_outputs[10]);
}

C4001::~C4001()
{
}

nts::Tristate C4001::compute(std::size_t pin)
{
    for (size_t i = 0; i < _nbGate; i++) {
        this->_gates[i]->updateOutput();
    }
}