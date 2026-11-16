#pragma once

#include "Unit.h"

class IInteractionStrategy {
public:
	virtual ~IInteractionStrategy() = default;

	virtual void apply(Unit& unit) = 0;
};