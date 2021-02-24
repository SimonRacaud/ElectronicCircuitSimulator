#include "InputComponent.hpp"

using namespace nts;

InputComponent::InputComponent(const std::string &name)
    : Component(name)
{
	size_t pin_out[] = {1};

	this->createOutputs(pin_out, 1);
}

Tristate InputComponent::compute(size_t pin)
{
	(void) pin;
	return UNDEFINED;
}

void InputComponent::simulate(size_t time)
{
	(void) time;
}