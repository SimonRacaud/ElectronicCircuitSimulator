/*
 * File: ComponentContent.hpp
 * Project: Modele
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 9th February 2021 11:06:10 am
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef H_COMPONENT_CONTENT
#define H_COMPONENT_CONTENT

#include <string>
#include "ComponentType.hpp"
#include "IComponent.hpp"
#include <unordered_map>

namespace nts
{
    class ComponentContent {
      public:
        ComponentContent(const std::string &name, ComponentType type,
            std::unordered_map<size_t, Tristate> &outputs);
        ~ComponentContent();

        const std::string &getName() const;
        ComponentType getType() const;
        const std::unordered_map<size_t, Tristate> &getPins() const;

      private:
        std::string _name;
        ComponentType _type;
        std::unordered_map<size_t, Tristate> _pins;
    };
} // namespace nts

#endif // DEBUG