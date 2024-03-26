#pragma once
#include "StatBlock_Fates.h"
#include <vector>
#include <string>

class Job_Fates : public StatBlock_Fates
{
public:
	Job_Fates();
	Job_Fates(const Job_Fates&);
	Job_Fates(Job_Fates&&) noexcept;
	friend void	swap(Job_Fates&, Job_Fates&);
	Job_Fates& operator=(const Job_Fates&);
	unsigned short int isPromotedJob()( return promotion_; );
	unsigned short int move() { return move_; };
//private:
	unsigned short int promotion_, move_;
	std::vector<Weapon_Rank_FE> weapon_ranks_;
	std::vector<Ability_FE> ability_list_;
};

