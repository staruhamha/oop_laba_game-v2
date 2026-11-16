#pragma once
#include "Terrain.h"

class Plains : public Terrain {
public:
	bool isPassable(UnitType type) const override;
	float getSpeedModifier(UnitType type) const override;
	int getDefenseBonus(UnitType type) const override;
};


class Forest : public Terrain {
public:
	bool isPassable(UnitType type) const override;
	float getSpeedModifier(UnitType type) const override;
	int getDefenseBonus(UnitType type) const override;
};


class Swamp : public Terrain {
public:
	bool isPassable(UnitType type) const override;
	float getSpeedModifier(UnitType type) const override;
	int getDefenseBonus(UnitType type) const override;
};


class Mountains : public Terrain {
public:
	bool isPassable(UnitType type) const override;
	float getSpeedModifier(UnitType type) const override;
	int getDefenseBonus(UnitType type) const override;
};