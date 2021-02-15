#include "Class/Component/Input/TrueComponent/TrueComponent.hpp"

using namespace nts;

TrueComponent::TrueComponent(Tristate state, IComponent &component) : InputComponent(state, component)
{
    this->setState(TRUE);
}

void TrueComponent::simulate(size_t time)
{
    InputComponent::simulate(time);
    return;
}

Tristate TrueComponent::compute(size_t pin)
{
    (void) pin;
    return TRUE;
}