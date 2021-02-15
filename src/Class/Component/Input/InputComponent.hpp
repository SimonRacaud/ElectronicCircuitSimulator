#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H
#pragma once
	
#include "Class/Component/Component.hpp"

namespace nts
{
	class InputComponent : public Component 
	{
		public:
			InputComponent(Tristate state, IComponent &component);

			Tristate getState() const;
			IComponent &getComponent() const;

			void setState(Tristate state);
			void setComponent(IComponent &component);
            void setInputValue(Tristate state);
            Tristate compute(size_t pin);
            void simulate(size_t time);

		private:
			Tristate _state;
			IComponent &_component;
	};

}
#endif