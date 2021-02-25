#include "Class/Component/Input/FalseComponent/FalseComponent.hpp"

using namespace nts;

FalseComponent::FalseComponent(const std::string &name) : InputComponent(name)
{
    this->_outputs[1]->setNewState(FALSE);
    this->_outputs[1]->updateState();
}

void FalseComponent::simulate(size_t time)
{
    InputComponent::simulate(time);
}

Tristate FalseComponent::compute(size_t)
{
    return FALSE;
}