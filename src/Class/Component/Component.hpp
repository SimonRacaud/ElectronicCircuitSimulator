/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Component
*/

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "IComponent.hpp"
#include "Modele/Output/Output.hpp"
#include "Modele/ComponentContent/ComponentContent.hpp"
#include "ComponentType.hpp"

#include <string>
#include <unordered_map>

namespace nts
{
    class Component : public IComponent
    {
        protected:
            std::string _name;
            ComponentType _type;
            std::unordered_map<size_t, IComponent *> _inputs;
            std::unordered_map<size_t, Output*> _outputs;

            Tristate getState(size_t pinOut);
        public:
            Component(const std::string &name = "", ComponentType type = OTHER);
            ~Component();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void dump() const;

            ComponentContent &getContent() const;
            const std::string &getName() const;
    };
}

#endif