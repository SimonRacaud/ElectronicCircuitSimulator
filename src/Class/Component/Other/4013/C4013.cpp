#include "C4013.hpp"

using namespace nts;

C4013::C4013(std::string const &name)
    : Component(name, OTHER), _prevClockState{UNDEFINED, UNDEFINED}
{
    size_t pinIn[] = {3, 5, 6, 4, 9, 8, 10, 11};
    size_t pinOut[] = {1, 2, 13, 12};

    this->createInputs(pinIn, 8);
    this->createOutputs(pinOut, 4);
}

C4013::~C4013()
{
}

nts::Tristate C4013::compute(std::size_t pin)
{
    flipFlopInputs_t pins1_2 = {3, 5, 6, 4, 0};
    flipFlopInputs_t pins12_13 = {11, 9, 8, 10, 1};
    Tristate ret;

    if (this->isLastCompute() && (pin == 1 || pin == 2)) {
        if (pin == 1) {
            ret = this->computeQPin(pins1_2, pin);
            this->_prevClockState[pins1_2.id] =
                _inputs[pins1_2.clock]->getState();
        } else {
            ret = this->computeNQPin(pins1_2, pin);
            this->_prevClockStateN[pins1_2.id] =
                _inputs[pins1_2.clock]->getState();
        }
        return ret;
    } else if (this->isLastCompute() && (pin == 12 || pin == 13)) {
        if (pin == 13) {
            ret = this->computeQPin(pins12_13, pin);
            this->_prevClockState[pins12_13.id] =
                _inputs[pins12_13.clock]->getState();
        } else {
            ret = this->computeNQPin(pins12_13, pin);
            this->_prevClockStateN[pins12_13.id] =
                _inputs[pins12_13.clock]->getState();
        }
        return ret;
    }
    return this->_outputs[pin]->getState();
}

nts::Tristate C4013::computeQPin(flipFlopInputs_t &inputs, size_t pinOut)
{
    Tristate reset = this->_inputs[inputs.reset]->getState();
    Tristate data = this->_inputs[inputs.data]->getState();
    Tristate set = this->_inputs[inputs.set]->getState();
    Tristate clock = this->_inputs[inputs.clock]->getState();

    if (clock == UNDEFINED || reset == UNDEFINED || data == UNDEFINED
        || set == UNDEFINED)
        return UNDEFINED;
    if (reset == TRUE && set == TRUE)
        return TRUE;
    if (set == TRUE)
        return TRUE;
    if (reset == TRUE)
        return FALSE;
    if (_prevClockState[inputs.id] == TRUE && clock == FALSE)
        return this->_outputs[pinOut]->getState();
    if (_prevClockState[inputs.id] == FALSE && clock == TRUE)
        return data;
    return this->_outputs[pinOut]->getState();
}

nts::Tristate C4013::computeNQPin(flipFlopInputs_t &inputs, size_t pinOut)
{
    Tristate reset = this->_inputs[inputs.reset]->getState();
    Tristate data = this->_inputs[inputs.data]->getState();
    Tristate set = this->_inputs[inputs.set]->getState();
    Tristate clock = this->_inputs[inputs.clock]->getState();

    if (clock == UNDEFINED || reset == UNDEFINED || data == UNDEFINED
        || set == UNDEFINED)
        return UNDEFINED;
    if (reset == TRUE && set == TRUE)
        return TRUE;
    if (set == TRUE)
        return FALSE;
    if (reset == TRUE)
        return TRUE;
    if (_prevClockStateN[inputs.id] == TRUE && clock == FALSE)
        return this->_outputs[pinOut]->getState();
    if (_prevClockStateN[inputs.id] == FALSE && clock == TRUE)
        return !data;
    return this->_outputs[pinOut]->getState();
}