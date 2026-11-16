#pragma once

#include "IInteractionStrategy.h"

class DamageStrategy : public IInteractionStrategy {
private:
	int damage;

public:
	DamageStrategy(int damage);

	void apply(Unit& unit) override;
};