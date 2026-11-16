#pragma once

class Attack {
private:
	int damage;

public:
	Attack(int damage);

	Attack(const Attack& other) = default;
	Attack(Attack&& other) noexcept = default;
	Attack& operator=(const Attack& other) = default;
	Attack& operator=(Attack&& other) noexcept = default;

	int getDamage() const;
	void setDamage(int damage);
	
	int calculateDamage(int enemyArmor) const;
};