#pragma once

#include "UnitFactory.h"

class AssaultFactory : public UnitFactory {
public:
	std::unique_ptr<Unit> createUnit(int x, int y, const std::string& type) const override;
};

class MarksmanFactory : public UnitFactory {
public:
	std::unique_ptr<Unit> createUnit(int x, int y, const std::string& type) const override;
};

class SpecialistFactory : public UnitFactory {
public:
	std::unique_ptr<Unit> createUnit(int x, int y, const std::string& type) const override;
};

class JetpackFactory : public UnitFactory {
public:
	std::unique_ptr<Unit> createUnit(int x, int y, const std::string& type) const override;
};
