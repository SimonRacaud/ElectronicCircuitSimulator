#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H
#pragma once
	
#include "Class/Component/Component.hpp"

namespace nts
{
	class InputComponent : public Component 
	{
		public:
			InputComponent(const std::string &name);

            Tristate compute(size_t pin);
            void simulate(size_t time);
	};

}
#endif