#ifndef OUTPUT_H
#define OUTPUT_H
#pragma once

#include <algorithm>
#include <deque>
#include "IComponent.hpp"
#include "InvalidLinkException.hpp"

namespace nts
{
    class Output {
      public:
        Output();

        Tristate getState() const;
        std::deque<IComponent *> const &getComponents() const;

        void setNewState(Tristate state);
        void updateState(void);
        void addComponent(IComponent &component);

      private:
        Tristate _newState;
        Tristate _state;
        std::deque<IComponent *> _components;
    };

} // namespace nts
#endif