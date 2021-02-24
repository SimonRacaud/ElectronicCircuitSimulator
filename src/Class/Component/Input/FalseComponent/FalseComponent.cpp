#include "Class/Component/Input/FalseComponent/FalseComponent.hpp"

using namespace nts;

FalseComponent::FalseComponent(const std::string &name) : InputComponent(name)
{
    this->setState(FALSE);
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