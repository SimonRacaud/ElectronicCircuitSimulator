/*
 * File: Component.cpp
 * Project: Component
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Thursday, 11th February 2021 1:54:30 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "Component.hpp"
#include "Class/Exception/UndefinedPinException.hpp"
#include "Class/Exception/BusyPinException.hpp"

using namespace nts;

Component::Component(const std::string &name, ComponentType type): _name(name), _type(type)
{
}

Component::~Component()
{
    std::unordered_map<size_t, Output*>::iterator it;

    while (this->_outputs.empty() == true) {
        it = this->_outputs.erase(this->_outputs.begin());
        delete &(*it);
    }
}

Tristate Component::getState(size_t pinOut)
{
    auto it = this->_outputs.find(pinOut);

    if (it == this->_outputs.end()) {
        throw UndefinedPinException("undefined out pin", "Componenent::getState");
    }
    return it->second->getState();
}

void Component::simulate(std::size_t tick)
{
    for (auto it = this->_outputs.begin(); it != this->_outputs.end(); it++) {
        it->second->setState(this->compute(it->first));
    }
    for (auto it = this->_outputs.begin(); it != this->_outputs.end(); it++) {
        it->second->getComponent().simulate(tick);
    }
}

Tristate Component::compute(__attribute__((unused))std::size_t pin)
{
    return UNDEFINED;
}

void Component::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    Component &otherCom = dynamic_cast<Component &>(other);
    auto outPin = this->_outputs.find(pin);
    auto inPin = otherCom._inputs.find(otherPin);
    if (inPin != otherCom._inputs.end() && inPin->second != this) {
        throw BusyPinException("Input Pin already used", "setLink");
    }
    if (outPin != this->_outputs.end()) {
        delete this->_outputs[pin];
    }
    this->_outputs[pin] = new Output(UNDEFINED, other);
    otherCom._inputs[otherPin] = this;
}

void Component::dump() const
{
    std::string typeNames[4] = {"INPUT", "OUTPUT", "BOTH", "OTHER"};
    std::unordered_map<Tristate, std::string> stateNames = {
        {UNDEFINED, "UNDEFINED"}, 
        {TRUE, "TRUE"},
        {FALSE, "FALSE"}
    };
    std::string name;

    std::cout << "Component: " << _name << " " << typeNames[_type] << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (auto it = this->_inputs.begin(); it != this->_inputs.end(); it++) {
        std::cout << "\t" << dynamic_cast<Component *>(it->second)->_name << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (auto it = this->_outputs.begin(); it != this->_outputs.end(); it++) {
        name = dynamic_cast<Component *>(&it->second->getComponent())->_name;
        std::cout << "\t" << name << ": " << stateNames[it->second->getState()] << std::endl;
    } 
    std::cout << std::endl;
}

ComponentContent &Component::getContent() const
{
    std::unordered_map<size_t, Tristate> outputs;

    for (auto it = this->_outputs.begin(); it != this->_outputs.end(); it++) {
        outputs[it->first] = it->second->getState();
    }
    return *(new ComponentContent(_name, _type, outputs));
}

const std::string &Component::getName() const
{
    return this->_name;
}

ComponentType Component::getType() const
{
    return this->_type;
}