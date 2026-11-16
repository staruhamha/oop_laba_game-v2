#include "Base.h"
#include "Factories.h"
#include <iostream>


Base::Base(int health, int maxUnits, int defenseLevel, int resources) : health(health), maxUnits(maxUnits), unitCount(0), defenseLevel(defenseLevel), resources(resources) {
}


int Base::getHealth() const {
	return health;
}

int Base::getMaxUnits() const {
	return maxUnits;
}

int Base::getDefenseLevel() const {
	return defenseLevel;
}

int Base::getResources() const {
	return resources;
}

int Base::getUnitCount() const {
	return unitCount;
}


void Base::setHealth(int health) {
	this->health = health;
}

void Base::setDefenseLevel(int defenseLevel) {
	this->defenseLevel = defenseLevel;
}

void Base::addResources(int amount) {
	resources += amount;
}

void Base::onUnitEvent(const UnitEvent& event) {
	switch (event.type) {
	case UnitEventType::Created:
		unitCount++;
		std::cout << "Юнит создан." << std::endl;
		break;

	case UnitEventType::Damaged:
		std::cout << "Юнит получил урон: " << event.damage << std::endl;
		break;

	case UnitEventType::Destroyed:
		if (unitCount > 0) {
			unitCount--;
		}
		std::cout << "Юнит устранён." << std::endl;
		break;
	}
}

void Base::addUnit(const std::shared_ptr<Unit>& unit) {
	if (unit != nullptr && unitCount < maxUnits) {
		units.push_back(unit);
		unit->subscribe(this);
		unit->notify(UnitEvent(UnitEventType::Created, unit->getId(), 0));
	}
}

std::shared_ptr<Unit> Base::createUnit(int x, int y, const std::string& type) {
	if (unitCount >= maxUnits) {
		return nullptr;
	}

	std::unique_ptr<Unit> newUnit;

	AssaultFactory assaultFactory;
	MarksmanFactory marksmanFactory;
	SpecialistFactory specialistFactory;
	JetpackFactory jetpackFactory;

	newUnit = assaultFactory.createUnit(x, y, type);

	if (newUnit == nullptr) {
		newUnit = marksmanFactory.createUnit(x, y, type);
	}

	if (newUnit == nullptr) {
		newUnit = specialistFactory.createUnit(x, y, type);
	}

	if (newUnit == nullptr) {
		newUnit = jetpackFactory.createUnit(x, y, type);
	}

	if (newUnit == nullptr) {
		return nullptr;
	}

	std::shared_ptr<Unit> unit = std::move(newUnit);
	addUnit(unit);

	return unit;
}

void Base::removeUnit(int unitId) {
	for (auto it = units.begin(); it != units.end(); ++it) {
		if ((*it)->getId() == unitId) {
			(*it)->unsubscribe(this);
			units.erase(it);
			break;
		}
	}
}