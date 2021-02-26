#include "Circuit.hpp"

using namespace nts;

Circuit::Circuit(const std::string &name, ComponentType type)
    : Component(name, type), _currentTick(0)
{
}

Circuit::~Circuit()
{
    while (this->_nodes.empty() == false) {
        delete this->_nodes.begin()->second;
        this->_nodes.erase(this->_nodes.begin());
    }
}

void Circuit::simulate()
{
    Component *com;

    this->_currentTick++;
    Component::nbJump = 0;
    for (auto it = _nodes.begin(); it != _nodes.end(); it++) {
        com = dynamic_cast<Component *>(it->second);
        if (com->getType() == INPUT) {
            com->simulate(this->_currentTick);
        }
    }
}

void Circuit::dump() const
{
    for (auto it = _nodes.begin(); it != _nodes.end(); it++) {
        it->second->dump();
    }
}

std::deque<ComponentContent *> &Circuit::getCircuitContent() const
{
    std::deque<ComponentContent *> *content =
        new std::deque<ComponentContent *>;
    Component *c;
    ComponentContent *ptr;

    for (auto it = _nodes.begin(); it != _nodes.end(); it++) {
        c = dynamic_cast<Component *>(it->second);
        if (c->getType() == INPUT || c->getType() == OUTPUT) {
            ptr = c->getContent();
            if (nullptr != ptr)
                content->push_back(ptr);
        }
    }
    std::sort(content->begin(), content->end(),
        [](ComponentContent *a, ComponentContent *b) {
            return a->getName() < b->getName();
        });
    return *content;
}

void Circuit::addNode(IComponent &component)
{
    Component *com = dynamic_cast<Component *>(&component);
    auto it = this->_nodes.find(com->getName());

    if (it != this->_nodes.end()) {
        throw ComponentNameException(
            "The node already exist", "Circuit::addNode");
    }
    this->_nodes[com->getName()] = &component;
}

void Circuit::setNodeLink(const std::string &nameNodeA, std::size_t pinOutA,
    const std::string &nameNodeB, std::size_t pinInB)
{
    auto itNodeA = this->_nodes.find(nameNodeA);
    auto itNodeB = this->_nodes.find(nameNodeB);

    if (itNodeA == this->_nodes.end() || itNodeB == this->_nodes.end()) {
        throw new ComponentNameException(
            "Node not found", "Circuit::setNodeLink");
    }
    itNodeA->second->setLink(pinOutA, *(itNodeB->second), pinInB);
}

size_t Circuit::getTick() const
{
    return this->_currentTick;
}

void Circuit::setInputComponentValue(
    const std::string &compName, Tristate value)
{
    Component *comp;

    if (this->_nodes.find(compName) == this->_nodes.end()) {
        throw InvalidComponentNameException(
            "component not found", "circuit::setInputComponentValue");
    }
    comp = dynamic_cast<Component *>(this->_nodes[compName]);
    comp->setState(value);
}