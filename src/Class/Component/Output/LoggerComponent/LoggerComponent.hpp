#ifndef LOGGERCOMPONENT_H
#define LOGGERCOMPONENT_H
#pragma once

#include "Class/Component/Output/OutputComponent.hpp"

namespace nts
{
	class LoggerComponent : public OutputComponent 
	{
		public:
			LoggerComponent(const std::string &name);

            Tristate compute(size_t pin);
            void simulate(size_t time);

		private:
			bool correctParmasForWrite(void);
			char charFromTristate(Tristate state);
	};

}
#endif