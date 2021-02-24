#ifndef CLOCKCOMPONENT_H
#define CLOCKCOMPONENT_H
#pragma once
	
#include "Class/Component/Input/InputComponent.hpp"

namespace nts
{
	class ClockComponent : public InputComponent
	{
		public:
			ClockComponent(const std::string &name = "clock");

			void simulate(size_t time);
            Tristate compute(size_t pin);
	};

}
#endif