#pragma once

class Armor {
private:
	int currentArmor;
	int maxArmor;

public:
	Armor(int maxArmor);

	Armor(const Armor& other) = default;
	Armor(Armor&& other) noexcept = default;
	Armor& operator=(const Armor& other) = default;
	Armor& operator=(Armor&& other) noexcept = default;

	int getCurrentArmor() const;
	int getMaxArmor() const;

	void setCurrentArmor(int armor);

	void increase(int amount);
	void decrease(int amount);
	bool isZero() const;

	int reduceDamage(int damage);
};