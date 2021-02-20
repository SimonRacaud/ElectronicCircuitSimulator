#include "Class/Component/Input/ClockComponent/ClockComponent.hpp"

using namespace nts;

ClockComponent::ClockComponent(Tristate state, IComponent &component) : InputComponent(state, component)
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
    (void) pin;
    Tristate pinValue = this->getState();

    pinValue = (pinValue == TRUE) ? FALSE : TRUE;
    this->setState(pinValue);
    return pinValue;
}