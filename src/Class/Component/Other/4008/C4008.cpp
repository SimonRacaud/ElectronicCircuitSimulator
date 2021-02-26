#include <map>
#include "Class/Component/Other/4008/C4008.hpp"

using namespace nts;

C4008::C4008(std::string const &name) : Component(name, OTHER), _carry(UNDEFINED)
{
    size_t pinIn[] = {1, 2, 3, 4, 5, 6, 7, 9, 15};
    size_t pinOut[] = {10, 11, 12, 13, 14};

    this->createInputs(pinIn, 9);
    this->createOutputs(pinOut, 5);
}

C4008::~C4008()
{
}

Tristate C4008::getDirectState(size_t pin)
{
    Component *input_pin = dynamic_cast<Component *>(this->_inputs[pin]->getComponent());

    return input_pin->getState(this->_inputs[pin]->getPinOut());
}

Tristate C4008::alphAdder(Tristate a, Tristate b, Tristate &c)
{
    if (a == UNDEFINED || b == UNDEFINED) {
        c = UNDEFINED;
        return UNDEFINED;
    }
    if (a == TRUE && b == TRUE) {
        c = TRUE;
        return FALSE;
    } else if (a == FALSE && b == FALSE) {
        c = FALSE;
        return FALSE;
    } else {
        c = FALSE;
        return TRUE;
    }
}

Tristate C4008::simpleAdder(Tristate a, Tristate b)
{
    Tristate cf = UNDEFINED;
    Tristate cs = UNDEFINED;
    Tristate retf = UNDEFINED;
    Tristate rets = UNDEFINED;

    if (a == UNDEFINED || a == UNDEFINED || this->_carry == UNDEFINED) {
        this->_carry = UNDEFINED;
        return UNDEFINED;
    }
    retf = this->alphAdder(a, b, cf);
    rets = this->alphAdder(retf, this->_carry, cs);
    //rets = I
    //h = (cf == TRUE || cs == TRUE) ? TRUE : FALSE;
    this->_carry = (cf == TRUE || cs == TRUE) ? TRUE : FALSE;
    return rets;
}

Tristate C4008::compute(std::size_t pin)
{
    this->_carry = this->getDirectState(9);
    std::map<size_t, Tristate> saves;

    saves[10] = simpleAdder(this->getDirectState(6), this->getDirectState(7));
    saves[11] = simpleAdder(this->getDirectState(4), this->getDirectState(5));
    saves[12] = simpleAdder(this->getDirectState(2), this->getDirectState(3));
    saves[13] = simpleAdder(this->getDirectState(15), this->getDirectState(1));
    saves[14] = this->_carry;
    return saves[pin];
}