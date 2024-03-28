#pragma once
#include <string>
#include <iostream>

struct Weapon_Rank_FE
{
	std::string name;
	uint16_t rank, id;
	auto compare_id(const Weapon_Rank_FE left, const Weapon_Rank_FE right) {
		if (left.id < right.id) return		std::strong_ordering::less;
		if (left.id > right.id) return		std::strong_ordering::greater;
		return								std::strong_ordering::equal;
	}
};

