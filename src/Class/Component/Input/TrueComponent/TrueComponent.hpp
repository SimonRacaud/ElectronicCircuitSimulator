#ifndef TRUECOMPONENT_H
#define TRUECOMPONENT_H
#pragma once
	
#include "Class/Component/Input/InputComponent.hpp"

namespace nts
{
	class TrueComponent : public InputComponent
	{
		public:
			TrueComponent(const std::string &name = "true");

			void simulate(size_t time);
            Tristate compute(size_t pin);
	};

}
#endif