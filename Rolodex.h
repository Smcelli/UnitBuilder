#pragma once
#include "fe_fates_namespace.h"
#include "Ability_List_FE.h"
#include "Job_List_Fates.h"
#include "Basic_blocks_FE.h"
#include "Unit_Base_Fates.h"

class Rolodex
{
private:
	Ability_List_Fates abilities;
	Job_List_Fates jobs;
	Support_Table_FE supports;
	std::unordered_map<uint16_t, Unit_Base_Fates> units;
public:
	Rolodex();
	Job_Fates get_job(uint16_t) const;
	Job_Fates* get_job_ptr(uint16_t);
	Unit_Base_Fates get_unit(uint16_t) const;
	void populate_fates_abilities();
	void populate_fates_jobs();
	void populate_fates_units();
	void populate_supports_h();
	void debug_console_print();
};