#include "Class/Component/Input/ClockComponent/ClockComponent.hpp"

using namespace nts;

ClockComponent::ClockComponent(Tristate state, IComponent &component) : InputComponent(state, component), _localTime(0)
{

}

void ClockComponent::simulate(size_t time)
{
    InputComponent::simulate(time);
    return;
}

Tristate ClockComponent::compute(size_t pin)
{
    (void) pin;
    Tristate pinValue = (this->_localTime % 2) ? TRUE : FALSE;

    this->_localTime++;
    return pinValue;
}