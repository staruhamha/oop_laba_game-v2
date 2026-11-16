#pragma once

#include <memory>
#include <vector>
#include "Unit.h"
#include "IObserver.h"
#include <string>

class Base : public IObserver {
private:
	int health;
	int maxUnits;
	int unitCount;
	int defenseLevel;
	int resources;
	std::vector<std::shared_ptr<Unit>> units;
	

public:
	Base(int health, int maxUnits, int defenseLevel, int resources);

	Base(const Base& other) = delete;
	Base& operator=(const Base& other) = delete;
	Base(Base&& other) = delete;
	Base& operator=(Base&& other) = delete;

	int getHealth() const;
	int getMaxUnits() const;
	int getDefenseLevel() const;
	int getResources() const;
	int getUnitCount() const;
	void setHealth(int health);
	void setDefenseLevel(int defenseLevel);
	void addResources(int amount);

	void onUnitEvent(const UnitEvent& event) override;

	void addUnit(const std::shared_ptr<Unit>& unit);
	std::shared_ptr<Unit> createUnit(int x, int y, const std::string& type);
	void removeUnit(int unitId);
};
