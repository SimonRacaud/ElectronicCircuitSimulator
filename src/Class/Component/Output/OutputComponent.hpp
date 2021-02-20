#ifndef OUTPUTCOMPONENT_H
#define OUTPUTCOMPONENT_H
#pragma once
	
#include "Class/Component/Component.hpp"

namespace nts
{
	class OutputComponent : public Component 
	{
		public:
			OutputComponent(Tristate state, IComponent &component);

			Tristate getState() const;
			IComponent &getComponent() const;

			void setState(Tristate state);
			void setComponent(IComponent &component);
            Tristate compute(size_t pin);
            void simulate(size_t time);

		private:
			Tristate _state;
			IComponent &_component;
	};

}
#endif