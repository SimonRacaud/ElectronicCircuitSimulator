/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_H_
#define CIRCUIT_H_

#include "Class/Component/Component.hpp"
#include "Modele/Output/Output.hpp"
#include "Class/Exception/ComponentNameException.hpp"

#include <unordered_map>
#include <string>
#include <deque>
#include <algorithm>

namespace nts
{
    class Circuit : public Component
    {
        private:
            std::unordered_map<std::string, IComponent *> _nodes;
            size_t _currentTick;

        public:
            Circuit(const std::string &name = "", ComponentType type = BOTH);
            ~Circuit();

            void simulate();
            void dump() const;

            std::deque<ComponentContent *> &getContent() const;
            void addNode(IComponent &component);
            void setNodeLink(const std::string &nameNodeA, std::size_t pinOutA, 
                const std::string &nameNodeB, std::size_t pinInB);
    };
}

#endif