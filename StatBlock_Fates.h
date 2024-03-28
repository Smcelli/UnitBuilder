#pragma once
#include "Stat_FE.h"
#include "fe_fates_namespace.h"
#include <array>

using fe_fates::BLOCK_SIZE;
class StatBlock_Fates
{
private:
	std::array <Stat_FE, fe_fates::BLOCK_SIZE> block_{ {
			Stat_FE{"Max HP"},
			Stat_FE{"Strength"},
			Stat_FE{"Magic"},
			Stat_FE{"Skill"},
			Stat_FE{"Speed"},
			Stat_FE{"Luck"},
			Stat_FE{"Defense"},
			Stat_FE{"Resistance"},
			} };
	
public:
	virtual ~StatBlock_Fates() = default;
	StatBlock_Fates() = default;
	StatBlock_Fates(const StatBlock_Fates&);
	friend void swap(StatBlock_Fates&, StatBlock_Fates&);
	StatBlock_Fates& operator=(StatBlock_Fates);
	StatBlock_Fates(StatBlock_Fates&&) noexcept;
	
	std::array<unsigned short int, fe_fates::BLOCK_SIZE> get_stats();
	std::array<unsigned short int, fe_fates::BLOCK_SIZE> get_growths();
	std::array<unsigned short int, fe_fates::BLOCK_SIZE> get_maxs();
	StatBlock_Fates& add_block(const StatBlock_Fates&);
	StatBlock_Fates& subtract_block(const StatBlock_Fates&);
	void debug_print();

};

