#include "Factories.h"
#include "Units.h"
using namespace std;

unique_ptr<Unit> AssaultFactory::createUnit(int x, int y, const string& type) const {
	if (type == "Soldier") {
		return make_unique<Soldier>(x, y);
	}
	if (type == "Heavy") {
		return make_unique<Heavy>(x, y);
	}
	if (type == "Rifleman") {
		return make_unique<Rifleman>(x, y);
	}
	if (type == "Grenadier") {
		return make_unique<Grenadier>(x, y);
	}

	return nullptr;
}


unique_ptr<Unit> MarksmanFactory::createUnit(int x, int y, const string& type) const {
	if (type == "Sniper") {
		return make_unique<Sniper>(x, y);
	}

	return nullptr;
}


unique_ptr<Unit> SpecialistFactory::createUnit(int x, int y, const string& type) const {
	if (type == "Pyro") {
		return make_unique<Pyro>(x, y);
	}
	if (type == "Engineer") {
		return make_unique<Engineer>(x, y);
	}
	if (type == "Medic") {
		return make_unique<Medic>(x, y);
	}
	if (type == "FieldMedic") {
		return make_unique<FieldMedic>(x, y);
	}

	return nullptr;
}


unique_ptr<Unit> JetpackFactory::createUnit(int x, int y, const string& type) const {
	if (type == "JetpackTrooper") {
		return make_unique<JetpackTrooper>(x, y);
	}

	return nullptr;
}