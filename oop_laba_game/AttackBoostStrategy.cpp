#include "AttackBoostStrategy.h"

AttackBoostStrategy::AttackBoostStrategy(int amount) : amount(amount) {
}

void AttackBoostStrategy::apply(Unit& unit) {
	unit.increaseAttack(amount);
}