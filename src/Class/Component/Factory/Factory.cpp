#include <memory>
#include "Class/Component/Input/ClockComponent/ClockComponent.hpp"
#include "Class/Component/Input/FalseComponent/FalseComponent.hpp"
#include "Class/Component/Input/InputComponent.hpp"
#include "Class/Component/Input/TrueComponent/TrueComponent.hpp"
#include "Class/Component/Other/4001/C4001.hpp"
#include "Class/Component/Other/4011/C4011.hpp"
#include "Class/Component/Other/4013/C4013.hpp"
#include "Class/Component/Other/4030/C4030.hpp"
#include "Class/Component/Other/4069/C4069.hpp"
#include "Class/Component/Other/4071/C4071.hpp"
#include "Class/Component/Other/4081/C4081.hpp"
#include "Class/Component/Output/LoggerComponent/LoggerComponent.hpp"
#include "Class/Component/Output/OutputComponent.hpp"
#include "Factory.hpp"

using namespace nts;

FactoryComponent::FactoryComponent(std::string name) : _componentName(name)
{
    this->_list = {
        {"output",
            [this]() {
                return new OutputComponent(this->_componentName);
            }},
        {"input",
            [this]() {
                return new InputComponent(this->_componentName);
            }},
        {"clock",
            [this]() {
                return new ClockComponent(this->_componentName);
            }},
        {"false",
            [this]() {
                return new FalseComponent(this->_componentName);
            }},
        {"true",
            [this]() {
                return new TrueComponent(this->_componentName);
            }},
        {"logger",
            [this]() {
                return new LoggerComponent(this->_componentName);
            }},
        {"4001",
            [this]() {
                return new C4001(this->_componentName);
            }},
        {"4011",
            [this]() {
                return new C4011(this->_componentName);
            }},
        {"4030",
            [this]() {
                return new C4030(this->_componentName);
            }},
        {"4069",
            [this]() {
                return new C4069(this->_componentName);
            }},
        {"4071",
            [this]() {
                return new C4071(this->_componentName);
            }},
        {"4081",
            [this]() {
                return new C4081(this->_componentName);
            }},
        {"4013",
            [this]() {
                return new C4013(this->_componentName);
            }},
    };
}

void FactoryComponent::setComponentName(std::string name)
{
    this->_componentName = name;
}

std::unique_ptr<nts::IComponent> FactoryComponent::callFactory(
    const std::string &type, std::string name)
{
    this->setComponentName(name);
    return this->createComponent(type);
}

std::unique_ptr<IComponent> FactoryComponent::createComponent(
    const std::string &type)
{
    IComponent *ret;

    if (this->_list.find(type) != this->_list.end()) {
        ret = this->_list[type]();
    } else {
        throw ComponentTypeException(
            "Can't find component " + type, "Factory");
    }
    return std::unique_ptr<IComponent>(ret);
}