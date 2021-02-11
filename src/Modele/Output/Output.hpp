#ifndef OUTPUT_H
#define OUTPUT_H
#pragma once
	
#include "IComponent.hpp"

namespace nts
{
	class Output  
	{
		public:
			Output(Tristate state, IComponent &component);

			Tristate getState() const;
			IComponent &getComponent() const;

			void setState(Tristate state);
			void setComponent(IComponent &component);

		private:
			Tristate _state;
			IComponent &_component;
	};

}
#endif