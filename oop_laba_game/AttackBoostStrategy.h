#pragma once

#include "IInteractionStrategy.h"

class AttackBoostStrategy : public IInteractionStrategy {
private:
	int amount;

public:
	AttackBoostStrategy(int amount);

	void apply(Unit& unit) override;
};