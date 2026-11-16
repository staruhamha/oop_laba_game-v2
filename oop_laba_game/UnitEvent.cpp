#include "UnitEvent.h"

UnitEvent::UnitEvent(UnitEventType type, int unitId, int damage) : type(type), unitId(unitId), damage(damage), timestamp(std::chrono::system_clock::now()) {
}