#ifndef H_C4008
#define H_C4008

#include "Class/Component/Component.hpp"
#include "Class/Gate/Not/NotGate.hpp"
#include "Class/Gate/Or/OrGate.hpp"
#include "Error/Error.hpp"
#include <unordered_map>

namespace nts
{
    class C4008 : public Component {
      public:
        C4008(std::string const &name);
        virtual ~C4008();

        nts::Tristate compute(std::size_t pin);

      private:
        Tristate getDirectState(size_t pin);
        Tristate simpleAdder(Tristate a, Tristate b);
        Tristate alphAdder(Tristate a, Tristate b, Tristate &c);
      private:
        Tristate _carry;
    };
}

#endif