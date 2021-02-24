#include "OutputComponent.hpp"

using namespace nts;

OutputComponent::OutputComponent(const std::string &name)
	: _state(UNDEFINED), _component(new Component(name, INPUT))
{
}

Tristate OutputComponent::compute(size_t pin)
{
	(void) pin;
	return UNDEFINED;
}

void OutputComponent::simulate(size_t time)
{
	(void) time;
	this->compute(0);
}