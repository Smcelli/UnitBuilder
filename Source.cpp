#include "fe_fates_namespace.h"
#include "Ability_List_FE.h"
#include "Job_List_Fates.h"
#include <stdlib.h>
#include <time.h>

void populate_fates_abilities(Ability_List_Fates*);
void populate_fates_jobs(Job_List_Fates*);

int main() {
	srand(time(NULL));
	Ability_List_Fates abilities;
	Job_List_Fates jobs;
	populate_fates_abilities(&abilities);
	populate_fates_jobs(&jobs);
	abilities.debug_console_print();
	jobs.debug_console_print();
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
		(JOB_SKILL + cavalier*2) , 
		(unpromo_first) });
	list->add_skill(Ability_Job_Fates{ 
		std::string("shelter"),
		(JOB_SKILL + (cavalier*2) +1) ,
		(unpromo_second) });
	list->add_skill(Ability_Job_Fates{
		std::string("defender"),
		(JOB_SKILL + paladin*2) ,
		(promo_first)});
	list->add_skill(Ability_Job_Fates{
		std::string("aegis"),
		(JOB_SKILL + (paladin*2) +1) ,
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
		debug_job,
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
		cavalier,
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
		paladin,
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
			std::array<int, BLOCK_SIZE> {0, 200,0,0,0,0,400,0},
			1
		},
		great_knight_cav,
		1,
		7
	});
}
/*StatBlock_Fates(
		std::array<int, fe_fates::BLOCK_SIZE>, 8
		std::array<int, fe_fates::BLOCK_SIZE>,
		std::array<int, fe_fates::BLOCK_SIZE>);
*/

/*Job_Fates(
		StatBlock_Fates,
		fe_fates::Job_name id,
		int promotion, 
		int move,
		std::vector<std::pair<fe_fates::Stat_name, int>> pair
	);*/