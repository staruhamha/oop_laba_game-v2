#pragma once

#include "UnitTypeInfo.h"

class Terrain {
public:
	virtual ~Terrain() = default;

	virtual bool isPassable(UnitType type) const = 0;
	virtual float getSpeedModifier(UnitType type) const = 0;
	virtual int getDefenseBonus(UnitType type) const = 0;
};
