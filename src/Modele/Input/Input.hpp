#ifndef INPUT_H
#define INPUT_H
#pragma once
	
#include "IComponent.hpp"

namespace nts
{
	class Input  
	{
		public:
			Input(Tristate state, IComponent &component);

			Tristate getState() const;
			IComponent &getComponent() const;

			void setState(Tristate state);
			void setComponent(IComponent &component);
            void setInputValue(Tristate state);

		private:
			Tristate _state;
			IComponent &_component;
	};

}
#endif