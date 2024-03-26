#pragma once
#include "StatBlock_Fates.h"
#include <vector>
class Unit_Base_Fates :
	public StatBlock_Fates
{
public:
	Unit_Base_Fates();
	Unit_Base_Fates(const Unit_Base_Fates&);
	Unit_Base_Fates(Unit_Base_Fates&&) noexcept;
	friend void swap(const Unit_Base_Fates&, const Unit_Base_Fates&);

private:
	Ability_FE personal_skill_;
	std::vector<Ability_FE> known_abilities_;
};