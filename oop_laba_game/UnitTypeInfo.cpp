#include "UnitTypeInfo.h"
using namespace std;

UnitTypeInfo::UnitTypeInfo(int maxHealth, int baseAttack, int baseSpeed, int cost, UnitType type) : maxHealth(maxHealth), baseAttack(baseAttack), baseSpeed(baseSpeed), cost(cost), type(type) {
}

shared_ptr<UnitTypeInfo> UnitTypeInfo::getInfo(UnitType type) {
	static unordered_map<UnitType, shared_ptr<UnitTypeInfo>> pool = {
		{UnitType::Assault, make_shared<UnitTypeInfo>(200, 25, 3, 100, UnitType::Assault) },
		{UnitType::Marksman, make_shared<UnitTypeInfo>(120, 60, 2, 120, UnitType::Marksman)},
		{UnitType::Specialist, make_shared<UnitTypeInfo>(150, 30, 2, 110, UnitType::Specialist)},
		{UnitType::JetpackUnit, make_shared<UnitTypeInfo>(170, 30, 4, 150, UnitType::JetpackUnit)}
	};
	return pool.at(type);
}