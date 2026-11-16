#include "HealthRestoreStrategy.h"

HealthRestoreStrategy::HealthRestoreStrategy(int amount) : amount(amount) {
}

void HealthRestoreStrategy::apply(Unit& unit) {
	unit.restoreHealth(amount);
}