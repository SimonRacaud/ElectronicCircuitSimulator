#include "InputComponent.hpp"

using namespace nts;

InputComponent::InputComponent(const std::string &name)
    : _state(UNDEFINED), _component(new Component(name, INPUT))
{
}

Tristate InputComponent::getState() const
{
	return this->_state;
}

IComponent *InputComponent::getComponent() const
{
	return this->_component;
}

void InputComponent::setState(Tristate state)
{
	this->_state = state;
}

void InputComponent::setComponent(IComponent *component)
{
	this->_component = component;
}

void InputComponent::setInputValue(Tristate state)
{
    this->setState(state);
}

Tristate InputComponent::compute(size_t pin)
{
	(void) pin;
	return this->getState();
}

void InputComponent::simulate(size_t time)
{
	(void) time;
}