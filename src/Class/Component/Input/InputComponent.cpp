#include "InputComponent.hpp"

using namespace nts;

InputComponent::InputComponent(const std::string &name)
    : Component(name, INPUT)
{
    size_t pin_out[] = {1};

    this->createOutputs(pin_out, 1);
}

Tristate InputComponent::compute(size_t pin)
{
    (void) pin;
    return UNDEFINED;
}

void InputComponent::simulate(size_t tick)
{
    this->_outputs[1]->updateState();
    for (auto it = this->_outputs.begin(); it != this->_outputs.end(); it++) {
        it->second->getComponent().simulate(tick);
    }
}