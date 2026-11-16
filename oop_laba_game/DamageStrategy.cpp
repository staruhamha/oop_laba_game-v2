#include "DamageStrategy.h"

DamageStrategy::DamageStrategy(int damage) : damage(damage) {
}

void DamageStrategy::apply(Unit& unit) {
	unit.takeDamage(damage);
}