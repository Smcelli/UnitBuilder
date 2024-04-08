#include "fe_fates_namespace.h"
#include "Ability_List_FE.h"
#include "Job_List_Fates.h"
#include "Unit_Base_Fates.h"
#include "Basic_blocks_FE.h"
#include <stdlib.h>
#include <time.h>

void populate_fates_abilities(Ability_List_Fates*);
void populate_fates_jobs(Job_List_Fates*);
void populate_fates_units(std::unordered_map<uint16_t, Unit_Base_Fates>* units);
void populate_supports_h(Support_Table_FE* supports);

int main() {
	srand(time(NULL));
	Ability_List_Fates abilities;
	Job_List_Fates jobs;
	Support_Table_FE supports;
	std::unordered_map<uint16_t, Unit_Base_Fates> units;
	populate_fates_abilities(&abilities);
	populate_fates_jobs(&jobs);
	populate_fates_units(&units);
	populate_supports_h(&supports);
	abilities.debug_console_print();
	jobs.debug_console_print();
	for (const auto& [key, val] : units) {
		val.debug_console_print();
		std::cout << std::endl;
	}
	supports.debug_console_print();
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
		(ID_SKILL_JOB + cavalier*2) , 
		(unpromo_first) });
	list->add_skill(Ability_Job_Fates{ 
		std::string("shelter"),
		(ID_SKILL_JOB + (cavalier*2) +1) ,
		(unpromo_second) });
	list->add_skill(Ability_Job_Fates{
		std::string("defender"),
		(ID_SKILL_JOB + paladin*2) ,
		(promo_first)});
	list->add_skill(Ability_Job_Fates{
		std::string("aegis"),
		(ID_SKILL_JOB + (paladin*2) +1) ,
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
		debug_job + ID_JOB_UNIQUE,
		0,
		0
	});
	list->add_job(Job_Fates{
		std::string("cavalier"),
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {17,6,0,5,5,3,5,3},
			std::array<int, BLOCK_SIZE> {10,15,0,10,10,15,10,5},
			std::array<int, BLOCK_SIZE> {40, 22,15,21,20,24,22,21}
		},
		Bonus_statblock{
			std::array<int, BLOCK_SIZE> {0, 2,0,0,0,0,2,2},
			0
		},
		cavalier + ID_JOB_COMMON,
		0,
		7
	});
	list->add_job(Job_Fates{
		std::string("paladin"),
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {19,8,1,7,7,4,7,6},
			std::array<int, BLOCK_SIZE> {10,15,0,10,10,15,10,10},
			std::array<int, BLOCK_SIZE> {60, 31,26,30,30,32,32,32}
		},
		Bonus_statblock{
			std::array<int, BLOCK_SIZE> {0, 2,0,0,0,0,2,2},
			1
		},
		paladin + ID_JOB_COMMON,
		1,
		8
	});
	list->add_job(Job_Fates{
		std::string("great knight"),
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {21,10,0,6,6,3,10,2},
			std::array<int, BLOCK_SIZE> {10,15,0,10,10,15,10,10},
			std::array<int, BLOCK_SIZE> {65, 35,25,29,27,28,37,28}
		},
		Bonus_statblock{
			std::array<int, BLOCK_SIZE> {0, 2,0,0,0,0,4,0}, 1 },
		great_knight_cav + ID_JOB_COMMON,
		1,
		7
	});
}

void populate_fates_units(std::unordered_map<uint16_t, Unit_Base_Fates>* units) {
	units->try_emplace(ID_UNIT + silas_h, Unit_Base_Fates{
		"Silas",
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {22, 11, 0, 9, 8, 7, 10, 5},
			std::array<int, BLOCK_SIZE> {40, 45, 5, 50, 40, 40, 40, 25},
			std::array<int, BLOCK_SIZE> {0, 1, 0, 2, 0, -1, 0, -1 }
		},
		Bonus_statblock{std::array <int, BLOCK_SIZE> 
			{0, 200, 0, 100, 100, 0, 100, 0}, 0},
		ID_UNIT + silas_h, ID_JOB_COMMON + cavalier, ID_JOB_COMMON + mercenary,
		6, 0, 0,
		std::vector<uint16_t> {cavalier*2}
		});
	units->try_emplace(ID_UNIT + ryoma, Unit_Base_Fates{
		"Ryoma",
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {36, 20, 2, 18, 24, 20, 16, 13},
			std::array<int, BLOCK_SIZE> {50, 45, 0, 50, 45, 40, 35, 25},
			std::array<int, BLOCK_SIZE> {0, 1, 0, 2, 1, 1, -2, -2 }
		},
		Bonus_statblock{std::array <int, BLOCK_SIZE> {0, 100, 0, 100, 300, 0, 0, 0}, 0},
		ID_UNIT + ryoma, ID_JOB_COMMON + sword_master, ID_JOB_COMMON + sky_knight,
		24, 0, 1,
		std::vector<uint16_t> {samurai*2, (samurai*2)+1}
		});
}

void populate_supports_h(Support_Table_FE* table) {

	unordered_set<uint16_t> wives_common_h{ hinoka, sakura, felicia_1, felicia_2, azura, mozu, rinkah, orochi, kagero, hana, setsuna, oboro };
	table->emplace(silas_h, 1, wives_common_h);
	table->emplace(silas_h, 2,
		unordered_set<uint16_t>{ryoma, jacob_1, jacob_2, kaze_h});

	wives_common_h.erase(hinoka);
	wives_common_h.erase(sakura);
	table->emplace(ryoma, 1, wives_common_h);
	table->emplace(ryoma, 2,
		unordered_set<uint16_t>{saizo, silas_h, takumi});

}