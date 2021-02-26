/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_H_
#define CIRCUIT_H_

#include "Class/Component/Component.hpp"
#include "Class/Exception/ComponentNameException.hpp"
#include "Class/Exception/InvalidComponentNameException.hpp"
#include "Modele/Output/Output.hpp"

#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>

namespace nts
{
    class Circuit : public Component {
      private:
        std::unordered_map<std::string, IComponent *> _nodes;
        size_t _currentTick;

      public:
        Circuit(const std::string &name = "", ComponentType type = BOTH);
        ~Circuit();

        void simulate();
        void dump() const;

        std::deque<ComponentContent *> &getCircuitContent() const;
        void addNode(IComponent &component);
        void setNodeLink(const std::string &nameNodeA, std::size_t pinOutA,
            const std::string &nameNodeB, std::size_t pinInB);

        size_t getTick() const;

        void setInputComponentValue(
            const std::string &compName, Tristate value);
    };
} // namespace nts

#endif