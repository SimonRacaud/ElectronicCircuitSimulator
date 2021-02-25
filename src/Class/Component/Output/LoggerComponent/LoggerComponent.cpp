#include <fstream>
#include "Class/Exception/OpenFileException.hpp"
#include "LoggerComponent.hpp"

using namespace nts;

LoggerComponent::LoggerComponent(const std::string &name)
    : Component(name, OUTPUT)
{
    size_t pin_in[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    this->createInputs(pin_in, 10);
}

/*
** 9 clock pin
** 10 inhibit pin
*/

bool LoggerComponent::correctParmasForWrite(void)
{
    Component *clock_component =
        dynamic_cast<Component *>(this->_inputs[9]->getComponent());
    Component *inhibit_component =
        dynamic_cast<Component *>(this->_inputs[10]->getComponent());
    Tristate clock = clock_component->getState(1);
    Tristate inhibit = inhibit_component->getState(1);

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

Tristate LoggerComponent::compute(size_t)
{
    Component *input_pin = NULL;
    Tristate state = UNDEFINED;
    std::ofstream output;

    if (this->correctParmasForWrite()) {
        output.open("./log.bin", std::ostream::trunc);
        if (output.is_open()) {
            for (auto it = this->_inputs.begin(); it != this->_inputs.end(); it++) {
                if (it->first != 9 && it->first != 10) {
                    input_pin = dynamic_cast<Component *>(it->second->getComponent());
                    state = input_pin->getState(it->second->getPinOut());
                    output << this->charFromTristate(state) << std::endl;
                }
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