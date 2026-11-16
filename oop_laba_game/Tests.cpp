#include "Tests.h"
#include "UnitTypeInfo.h"
#include "TerrainTypes.h"
#include "GameController.h"
#include "Factories.h"
#include <iostream>

void checkTest(const std::string& name, bool condition) {
	if (condition) {
		std::cout << "Тест пройден: " << name << "\n";
	}
	else {
		std::cout << "Тест не пройден: " << name << "\n";
	}
}

void testUnitTypeInfo() {
	auto assault = UnitTypeInfo::getInfo(UnitType::Assault);
	auto marksman = UnitTypeInfo::getInfo(UnitType::Marksman);
	auto specialist = UnitTypeInfo::getInfo(UnitType::Specialist);
	auto jetpack = UnitTypeInfo::getInfo(UnitType::JetpackUnit);

	checkTest("Assault существует", assault != nullptr);
	checkTest("Marksman существует", marksman != nullptr);
	checkTest("Specialist существует", specialist != nullptr);
	checkTest("JetpackUnit существует", jetpack != nullptr);

	checkTest("Здоровье Assault", assault->maxHealth == 200);
	checkTest("Здоровье Marksman", marksman->maxHealth == 120);
	checkTest("Здоровье Specialist", specialist->maxHealth == 150);
	checkTest("Здоровье JetpackUnit", jetpack->maxHealth == 170);

	checkTest("Тип Assault", assault->type == UnitType::Assault);
	checkTest("Тип Marksman", marksman->type == UnitType::Marksman);
	checkTest("Тип Specialist", specialist->type == UnitType::Specialist);
	checkTest("Тип JetpackUnit", jetpack->type == UnitType::JetpackUnit);
}

void testTerrain() {
	Forest forest;
	Swamp swamp;
	Mountains mountains;

	checkTest("Soldier не проходит через горы", !mountains.isPassable(UnitType::Assault));
	checkTest("Sniper проходит через горы", mountains.isPassable(UnitType::Marksman));
	checkTest("JetpackTrooper проходит через горы", mountains.isPassable(UnitType::JetpackUnit));

	checkTest("Бонус защиты леса", forest.getDefenseBonus(UnitType::Assault) == 15);

	checkTest("Замедление Soldier в болоте", swamp.getSpeedModifier(UnitType::Assault) == 0.5f);
	checkTest("Soldier проходит через болото", swamp.isPassable(UnitType::Assault));
	checkTest("Sniper не проходит через болото", !swamp.isPassable(UnitType::Marksman));
}

void testBaseUnitCount() {
	GameController controller(1000, 3, 0, 100, 3, 3);
	AssaultFactory factory;

	auto unit = controller.createUnit(factory, 0, 0, "Soldier");

	checkTest("Счётчик базы после создания юнита",
		unit != nullptr && controller.getBase().getUnitCount() == 1);

	if (unit != nullptr) {
		unit->takeDamage(10000);

		checkTest("Счётчик базы после уничтожения юнита",
			controller.getBase().getUnitCount() == 0);

		controller.removeDestroyedUnit(*unit);
	}
}

void runTests() {
	std::cout << "\nТестирование UnitTypeInfo\n";
	testUnitTypeInfo();

	std::cout << "\nТестирование ландшафтов\n";
	testTerrain();

	std::cout << "\nТестирование счётчика базы\n";
	testBaseUnitCount();

	std::cout << "\nТестирование завершено\n";
}