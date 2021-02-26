#include "Class/Exception/OpenFileException.hpp"
#include "LoggerComponent.hpp"

using namespace nts;

LoggerComponent::LoggerComponent(const std::string &name)
    : Component(name, OUTPUT)
{
    size_t pin_in[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    this->createInputs(pin_in, 10);
    this->_outputFile.open("./log.bin", std::ostream::trunc);
    if (!this->_outputFile.is_open())
        throw OpenFileException("Can't open file", "LoggerComponent");
}

LoggerComponent::~LoggerComponent()
{
    this->_outputFile.close();
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

    if (clock == TRUE && inhibit == FALSE && this->_computeCalls == this->_connectedInPins)
        return true;
    return false;
}

size_t LoggerComponent::binFromTristate(size_t pin)
{
    Component *input_pin = dynamic_cast<Component *>(this->_inputs[pin]->getComponent());
    Tristate state = input_pin->getState(this->_inputs[pin]->getPinOut());

    if (state == TRUE) {
        return 1;
    } else if (state == FALSE) {
        return 0;
    } else {
        throw UndefinedPinException("logger", "undifined pin value");
    }
}

Tristate LoggerComponent::compute(size_t)
{
    size_t value = 0;

    if (this->correctParmasForWrite()) {
        if (this->_outputFile.is_open()) {
            try {
                value += this->binFromTristate(1) * 1;
                value += this->binFromTristate(2) * 2;
                value += this->binFromTristate(3) * 4;
                value += this->binFromTristate(4) * 8;
                value += this->binFromTristate(5) * 16;
                value += this->binFromTristate(6) * 32;
                value += this->binFromTristate(7) * 64;
                value += this->binFromTristate(8) * 128;
                this->_outputFile << (char) value;
                this->_outputFile.flush();
            } catch (const UndefinedPinException &e) {
                return UNDEFINED;
            }
        } else {
            throw OpenFileException("Can't open file", "LoggerComponent");
        }
    }
    return UNDEFINED;
}

void LoggerComponent::simulate(size_t time)
{
    (void) time;
    if (this->_connectedInPins == 0) {
        this->_connectedInPins =
            std::count_if(_inputs.begin(), _inputs.end(), [](auto el) {
                return el.second->getComponent() != nullptr;
            });
    }
    this->_computeCalls++;
    this->compute(0);
    if (this->_computeCalls == this->_connectedInPins) {
        this->_computeCalls = 0;
    }
}