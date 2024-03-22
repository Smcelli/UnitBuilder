#pragma once
#include "Stat_FE.h"
#include <array>

const int BLOCK_SIZE = 8;
class StatBlock_Fates
{
public:
	enum Stat_Name {hp, str, mag, skl, spd, lck, def, res};
	StatBlock_Fates();
	StatBlock_Fates(const StatBlock_Fates&); 
	StatBlock_Fates(StatBlock_Fates&&) noexcept;
	~StatBlock_Fates();
	friend void swap(StatBlock_Fates&, StatBlock_Fates&);
	std::array<int, BLOCK_SIZE> get_stats();
	std::array<int, BLOCK_SIZE> get_growths();
	std::array<int, BLOCK_SIZE> get_maxs();

	StatBlock_Fates& operator=(const StatBlock_Fates&);
	StatBlock_Fates& add_block(const StatBlock_Fates&);
	StatBlock_Fates& subtract_block(const StatBlock_Fates&);
	void debug_print();
private:
	std::array <Stat_FE, BLOCK_SIZE> block_{ {
			Stat_FE("Max HP"),
			Stat_FE("Strength"),
			Stat_FE("Magic"),
			Stat_FE("Skill"),
			Stat_FE("Speed"),
			Stat_FE("Luck"),
			Stat_FE("Defense"),
			Stat_FE("Resistance"),
			} };
};

