#include "Class/Component/Input/ClockComponent/ClockComponent.hpp"

using namespace nts;

ClockComponent::ClockComponent(const std::string &name) : InputComponent(name)
{
    this->setState(TRUE);
}

void ClockComponent::simulate(size_t time)
{
    InputComponent::simulate(time);
    return;
}

Tristate ClockComponent::compute(size_t pin)
{
    Tristate pinValue = this->getState(pin);

    pinValue = (pinValue == TRUE) ? FALSE : TRUE;
    this->setState(pinValue);
    return pinValue;
}