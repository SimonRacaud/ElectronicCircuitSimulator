#include <fstream>
#include "Class/Exception/OpenFileException.hpp"
#include "LoggerComponent.hpp"

using namespace nts;

LoggerComponent::LoggerComponent(Tristate state, IComponent &component)
    : OutputComponent(state, component), _state(state), _component(component)
{
}

/*
** 9 clock pin
** 10 inhibit pin
*/

bool LoggerComponent::correctParmasForWrite(void)
{
    Component *clock_component =
        dynamic_cast<Component *>(&this->_inputs[9]->getComponent());
    Component *inhibit_component =
        dynamic_cast<Component *>(&this->_inputs[10]->getComponent());
    Tristate clock = clock_component->getState(0);
    Tristate inhibit = inhibit_component->getState(0);

    if (clock == TRUE && inhibit == FALSE)
        return true;
    return false;
}

char LoggerComponent::charFromTristate(Tristate state)
{
    char c = '\0';

    switch (state) {
        case TRUE: c = 'T'; break;
        case FALSE: c = 'F'; break;
        case UNDEFINED: c = 'U'; break;
        default: c = '\0'; break;
    }
    return c;
}

Tristate LoggerComponent::compute(size_t pin)
{
    Component *input_pin = NULL;
    Tristate state = UNDEFINED;
    std::ofstream output;

    (void) pin;
    if (this->correctParmasForWrite()) {
        output.open("./log.bin");
        if (output.is_open()) {
            for (auto it = this->_inputs.begin(); it != this->_inputs.end();
                 it++) {
                input_pin =
                    dynamic_cast<Component *>(&it->second->getComponent());
                state = input_pin->getState(it->first);
                output << this->charFromTristate(state) << std::endl;
            }
            output.close();
        } else {
            throw OpenFileException("Can't open file", "LoggerComponent");
        }
    }
    return UNDEFINED;
}

void LoggerComponent::simulate(size_t time)
{
    (void) time;
    this->compute(0);
}