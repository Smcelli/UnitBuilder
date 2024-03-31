#pragma once
#include "StatBlock_Fates.h"
#include "fe_fates_namespace.h"
#include "Bonus_statblock.h"
#include <vector>
#include <string>

class Job_Fates : public StatBlock_Fates
{
public:
	uint16_t promotion, move;
	std::vector<Weapon_Rank_FE> weapon_ranks;
	std::vector<Ability_FE> ability_list;

	~Job_Fates() = default;
	Job_Fates() = default;
	Job_Fates(const Job_Fates&);
	friend void	swap(Job_Fates&, Job_Fates&);
	Job_Fates& operator=(Job_Fates);
	Job_Fates(Job_Fates&&) noexcept;

	Job_Fates( std::string,
		StatBlock_Fates,
		Bonus_statblock,
		uint16_t id,
		int promotion, 
		int move
	);
	uint16_t is_promoted_job() const { return promotion; };
	void debug_console_print() const;
	
//private:
	
};

