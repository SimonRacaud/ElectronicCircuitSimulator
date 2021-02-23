#include "OutputComponent.hpp"

using namespace nts;

OutputComponent::OutputComponent(Tristate state, IComponent &component)
    : _state(state), _component(component)
{
}

Tristate OutputComponent::compute(size_t pin)
{
	return UNDEFINED;
}

void OutputComponent::simulate(size_t time)
{
	(void) time;
	this->compute(0);
}