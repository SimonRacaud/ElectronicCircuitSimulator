/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Component
*/

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "Class/Exception/ComponentTypeException.hpp"
#include "ComponentType.hpp"
#include "IComponent.hpp"
#include "Modele/ComponentContent/ComponentContent.hpp"
#include "Modele/Input/Input.hpp"
#include "Modele/Output/Output.hpp"

#include <string>
#include <unordered_map>

namespace nts
{
    class Input;

    class Component : public IComponent {
      protected:
        std::string _name;
        ComponentType _type;
        std::unordered_map<size_t, Input *> _inputs;
        std::unordered_map<size_t, Output *> _outputs;

      public:
        Component(const std::string &name = "", ComponentType type = OTHER);
        ~Component();

        void createInputs(const size_t *pins, size_t size);
        void createOutputs(const size_t *pins, size_t size);

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(
            std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        Tristate getState(size_t pinOut);
        ComponentContent &getContent() const;
        const std::string &getName() const;
        ComponentType getType() const;

        void setState(Tristate state);
    };
} // namespace nts

#endif