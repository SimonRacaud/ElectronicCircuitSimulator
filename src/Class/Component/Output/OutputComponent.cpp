#include "OutputComponent.hpp"

using namespace nts;

OutputComponent::OutputComponent(Tristate state, IComponent &component)
    : _state(state), _component(component)
{
}

Tristate OutputComponent::getState() const
{
	return this->_state;
}

IComponent &OutputComponent::getComponent() const
{
	return this->_component;
}

void OutputComponent::setState(Tristate state)
{
	this->_state = state;
}

void OutputComponent::setComponent(IComponent &component)
{
	this->_component = component;
}

Tristate OutputComponent::compute(size_t pin)
{
    (void) pin;
	return this->getState();
}

void OutputComponent::simulate(size_t time)
{
    (void) time;
}