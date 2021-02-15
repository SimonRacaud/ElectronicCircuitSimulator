#include "Class/Component/Input/FalseComponent/FalseComponent.hpp"

using namespace nts;

FalseComponent::FalseComponent(Tristate state, IComponent &component) : InputComponent(state, component)
{

}

void FalseComponent::simulate(size_t time)
{
    InputComponent::simulate(time);
    return;
}

Tristate FalseComponent::compute(size_t pin)
{
    (void) pin;
    return FALSE;
}