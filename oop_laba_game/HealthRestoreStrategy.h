#pragma once

#include "IInteractionStrategy.h"

class HealthRestoreStrategy : public IInteractionStrategy {
private:
	int amount;

public:
	HealthRestoreStrategy(int amount);

	void apply(Unit& unit) override;
};