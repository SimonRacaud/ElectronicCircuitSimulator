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
        {"clock", [this]() {return new ClockComponent(this->_componentName);}},
        {"false", [this]() {return new FalseComponent(this->_componentName);}},
        {"true", [this]() {return new TrueComponent(this->_componentName);}},
        {"logger", [this]() {return new LoggerComponent(this->_componentName);}},
    };
}

void FactoryComponent::setComponentName(std::string name)
{
    this->_componentName = name;
}

std::unique_ptr<nts::IComponent> FactoryComponent::callFactory(const std::string &type, std::string name)
{
    this->setComponentName(name);
    return this->createComponent(type);
}

std::unique_ptr<IComponent> FactoryComponent::createComponent(const std::string &type)
{
    IComponent *ret;

    if (this->_list.find(type) != this->_list.end()) {
        ret = this->_list[type]();
    } else {
        throw ComponentTypeException("Can't find component " + type, "Factory");
    }
    return std::unique_ptr<IComponent>(ret);
}