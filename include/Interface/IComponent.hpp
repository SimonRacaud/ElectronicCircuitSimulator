/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** ICompnent
*/

#ifndef ICOMPONENT_H_
#define ICOMPONENT_H_

#include <iostream>

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
        public :
            virtual ~IComponent() {};
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
    };
}

#endif