#ifndef FALSECOMPONENT_H
#define FALSECOMPONENT_H
#pragma once
	
#include "Class/Component/Input/InputComponent.hpp"

namespace nts
{
	class FalseComponent : public InputComponent
	{
		public:
			FalseComponent(Tristate state, IComponent &component);

			void simulate(size_t time);
            Tristate compute(size_t pin);
	};

}
#endif