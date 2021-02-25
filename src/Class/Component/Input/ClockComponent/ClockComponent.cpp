#include "Class/Component/Input/ClockComponent/ClockComponent.hpp"

using namespace nts;

ClockComponent::ClockComponent(const std::string &name) : InputComponent(name)
{
    this->setState(UNDEFINED);
    this->_outputs[1]->updateState();
}

void ClockComponent::simulate(size_t time)
{
    InputComponent::simulate(time);
    this->compute(1);
    return;
}

Tristate ClockComponent::compute(size_t pin)
{
    Tristate pinValue = this->getState(pin);

    if (pinValue == UNDEFINED)
        return UNDEFINED;
    pinValue = (pinValue == TRUE) ? FALSE : TRUE;
    this->setState(pinValue);
    return pinValue;
}