#include "Unit_Plan_Fates.h"

Unit_Plan_Fates::Unit_Plan_Fates(uint16_t starting_lvl, uint16_t starting_job)
{
	emplace(starting_lvl, starting_job);
}

Unit_Plan_Fates::Unit_Plan_Fates(const Unit_Plan_Fates& source)
	:plan (source.plan){}

Unit_Plan_Fates& Unit_Plan_Fates::operator=(Unit_Plan_Fates temp)
{
	swap(*this, temp);
	return *this;
}

Unit_Plan_Fates::Unit_Plan_Fates(Unit_Plan_Fates&& source) noexcept
	:Unit_Plan_Fates()
{
	swap(*this, source);
}

bool Unit_Plan_Fates::is_proper_lvl(uint16_t lvl)
{
	if (lvl == 0)
		return false;
	else if (lvl > 60)
		return false;
	return true;
}

bool Unit_Plan_Fates::is_proper_action(uint16_t action)
{
	if (action < 3)
		return true;
	else if (action > fe_fates::ID_JOB && action < fe_fates::ID_SKILL_JOB)
		return true;
	return false;

}

void Unit_Plan_Fates::emplace(uint16_t lvl, uint16_t action)
{
	if (!is_proper_action(action) || !is_proper_lvl(lvl)) {
		std::cout << "INVALID INPUT TO UNIT PLAN FATES [ " << lvl << " : " << action << "]" << std::endl;
		return;
	}
	plan[lvl] = action;
}

void Unit_Plan_Fates::remove(uint16_t lvl)
{
	plan.erase(lvl);
}

void Unit_Plan_Fates::remove(map<uint16_t, uint16_t>::iterator task)
{
	plan.erase(task);
}

map<uint16_t, uint16_t>::iterator Unit_Plan_Fates::get_first()
{
	return plan.begin();
}

map<uint16_t, uint16_t>::iterator Unit_Plan_Fates::get_next(uint16_t lvl)
{
	map<uint16_t, uint16_t>::iterator it = plan.begin();
	while (it != plan.end()) {
		if (it->first > lvl)
			return it;
		it++;
	}
	return plan.begin();
}

void swap(Unit_Plan_Fates& left, Unit_Plan_Fates& right)
{
	using std::swap;
	swap(left.plan, right.plan);
}
