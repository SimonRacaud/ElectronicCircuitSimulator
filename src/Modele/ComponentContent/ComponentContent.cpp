#include "ComponentContent.hpp"

using namespace nts;

ComponentContent::ComponentContent(const std::string &name, ComponentType type,
    std::unordered_map<size_t, Tristate> &pins)
    : _name(name), _type(type), _pins(pins)
{
}

ComponentContent::~ComponentContent()
{
}

const std::string &ComponentContent::getName() const
{
    return this->_name;
}

ComponentType ComponentContent::getType() const
{
    return this->_type;
}

const std::unordered_map<size_t, Tristate> &ComponentContent::getPins() const
{
    return this->_pins;
}