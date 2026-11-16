#pragma once

#include <memory>
#include "IInteractionStrategy.h"
#include "Base.h"
#include "Unit.h"

class NeutralObject {
protected:
	std::shared_ptr<IInteractionStrategy> strategy;

	void applyStrategy(Unit& unit);

public:
	NeutralObject(std::shared_ptr<IInteractionStrategy> strategy);

	NeutralObject(const NeutralObject& other) = default;
	NeutralObject(NeutralObject&& other) noexcept = default;
	NeutralObject& operator=(const NeutralObject& other) = default;
	NeutralObject& operator=(NeutralObject&& other) noexcept = default;

	virtual ~NeutralObject() = default;

	virtual void interact(Unit& unit) = 0;
};


class SupplyCrate : public NeutralObject {
public:
	SupplyCrate(Base& base, int amount);

	void interact(Unit& unit) override;

	void operator+(Unit& unit);
};

class Mine : public NeutralObject {
public:
	Mine(int damage);

	void interact(Unit& unit) override;

	void operator-(Unit& unit);
};


class PowerCrate : public NeutralObject {
private:
	int amount;

public:
	PowerCrate(int amount);

	void interact(Unit& unit) override;

	void operator*(Unit& unit);
};


class Dispenser : public NeutralObject {
public:
	Dispenser(int amount);

	void interact(Unit& unit) override;

	void operator/(Unit& unit);
};