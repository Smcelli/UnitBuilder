#pragma once
#include <fe_fates_namespace.h>
#include <vector>
#include <Bonus_list.h>

class Bonus_statblock
{
	std::vector<Bonus_list> bonuses;
public:

	~Bonus_statblock() = default;
	Bonus_statblock() = default;
	Bonus_statblock(const Bonus_statblock&);
	friend void swap(Bonus_statblock&, Bonus_statblock&);
	Bonus_statblock& operator=(Bonus_statblock);
	Bonus_statblock(Bonus_statblock&&) noexcept;
};

