#include "UnitTypes.h"

void Assault::move(int dx, int dy) {
	Unit::move(dx, dy);
}

void Assault::attack(Unit& target) const {
	int damage = calculateDamage();
	target.takeDamage(damage);
}

void Assault::takeDamage(int damage) {
	Unit::takeDamage(damage);
}


void Marksman::move(int dx, int dy) {
	Unit::move(dx, dy);
}

void Marksman::attack(Unit& target) const {
	int damage = calculateDamage();
	target.takeDamage(damage);
}

void Marksman::takeDamage(int damage) {
	Unit::takeDamage(damage);
}


void Specialist::move(int dx, int dy) {
	Unit::move(dx, dy);
}

void Specialist::attack(Unit& target) const {
	int damage = calculateDamage();
	target.takeDamage(damage);
}

void Specialist::takeDamage(int damage) {
	Unit::takeDamage(damage);
}


void JetpackUnit::move(int dx, int dy) {
	Unit::move(dx, dy);
}

void JetpackUnit::attack(Unit& target) const {
	int damage = calculateDamage();
	target.takeDamage(damage);
}

void JetpackUnit::takeDamage(int damage) {
	Unit::takeDamage(damage);
}