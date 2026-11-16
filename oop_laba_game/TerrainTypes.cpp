#include "TerrainTypes.h"


bool Plains::isPassable(UnitType type) const {
	return true;
}

float Plains::getSpeedModifier(UnitType type) const {
	return 1.0f;
}

int Plains::getDefenseBonus(UnitType type) const {
	return 0;
}


bool Forest::isPassable(UnitType type) const {
	return true;
}

float Forest::getSpeedModifier(UnitType type) const {
	switch (type) {
	case UnitType::Assault:
		return 0.8f;
	case UnitType::Marksman:
		return 0.9f;
	case UnitType::Specialist:
		return 0.9f;
	case UnitType::JetpackUnit:
		return 1.0f;
	}
	return 1.0f;
}

int Forest::getDefenseBonus(UnitType type) const {
	return 15;
}


bool Swamp::isPassable(UnitType type) const {
	return type != UnitType::Marksman && type != UnitType::Specialist;
}

float Swamp::getSpeedModifier(UnitType type) const {
	switch (type) {
	case UnitType::Assault:
		return 0.5f;
	case UnitType::Marksman:
		return 0.6f;
	case UnitType::Specialist:
		return 0.6f;
	case UnitType::JetpackUnit:
		return 1.0f;
	}
	return 1.0f;
}

int Swamp::getDefenseBonus(UnitType type) const {
	return 0;
}


bool Mountains::isPassable(UnitType type) const {
	return type == UnitType::Marksman || type == UnitType::JetpackUnit;
}

float Mountains::getSpeedModifier(UnitType type) const {
	switch (type) {
	case UnitType::Assault:
		return 0.7f;
	case UnitType::Marksman:
		return 0.8f;
	case UnitType::Specialist:
		return 0.7f;
	case UnitType::JetpackUnit:
		return 1.0f;
	}
	return 1.0f;
}

int Mountains::getDefenseBonus(UnitType type) const {
	return 25;
}