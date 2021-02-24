#include "OutputComponent.hpp"

using namespace nts;

OutputComponent::OutputComponent(const std::string &name)
	: Component(name)
{
	size_t pin_in[] = {1};

	this->createInputs(pin_in, 1);
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