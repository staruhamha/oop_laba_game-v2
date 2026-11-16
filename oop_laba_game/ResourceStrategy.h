#pragma once

#include "IInteractionStrategy.h"
#include "Base.h"

class ResourceStrategy : public IInteractionStrategy {
private:
	int amount;
	Base& base;

public:
	ResourceStrategy(Base& base, int amount);

	void apply(Unit& unit) override;
};