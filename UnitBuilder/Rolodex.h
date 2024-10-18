#pragma once
#include <fe_fates_namespace.h>
#include <Basic_blocks_FE.h>
#include <Unit_Base_Fates.h>
#include <Job_Fates.h>
#include <unordered_map>



class Rolodex
{

public:
	Support_Table_FE supports;
	std::unordered_map<int16_t, Unit_Base_Fates> units;
	std::unordered_map<int16_t, Job_Fates> jobs;
	std::unordered_set<int16_t> girls_club{
		fe_fates::ids::avatar_f,
		fe_fates::ids::azura,
		fe_fates::ids::felicia_1,
		fe_fates::ids::felicia_2,
		fe_fates::ids::mozu,
		fe_fates::ids::rinkah,
		fe_fates::ids::sakura,
		fe_fates::ids::hana,
		fe_fates::ids::orochi,
		fe_fates::ids::hinoka,
		fe_fates::ids::setsuna,
		fe_fates::ids::oboro,
		fe_fates::ids::kagero,
		fe_fates::ids::reina,
		fe_fates::ids::scarlet,
		fe_fates::ids::elise,
		fe_fates::ids::effie,
		fe_fates::ids::nyx,
		fe_fates::ids::camilla,
		fe_fates::ids::selena,
		fe_fates::ids::beruka,
		fe_fates::ids::peri,
		fe_fates::ids::charlotte,
		fe_fates::ids::flora,
		fe_fates::ids::kana_f,
		fe_fates::ids::sophie,
		fe_fates::ids::midori,
		fe_fates::ids::selkie,
		fe_fates::ids::mitama,
		fe_fates::ids::caeldori,
		fe_fates::ids::rhajat,
		fe_fates::ids::forrest,
		fe_fates::ids::velouria,
		fe_fates::ids::ophelia,
		fe_fates::ids::soleil,
		fe_fates::ids::nina,
	};

	Rolodex();
	Unit_Base_Fates get_unit(int16_t) const;
	bool unit_is_female(int16_t unit_id) const { return girls_club.count(unit_id); };

	Job_Fates* get_job_ptr(int16_t);
	std::vector<std::pair<int16_t, int16_t>> get_jobs_abilities(int16_t job_id) const;


	

	void add_ability(Ability_Job_Fates, int16_t job_id, int16_t job_id_dup = 0, int16_t job_id_third = 0);
	void add_unit(Unit_Base_Fates, bool);
	void add_job(Job_Fates, int16_t, int16_t);
	void add_job(int16_t, Job_Fates);
	void populate_fates_abilities();
	void populate_fates_jobs();
	void populate_fates_units();
	void populate_supports_h();
	void serenes_forest(std::unordered_map<int16_t, Unit_Base_Fates>::iterator);
	void debug_console_print();
};

extern Rolodex common_table;