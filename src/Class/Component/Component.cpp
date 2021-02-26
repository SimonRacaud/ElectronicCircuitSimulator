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

#include "Class/Exception/BusyPinException.hpp"
#include "Class/Exception/UndefinedPinException.hpp"
#include "Component.hpp"
#include "Input/FalseComponent/FalseComponent.hpp"
#include "Input/TrueComponent/TrueComponent.hpp"

using namespace nts;

const size_t MAX_JUMP = 500;

std::unordered_map<Tristate, std::string> Component::TRISTATE_STR = {
    {UNDEFINED, "U"}, {TRUE, "1"}, {FALSE, "0"}};

size_t Component::nbJump = 0;

Component::Component(const std::string &name, ComponentType type)
    : _name(name), _type(type), _computeCalls(0), _connectedInPins(0)
{
}

Component::~Component()
{
    std::unordered_map<size_t, Output *>::iterator itOut;
    std::unordered_map<size_t, Input *>::iterator itIn;

    while (this->_outputs.empty() == false) {
        itOut = this->_outputs.erase(this->_outputs.begin());
        delete &(*itOut);
    }
    while (this->_inputs.empty() == false) {
        itIn = this->_inputs.erase(this->_inputs.begin());
        delete &(*itIn);
    }
}

void Component::createInputs(const size_t *pins, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        this->_inputs[pins[i]] = new Input();
    }
}

void Component::createOutputs(const size_t *pins, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        this->_outputs[pins[i]] = new Output();
    }
}

Tristate Component::getState(size_t pinOut)
{
    auto it = this->_outputs.find(pinOut);

    if (it == this->_outputs.end()) {
        throw UndefinedPinException(
            "undefined out pin", "Componenent::getState");
    }
    return it->second->getState();
}

void Component::simulate(std::size_t tick)
{
    if (Component::nbJump > MAX_JUMP) {
        std::cerr << "Error: infinite loop" << std::endl;
        return;
    }
    if (this->_connectedInPins == 0) {
        this->_connectedInPins =
            std::count_if(_inputs.begin(), _inputs.end(), [](auto el) {
                return el.second->getComponent() != nullptr;
            });
    }
    Component::nbJump++;
    this->_computeCalls++;
    for (auto it = this->_outputs.begin(); it != this->_outputs.end(); it++) {
        if (it->second->getComponents().size() == 0)
            continue;
        it->second->setNewState(this->compute(it->first));
        it->second->updateState();
    }
    if (this->_computeCalls == this->_connectedInPins) {
        this->_computeCalls = 0;
    }
    this->simulateNextNodes(tick);
}

void Component::simulateNextNodes(size_t tick)
{
    for (auto it = this->_outputs.begin(); it != this->_outputs.end(); it++) {
        const std::deque<IComponent *> &compList = it->second->getComponents();
        if (compList.size() == 0)
            continue;
        std::for_each(
            compList.begin(), compList.end(), [tick](IComponent *comp) {
                comp->simulate(tick);
            });
    }
}

Tristate Component::compute(__attribute__((unused)) std::size_t pin)
{
    throw std::exception();
    return UNDEFINED;
}

/*
 * pin => output pin (this), otherPin => input Pin (other)
 */
void Component::setLink(
    std::size_t pin, IComponent &other, std::size_t otherPin)
{
    Component &otherCom = dynamic_cast<Component &>(other);
    auto outPin = this->_outputs.find(pin);
    auto inPin = otherCom._inputs.find(otherPin);

    if (inPin == otherCom._inputs.end()) {
        throw UndefinedPinException(
            "Input Pin does not exist", "Component::setLink");
    } else if (inPin->second->getComponent() != nullptr) {
        throw BusyPinException("Input Pin busy", "Component::setLink");
    }
    if (outPin == this->_outputs.end()) {
        throw UndefinedPinException(
            "Output Pin does not exist", "Component::setLink");
    }
    this->_outputs[pin]->addComponent(other);
    otherCom._inputs[otherPin]->initialize(pin, *this);
}

void Component::dump() const
{
    std::string typeNames[4] = {"INPUT", "OUTPUT", "BOTH", "OTHER"};
    std::unordered_map<Tristate, std::string> stateNames = {
        {UNDEFINED, "UNDEFINED"}, {TRUE, "TRUE"}, {FALSE, "FALSE"}};
    std::string name;
    Component *tmp;

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Component: " << _name << " " << typeNames[_type]
              << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (auto it = this->_inputs.begin(); it != this->_inputs.end(); it++) {
        tmp = dynamic_cast<Component *>(it->second->getComponent());
        if (tmp) {
            std::cout << "\t" << tmp->_name << " : "
                      << stateNames[it->second->getState()] << std::endl;
        }
    }
    std::cout << "Outputs:" << std::endl;
    for (auto it = this->_outputs.begin(); it != this->_outputs.end(); it++) {
        const std::deque<IComponent *> &components =
            it->second->getComponents();
        for (auto it2 = components.begin(); it2 != components.end(); it2++) {
            tmp = dynamic_cast<Component *>(*it2);
            if (tmp) {
                name = tmp->_name;
                std::cout << "\t" << name << ": "
                          << stateNames[it->second->getState()] << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

ComponentContent *Component::getContent() const
{
    std::unordered_map<size_t, Tristate> pinsState;

    if (this->_type == INPUT) {
        for (auto it = this->_outputs.begin(); it != this->_outputs.end();
             it++) {
            pinsState[it->first] = it->second->getState();
        }
    } else if (this->_type == OUTPUT) {
        for (auto it = this->_inputs.begin(); it != this->_inputs.end();
             it++) {
            pinsState[it->first] = it->second->getState();
        }
    }
    return new ComponentContent(_name, _type, pinsState);
}

const std::string &Component::getName() const
{
    return this->_name;
}

ComponentType Component::getType() const
{
    return this->_type;
}

void Component::setState(Tristate state)
{
    TrueComponent *truecom = dynamic_cast<TrueComponent *>(this);
    FalseComponent *falsecom = dynamic_cast<FalseComponent *>(this);

    if (this->_type != INPUT) {
        throw ComponentTypeException(
            "set state not supported", "component::setState");
    } else if (!truecom && !falsecom) {
        for (auto it = this->_outputs.begin(); it != this->_outputs.end();
             it++) {
            it->second->setNewState(state);
        }
    }
}