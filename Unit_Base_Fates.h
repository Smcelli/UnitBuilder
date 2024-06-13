#pragma once
#include "StatBlock_Fates.h"
#include "Basic_blocks_FE.h"
#include "Bonus_statblock.h"
#include "Ability_FE.h"

#include <algorithm>
#include <vector>

class Unit_Base_Fates : public StatBlock_Fates

{
protected:
	std::string name;
	Bonus_statblock pair_bonus;
	uint16_t id, level, level_offset, promotion;
	uint16_t job_prim, job_sec, job_tert;

public:
	std::vector<uint16_t> get_jobs() const;
	uint16_t get_primary_job() const;
	uint16_t get_promotion() const;
	uint16_t get_lvl() const;
	std::string get_name() const;
	uint16_t get_id() const;


	~Unit_Base_Fates() = default;
	Unit_Base_Fates() = default;
	Unit_Base_Fates(const Unit_Base_Fates&);
	friend void swap( Unit_Base_Fates&,  Unit_Base_Fates&);
	Unit_Base_Fates& operator= (Unit_Base_Fates);
	Unit_Base_Fates(Unit_Base_Fates&&) noexcept;
	void debug_console_print() const;
	
	Unit_Base_Fates(std::string name,
		StatBlock_Fates sb,
		Bonus_statblock bb,
		uint16_t id, uint16_t job_p, uint16_t job_s,
		int l, int l_off, int promo, uint16_t job_t=0);
};