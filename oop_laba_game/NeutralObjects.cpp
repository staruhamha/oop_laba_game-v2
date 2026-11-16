#include "NeutralObjects.h"
#include "DamageStrategy.h"
#include "HealthRestoreStrategy.h"
#include "AttackBoostStrategy.h"
#include "ResourceStrategy.h"
#include "ManaBoostStrategy.h"

NeutralObject::NeutralObject(std::shared_ptr<IInteractionStrategy> strategy) : strategy(std::move(strategy)) {
}

void NeutralObject::applyStrategy(Unit& unit) {
	if (strategy) {
		strategy->apply(unit);
	}
}


SupplyCrate::SupplyCrate(Base& base, int amount) : NeutralObject(std::make_shared<ResourceStrategy>(base, amount)) {
}

void SupplyCrate::interact(Unit& unit) {
	applyStrategy(unit);
}

void SupplyCrate::operator+(Unit& unit) {
	interact(unit);
}


Mine::Mine(int damage) : NeutralObject(std::make_shared<DamageStrategy>(damage)) {
}

void Mine::interact(Unit& unit) {
	applyStrategy(unit);
}

void Mine::operator-(Unit& unit) {
	interact(unit);
}

PowerCrate::PowerCrate(int amount) : NeutralObject(nullptr), amount(amount) {
}

void PowerCrate::interact(Unit& unit) {
	switch (unit.getTypeInfo().type) {
	case UnitType::Assault: {
		AttackBoostStrategy strategy(amount);
		strategy.apply(unit);
		break;
	}
	case UnitType::Marksman: {
		ManaBoostStrategy strategy(amount);
		strategy.apply(unit);
		break;
	}
	case UnitType::Specialist: {
		HealthRestoreStrategy strategy(amount);
		strategy.apply(unit);
		break;
	}
	case UnitType::JetpackUnit: {
		AttackBoostStrategy strategy(amount);
		strategy.apply(unit);
		break;
	}
	}
}

void PowerCrate::operator*(Unit& unit) {
	interact(unit);
}


Dispenser::Dispenser(int amount) : NeutralObject(std::make_shared<HealthRestoreStrategy>(amount)) {
}

void Dispenser::interact(Unit& unit) {
	applyStrategy(unit);
}

void Dispenser::operator/(Unit& unit) {
	interact(unit);
}
