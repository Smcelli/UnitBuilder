#include "fe_fates_namespace.h"
#include "Ability_List_FE.h"
#include "Job_List_Fates.h"
#include "Unit_Base_Fates.h"
#include <stdlib.h>
#include <time.h>

void populate_fates_abilities(Ability_List_Fates*);
void populate_fates_jobs(Job_List_Fates*);
void populate_fates_units(std::unordered_map<uint16_t, Unit_Base_Fates>* units);

int main() {
	srand(time(NULL));
	Ability_List_Fates abilities;
	Job_List_Fates jobs;
	std::unordered_map<uint16_t, Unit_Base_Fates> units;
	populate_fates_abilities(&abilities);
	populate_fates_jobs(&jobs);
	populate_fates_units(&units);
	abilities.debug_console_print();
	jobs.debug_console_print();
	for (const auto& [key, val] : units) {
		val.debug_console_print();
		std::cout << std::endl;
	}
}

void populate_fates_abilities(Ability_List_Fates* list)
{
	using namespace fe_fates;
	list->add_skill(Ability_Job_Fates{ 
		std::string("debug"), 
		static_cast<uint16_t>(0) , 
		static_cast<uint16_t>(0) });
	list->add_skill(Ability_Job_Fates{ 
		std::string("elbow room"), 
		(JOB_SKILL_ID + cavalier*2) , 
		(unpromo_first) });
	list->add_skill(Ability_Job_Fates{ 
		std::string("shelter"),
		(JOB_SKILL_ID + (cavalier*2) +1) ,
		(unpromo_second) });
	list->add_skill(Ability_Job_Fates{
		std::string("defender"),
		(JOB_SKILL_ID + paladin*2) ,
		(promo_first)});
	list->add_skill(Ability_Job_Fates{
		std::string("aegis"),
		(JOB_SKILL_ID + (paladin*2) +1) ,
		(promo_second)});
}

void populate_fates_jobs(Job_List_Fates* list) {
	using namespace fe_fates;
	list->add_job(Job_Fates{
		std::string("debug"),
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE>{0},
			std::array<int, BLOCK_SIZE>{0},
			std::array<int, BLOCK_SIZE>{0}
		},
		Bonus_statblock{
			std::array<int, BLOCK_SIZE>{0},
			0
		},
		debug_job + UNIQUE_JOB_ID,
		0,
		0
	});
	list->add_job(Job_Fates{
		std::string("cavalier"),
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {1700,600,000,500,500,300,500,300},
			std::array<int, BLOCK_SIZE> {10,15,0,10,10,15,10,5},
			std::array<int, BLOCK_SIZE> {4000, 2200,1500,2100,2000,2400,2200,2100}
		},
		Bonus_statblock{
			std::array<int, BLOCK_SIZE> {0, 200,0,0,0,0,200,200},
			0
		},
		cavalier + COMMON_JOB_ID,
		0,
		7
	});
	list->add_job(Job_Fates{
		std::string("paladin"),
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {1900,800,100,700,700,400,700,600},
			std::array<int, BLOCK_SIZE> {10,15,0,10,10,15,10,10},
			std::array<int, BLOCK_SIZE> {6000, 3100,2600,3000,3000,3200,3200,3200}
		},
		Bonus_statblock{
			std::array<int, BLOCK_SIZE> {0, 200,0,0,0,0,200,200},
			1
		},
		paladin + COMMON_JOB_ID,
		1,
		8
	});
	list->add_job(Job_Fates{
		std::string("great knight"),
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {2100,1000,0,600,600,300,1000,200},
			std::array<int, BLOCK_SIZE> {10,15,0,10,10,15,10,10},
			std::array<int, BLOCK_SIZE> {6500, 3500,2500,2900,2700,2800,3700,2800}
		},
		Bonus_statblock{
			std::array<int, BLOCK_SIZE> {0, 200,0,0,0,0,400,0}, 1 },
		great_knight_cav + COMMON_JOB_ID,
		1,
		7
	});
}

void populate_fates_units(std::unordered_map<uint16_t, Unit_Base_Fates>* units) {
	units->try_emplace(UNIT_ID + silas_h, Unit_Base_Fates{
		"Silas",
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {2200, 1100, 0, 900, 800, 700, 1000, 500},
			std::array<int, BLOCK_SIZE> {50, 60, 5, 60, 50, 55, 50, 30},
			std::array<int, BLOCK_SIZE> {0, 100, 0, 200, 0, -100, 0, -100 }
		},
		Bonus_statblock{std::array <int, BLOCK_SIZE> {0, 200, 0, 100, 100, 0, 100, 0}, 0},
		Ability_FE {"Vow of Friendship", UNIT_SKILL_ID + silas_h},
		UNIT_ID + silas_h, COMMON_JOB_ID + cavalier, COMMON_JOB_ID + mercenary,
		6, 0, 0,
		std::vector<uint16_t> {jacob_1, jacob_2, kaze_h, ryoma, sophie},
		std::vector<uint16_t> {felicia_1, felicia_2, azura, mozu, hinoka, sakura, rinkah, orochi, kagero, hana, setsuna, oboro},
		std::vector<uint16_t> {cavalier}
		});
}

/*
std::string name,
StatBlock_Fates sb,
Bonus_statblock bb,
Ability_FE ap,
uint id, uint job_p, uint job_s,
int l, int l_off, int promo, 
std::vector<int> sf = {},
std::vector<int> sm = {},
std::vector<int> al = {}
*/