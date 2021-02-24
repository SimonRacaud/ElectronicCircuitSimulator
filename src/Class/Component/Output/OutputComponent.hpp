#ifndef OUTPUTCOMPONENT_H
#define OUTPUTCOMPONENT_H
#pragma once
	
#include "Class/Component/Component.hpp"

namespace nts
{
	class OutputComponent : public Component 
	{
		public:
			OutputComponent(const std::string &name);

            Tristate compute(size_t pin);
            void simulate(size_t time);
	};

}
#endif