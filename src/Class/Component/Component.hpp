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

#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>

namespace nts
{
    class Input;

    class Component : public IComponent {
      protected:
        std::string _name;
        ComponentType _type;
        size_t _computeCalls;
        size_t _connectedInPins;
        std::unordered_map<size_t, Input *> _inputs;
        std::unordered_map<size_t, Output *> _outputs;

        void simulateNextNodes(size_t tick);

      public:
        Component(const std::string &name = "", ComponentType type = OTHER);
        ~Component();

        void createInputs(const size_t *pins, size_t size);
        void createOutputs(const size_t *pins, size_t size);

        void simulate(std::size_t tick);
        virtual nts::Tristate compute(std::size_t pin);
        void setLink(
            std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        Tristate getState(size_t pinOut);
        virtual ComponentContent *getContent() const;
        const std::string &getName() const;
        ComponentType getType() const;
        bool isLastCompute(void) const;

        void setState(Tristate state);

        static std::unordered_map<Tristate, std::string> TRISTATE_STR;
        static size_t nbJump;
    };
} // namespace nts

#endif