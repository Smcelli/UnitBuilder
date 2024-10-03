#include "Unit_Active.h"

Unit_Active::Unit_Active(const StatBlock_Fates& b, 
	const Unit_Plan_Fates& p, 
	Job_Fates* j, 
	int16_t l)
	: StatBlock_Fates(b),
	plan(p),
	currect_job(j),
	level(l){}

void Unit_Active::make_average_unit()
{
	if (is_average)
		return;
	is_average = true;
	prep_average();
}

void Unit_Active::change_job(Job_Fates* job)
{
	if (currect_job) {
		subtract_block(currect_job);
	}
	currect_job = job;
	if (currect_job) {
		add_block(currect_job);
	}
	else {
		std::cout << "ERROR: changejob target id: " << job << std::endl;
	}
}

void Unit_Active::change_job(int16_t id)
{
	return change_job(common_table.get_job_ptr(id));
}

void Unit_Active::level_to_ambiguous(int16_t target)
{
	if (is_average)
		return levelup_average(target-level);
	else
		return levelup(target-level);
}

void Unit_Active::level_to(int16_t target)
{
	auto it_plan_end = plan.get_end();
	for (auto it_plan = plan.get_next(level);
		it_plan != it_plan_end;
		it_plan++) {
		if (target <= it_plan->first) {
			level_to_ambiguous(target);
			if (target == it_plan->first && it_plan->second ) {
				change_job(it_plan->second);
				break;
			}
		} else {
			level_to_ambiguous(it_plan->first);
			change_job(it_plan->second);
		}
	}
	if (level < target) {
		level_to_ambiguous(target - level);
	}
	return;
}
