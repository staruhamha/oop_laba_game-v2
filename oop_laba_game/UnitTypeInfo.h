#pragma once
#include <memory>
#include <unordered_map>

enum class UnitType {
    Assault,
    Marksman,
    Specialist,
    JetpackUnit
};

class UnitTypeInfo {
public:
    const int maxHealth;
    const int baseAttack;
    const int baseSpeed;
    const int cost;
    const UnitType type;

    UnitTypeInfo(int maxHealth, int baseAttack, int baseSpeed, int cost, UnitType type);

    static std::shared_ptr<UnitTypeInfo> getInfo(UnitType type);
};
