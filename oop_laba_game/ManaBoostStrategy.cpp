#include "ManaBoostStrategy.h"

ManaBoostStrategy::ManaBoostStrategy(int amount) : amount(amount) {
}

void ManaBoostStrategy::apply(Unit& unit) {
	unit.increaseMana(amount);
}