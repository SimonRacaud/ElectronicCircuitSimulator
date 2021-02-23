/*
 * File: nts::TristateOperators.hpp
 * Project: nts::Tristate
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Tuesday, 23rd February 2021 4:20:35 pm
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef H_TRISTATE_OP
#define H_TRISTATE_OP

#include "IComponent.hpp"

nts::Tristate operator&(const nts::Tristate &a, const nts::Tristate &b);
nts::Tristate operator|(const nts::Tristate &a, const nts::Tristate &b);
nts::Tristate operator^(const nts::Tristate &a, const nts::Tristate &b);
nts::Tristate operator!(const nts::Tristate &a);

#endif // !H_TRISTATE_OP