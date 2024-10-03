#include "Unit_Plan_Fates.h"

Unit_Plan_Fates::Unit_Plan_Fates(int16_t starting_lvl, int16_t starting_job)
{
	plan.emplace(starting_lvl, starting_job);
	promotion = plan.end();
}

Unit_Plan_Fates::Unit_Plan_Fates(const Unit_Plan_Fates& source)
	:plan (source.plan)
{
	if (source.promotion == source.plan.end())
		promotion = plan.end();
	else
		promotion = plan.find(source.promotion->first);
}

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

bool Unit_Plan_Fates::is_proper_lvl(int16_t lvl)
{
	if (!fe_fates::in_level_range(lvl))
		return false;
	else if (has_promotion() && in_promotion_range(lvl) && lvl > promotion->first)
		return false;
	else if ( !plan.empty() && lvl <= plan.begin()->first)
		return false;
	return true;
}

bool Unit_Plan_Fates::is_promotion(int16_t level, int16_t job)
{
	if (!in_promotion_range(level))
		return false;
	else if (fe_fates::id_job_is_promo(job))
		return false;
	return true;
}



void Unit_Plan_Fates::remove(int16_t lvl)
{
	auto it = plan.find(lvl);
	if (it != plan.end())
		remove(it);
}

void Unit_Plan_Fates::remove(std::map<int16_t, int16_t>::iterator it)
{
	if (it == plan.end())
		return;
	if (has_promotion() && it == promotion)
		promotion = plan.end();
	plan.erase(it);
}

void Unit_Plan_Fates::remove_invalid_promoted()
{
	if (!has_promotion())
		return;
	auto it_lower = promotion;
	it_lower++;
	if (it_lower == plan.end() || it_lower->first > 20)
		return;
	auto it_upper = plan.upper_bound(20);
	plan.erase(it_lower, it_upper);
}

void Unit_Plan_Fates::force_promotion()
{
	if (has_promotion() || plan.empty())
		return;

	auto it = plan.upper_bound(20);
	it--;
	int16_t id = it->second + 1;
	promotion = plan.emplace(20, id).first;
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::emplace(int16_t lvl, int16_t job)
{
	if (job == NULL)
		plan.end();
	else if (!is_proper_lvl(lvl))
		plan.end();
	else if (lvl < 10 && fe_fates::id_job_is_promo(job))
		plan.end();
	else if (lvl > 20 && !fe_fates::id_job_is_promo(job))
		plan.end();

	remove(plan.find(lvl));

	if (in_promotion_range(lvl) && fe_fates::id_job_is_promo(job)) {
		if (has_promotion())
			plan.erase(promotion);
		auto result = plan.emplace(lvl, job);
		if (result.second) {
			promotion = result.first;
			remove_invalid_promoted();
			return promotion;
		}
		else
			return plan.end();
	}
	else {
		return plan.emplace(lvl, job).first;
	}
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::get_first()
{
	return plan.begin();
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::get_prev(int16_t lvl)
{
	return plan.lower_bound(lvl);
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::get_next(int16_t lvl)
{
	return plan.upper_bound(lvl);
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::get_end()
{
	return plan.end();
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::get_promotion() const
{
	return promotion;
}

bool Unit_Plan_Fates::empty()
{
	return plan.empty();
}

bool Unit_Plan_Fates::has_promotion()
{
	return (promotion != plan.end()) ? true : false;
}

bool Unit_Plan_Fates::in_promotion_range(int16_t level)
{
	return (level > 9 && level < 21) ? true : false;
}


void swap(Unit_Plan_Fates& left, Unit_Plan_Fates& right)
{
	using std::swap;
	swap(left.plan, right.plan);
	swap(left.promotion, right.promotion);
}
