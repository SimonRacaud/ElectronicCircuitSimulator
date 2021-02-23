#ifndef FACTORYCOMPONENT_H
#define FACTORYCOMPONENT_H
#pragma once

#include <memory>
#include <functional>
#include <unordered_map>
#include "Interface/IComponent.hpp"

namespace nts
{
	class FactoryComponent
	{
		public:
			FactoryComponent();
            std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

		private:
			std::unordered_map <std::string, std::function<IComponent *(Tristate state, IComponent &component)>> _list;
	};
}
#endif