#ifndef LOGGERCOMPONENT_H
#define LOGGERCOMPONENT_H
#pragma once

#include "Class/Component/Output/OutputComponent.hpp"

namespace nts
{
	class LoggerComponent : public OutputComponent 
	{
		public:
			LoggerComponent(Tristate state, IComponent &component);

			Tristate getState() const;
			IComponent &getComponent() const;

			void setState(Tristate state);
			void setComponent(IComponent &component);
            Tristate compute(size_t pin);
            void simulate(size_t time);

		private:
			bool correctParmasForWrite(void);
			char charFromTristate(Tristate state);

		private:
			Tristate _state;
			IComponent &_component;
	};

}
#endif