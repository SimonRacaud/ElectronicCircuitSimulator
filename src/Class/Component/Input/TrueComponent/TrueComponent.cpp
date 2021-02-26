#include "Class/Component/Input/TrueComponent/TrueComponent.hpp"

using namespace nts;

TrueComponent::TrueComponent(const std::string &name) : InputComponent(name)
{
    this->_outputs[1]->setNewState(TRUE);
    this->_outputs[1]->updateState();
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

ComponentContent *TrueComponent::getContent() const
{
    return nullptr;
}