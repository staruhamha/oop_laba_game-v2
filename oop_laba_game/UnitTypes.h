#pragma once

#include "Unit.h"

class Assault : public Unit {
public:
    using Unit::Unit;

    void move(int dx, int dy) override;
    void attack(Unit& target) const override;
    void takeDamage(int damage) override;
};

class Marksman : public Unit {
public:
    using Unit::Unit;

    void move(int dx, int dy) override;
    void attack(Unit& target) const override;
    void takeDamage(int damage) override;
};

class Specialist : public Unit {
public:
    using Unit::Unit;

    void move(int dx, int dy) override;
    void attack(Unit& target) const override;
    void takeDamage(int damage) override;
};

class JetpackUnit : public Unit {
public:
    using Unit::Unit;

    void move(int dx, int dy) override;
    void attack(Unit& target) const override;
    void takeDamage(int damage) override;
};
