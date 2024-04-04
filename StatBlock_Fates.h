#pragma once
#include "Stat_FE.h"
#include "fe_fates_namespace.h"
#include <array>

using namespace fe_fates;
class StatBlock_Fates
{
private:
	std::array <Stat_FE, fe_fates::BLOCK_SIZE> block_{ {
			Stat_FE{fates_names.at(Stat_places::hp + STAT_ID)},
			Stat_FE{fates_names.at(Stat_places::str + STAT_ID)},
			Stat_FE{fates_names.at(Stat_places::mag + STAT_ID)},
			Stat_FE{fates_names.at(Stat_places::skl + STAT_ID)},
			Stat_FE{fates_names.at(Stat_places::spd + STAT_ID)},
			Stat_FE{fates_names.at(Stat_places::lck + STAT_ID)},
			Stat_FE{fates_names.at(Stat_places::def + STAT_ID)},
			Stat_FE{fates_names.at(Stat_places::res + STAT_ID)},
			} };
	
public:
	virtual ~StatBlock_Fates() = default;
	StatBlock_Fates() = default;
	StatBlock_Fates(const StatBlock_Fates&);
	friend void swap(StatBlock_Fates&, StatBlock_Fates&);
	StatBlock_Fates& operator=(StatBlock_Fates);
	StatBlock_Fates(StatBlock_Fates&&) noexcept;
	
	StatBlock_Fates(
		std::array<int16_t, fe_fates::BLOCK_SIZE>, 
		std::array<int16_t, fe_fates::BLOCK_SIZE>, 
		std::array<int16_t, fe_fates::BLOCK_SIZE>);

	StatBlock_Fates(
		std::array<int, fe_fates::BLOCK_SIZE>,
		std::array<int, fe_fates::BLOCK_SIZE>,
		std::array<int, fe_fates::BLOCK_SIZE>);

	std::array<int16_t, fe_fates::BLOCK_SIZE> get_stats();
	std::array<int16_t, fe_fates::BLOCK_SIZE> get_growths();
	std::array<int16_t, fe_fates::BLOCK_SIZE> get_maxs();
	StatBlock_Fates& add_block(const StatBlock_Fates&);
	StatBlock_Fates& subtract_block(const StatBlock_Fates&);
	void debug_console_print() const;

};

