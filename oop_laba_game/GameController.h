#pragma once

#include <memory>
#include <string>
#include "Base.h"
#include "TerrainMap.h"
#include "Factories.h"

class GameController {
private:
	std::shared_ptr<Base> base;
	std::shared_ptr<TerrainMap> terrainMap;

public:
	GameController(int baseHealth, int maxUnits, int defenseLevel, int resources, int mapWidth, int mapHeight);

	GameController(const GameController& other) = delete;
	GameController& operator=(const GameController& other) = delete;
	GameController(GameController&& other) noexcept = default;
	GameController& operator=(GameController&& other) noexcept = default;

	Base& getBase();
	const Base& getBase() const;

	TerrainMap& getTerrainMap();
	const TerrainMap& getTerrainMap() const;

	std::shared_ptr<Unit> createUnit(const UnitFactory& factory, int x, int y, const std::string& type);
	bool moveUnit(Unit& unit, int dx, int dy);
	bool removeDestroyedUnit(const Unit& unit);
	bool interactWithObject(Unit& unit);
};
