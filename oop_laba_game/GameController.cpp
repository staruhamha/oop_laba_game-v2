#include "GameController.h"
#include "NeutralObjects.h"
#include <iostream>

GameController::GameController(int baseHealth, int maxUnits, int defenseLevel, int resources, int mapWidth, int mapHeight) {
	base = std::make_shared<Base>(baseHealth, maxUnits, defenseLevel, resources);
	terrainMap = std::make_shared<TerrainMap>(mapWidth, mapHeight);
}

Base& GameController::getBase() {
	return *base;
}

const Base& GameController::getBase() const {
	return *base;
}


TerrainMap& GameController::getTerrainMap() {
	return *terrainMap;
}

const TerrainMap& GameController::getTerrainMap() const {
	return *terrainMap;
}

std::shared_ptr<Unit> GameController::createUnit(const UnitFactory& factory, int x, int y, const std::string& type) {
	std::unique_ptr<Unit> unit = factory.createUnit(x, y, type);

	if (unit == nullptr) {
		return nullptr;
	}

	std::shared_ptr<Unit> sharedUnit = std::move(unit);
	base->addUnit(sharedUnit);

	std::cout << "Создан юнит с ID: " << sharedUnit->getId() << std::endl;

	return sharedUnit;
}

bool GameController::moveUnit(Unit& unit, int dx, int dy) {
	int newX = unit.getX() + dx;
	int newY = unit.getY() + dy;

	if (newX < 0 || newY < 0 ||
		newX >= terrainMap->getWidth() || newY >= terrainMap->getHeight()) {
		std::cout << "Нельзя переместиться за пределы карты." << std::endl;
		return false;
	}

	Terrain* terrain = terrainMap->getTerrain(newX, newY);

	if (terrain == nullptr) {
		std::cout << "В этой клетке не задан ландшафт." << std::endl;
		return false;
	}

	UnitType type = unit.getTypeInfo().type;

	if (!terrain->isPassable(type)) {
		std::cout << "Юнит не может пройти через этот ландшафт." << std::endl;
		return false;
	}

	float speedModifier = terrain->getSpeedModifier(type);
	int defenseBonus = terrain->getDefenseBonus(type);

	unit.move(dx, dy);

	std::cout << "Юнит переместился на (" << newX << ", " << newY << ")." << std::endl;
	std::cout << "Модификатор скорости: " << speedModifier << std::endl;
	std::cout << "Бонус защиты: " << defenseBonus << std::endl;

	return true;
}

bool GameController::removeDestroyedUnit(const Unit& unit) {
	if (!unit.getHealth().isZero()) {
		std::cout << "Юнит ещё жив. Удаление невозможно." << std::endl;
		return false;
	}

	base->removeUnit(unit.getId());

	std::cout << "Уничтоженный юнит удалён из базы." << std::endl;
	return true;
}

bool GameController::interactWithObject(Unit& unit) {
	NeutralObject* object = terrainMap->getNeutralObjectAt(unit.getX(), unit.getY());

	if (object == nullptr) {
		std::cout << "На этой клетке нет нейтрального объекта." << std::endl;
		return false;
	}

	if (SupplyCrate* crate = dynamic_cast<SupplyCrate*>(object)) {
		*crate + unit;
	}
	else if (Mine* mine = dynamic_cast<Mine*>(object)) {
		*mine - unit;
	}
	else if (PowerCrate* powerCrate = dynamic_cast<PowerCrate*>(object)) {
		*powerCrate* unit;
	}
	else if (Dispenser* dispenser = dynamic_cast<Dispenser*>(object)) {
		*dispenser / unit;
	}
	else {
		std::cout << "Неизвестный тип нейтрального объекта." << std::endl;
		return false;
	}
	std::cout << "Юнит взаимодействовал с нейтральным объектом." << std::endl;

	return true;
}
