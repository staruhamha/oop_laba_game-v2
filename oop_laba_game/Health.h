#pragma once

class Health {
private:
	int currentHealth;
	int maxHealth;

public:
	Health(int maxHealth);

	Health(const Health& other) = default;
	Health(Health&& other) noexcept = default;
	Health& operator=(const Health& other) = default;
	Health& operator=(Health&& other) noexcept = default;

	int getCurrentHealth() const;
	int getMaxHealth() const;

	void setCurrentHealth(int health);

	void increase(int amount);
	void decrease(int amount);
	bool isZero() const;
};