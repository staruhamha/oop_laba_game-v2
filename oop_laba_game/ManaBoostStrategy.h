#pragma once

#include "IInteractionStrategy.h"

class ManaBoostStrategy : public IInteractionStrategy {
private:
	int amount;

public:
	ManaBoostStrategy(int amount);

	void apply(Unit& unit) override;
};