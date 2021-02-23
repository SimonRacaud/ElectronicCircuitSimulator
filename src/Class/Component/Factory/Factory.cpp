#include <memory>
#include "Factory.hpp"
#include "Class/Component/Input/TrueComponent/TrueComponent.hpp"
#include "Class/Component/Input/FalseComponent/FalseComponent.hpp"
#include "Class/Component/Input/ClockComponent/ClockComponent.hpp"
#include "Class/Component/Output/LoggerComponent/LoggerComponent.hpp"

using namespace nts;

FactoryComponent::FactoryComponent()
{
    this->_list = {
        {"clock", [](Tristate state, IComponent &component) {return new ClockComponent(state, component);}},
        {"false", [](Tristate state, IComponent &component) {return new FalseComponent(state, component);}},
        {"true", [](Tristate state, IComponent &component) {return new TrueComponent(state, component);}},
        {"logger", [](Tristate state, IComponent &component) {return new LoggerComponent(state, component);}},
    };
}

std::unique_ptr<IComponent> FactoryComponent::createComponent(const std::string &type)
{
    IComponent *component = new Component();
    IComponent *ret;

    if (this->_list.find(type) != this->_list.end()) {
        ret = this->_list[type](UNDEFINED, *component);
    } else {
        throw ComponentTypeException("Can't find component " + type, "Factory");
    }
    return std::unique_ptr<IComponent>(ret);
}