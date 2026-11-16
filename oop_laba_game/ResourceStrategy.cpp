#include "ResourceStrategy.h"

ResourceStrategy::ResourceStrategy(Base& base, int amount) : amount(amount), base(base) {
}

void ResourceStrategy::apply(Unit& unit) {
	base.addResources(amount);
}