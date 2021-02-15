#include "Class/Component/Input/ClockComponent/ClockComponent.hpp"

using namespace nts;

ClockComponent::ClockComponent(Tristate state, IComponent &component) : InputComponent(state, component), _localTime(0)
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
    Tristate pinValue = (this->_localTime % 2 == 0) ? TRUE : FALSE;

    this->setState(pinValue);
    this->_localTime++;
    return pinValue;
}