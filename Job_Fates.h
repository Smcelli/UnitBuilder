#pragma once
#include "StatBlock_Fates.h"
#include "Basic_blocks_FE.h"
#include "Ability_FE.h"
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

	const uint16_t is_promoted_job() const { return promotion; };
//private:
	
};

