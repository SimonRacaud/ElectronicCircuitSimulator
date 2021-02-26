#ifndef LOGGERCOMPONENT_H
#define LOGGERCOMPONENT_H
#pragma once

#include <fstream>
#include "Class/Component/Component.hpp"

namespace nts
{
	class LoggerComponent : public Component 
	{
		public:
			LoggerComponent(const std::string &name);
			~LoggerComponent();

            Tristate compute(size_t pin);
            void simulate(size_t time);

		private:
			bool correctParmasForWrite(void);
			size_t binFromTristate(size_t pin);
		private:
			std::ofstream _outputFile;
	};

}
#endif