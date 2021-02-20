#ifndef CLOCKCOMPONENT_H
#define CLOCKCOMPONENT_H
#pragma once
	
#include "Class/Component/Input/InputComponent.hpp"

namespace nts
{
	class ClockComponent : public InputComponent
	{
		public:
			ClockComponent(Tristate state, IComponent &component);

			void simulate(size_t time);
            Tristate compute(size_t pin);
	};

}
#endif