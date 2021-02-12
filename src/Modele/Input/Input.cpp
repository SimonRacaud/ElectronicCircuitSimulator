#include "Input.hpp"

using namespace nts;

Input::Input(Tristate state, IComponent &component)
    : _state(state), _component(component)
{
}

Tristate Input::getState() const
{
	return this->_state;
}

IComponent &Input::getComponent() const
{
	return this->_component;
}

void Input::setState(Tristate state)
{
	this->_state = state;
}

void Input::setComponent(IComponent &component)
{
	this->_component = component;
}

void Input::setInputValue(Tristate state)
{
    this->setState(state);
}