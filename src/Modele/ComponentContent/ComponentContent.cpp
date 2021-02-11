#include "ComponentContent.hpp"

using namespace nts;

ComponentContent::ComponentContent(const std::string &name, ComponentType type, std::unordered_map<size_t, Tristate> &outputs)
: _name(name), _type(type), _outputs(outputs)
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

const std::unordered_map<size_t, Tristate> &ComponentContent::getOutputs() const
{
    return this->_outputs;
}