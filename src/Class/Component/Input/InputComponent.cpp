#include "InputComponent.hpp"

using namespace nts;

InputComponent::InputComponent(Tristate state, IComponent &component)
    : _state(state), _component(component)
{
}

Tristate InputComponent::getState() const
{
	return this->_state;
}

IComponent &InputComponent::getComponent() const
{
	return this->_component;
}

void InputComponent::setState(Tristate state)
{
	this->_state = state;
}

void InputComponent::setComponent(IComponent &component)
{
	this->_component = component;
}

void InputComponent::setInputValue(Tristate state)
{
    this->setState(state);
}


Tristate InputComponent::compute(size_t pin)
{
	return this->getState();
}

void InputComponent::simulate(size_t time)
{

}