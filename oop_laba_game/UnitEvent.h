#pragma once

#include <chrono>

enum class UnitEventType {
	Created,
	Damaged,
	Destroyed
};

class UnitEvent {
public:
	UnitEventType type;
	int unitId;
	int damage;
	std::chrono::system_clock::time_point timestamp;

	UnitEvent(UnitEventType type, int unitId, int damage);
};