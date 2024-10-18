#include "Unit_Plan_Fates.h"

Unit_Plan_Fates::Unit_Plan_Fates(int16_t starting_lvl, int16_t starting_job)
{
	plan_.emplace(starting_lvl-1, starting_job);
	promotion_ = plan_.end();
}

Unit_Plan_Fates::Unit_Plan_Fates(const Unit_Plan_Fates& source)
	:plan_ (source.plan_)
{
	if (source.promotion_ == source.plan_.end())
		promotion_ = plan_.end();
	else
		promotion_ = plan_.find(source.promotion_->first);
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
	else if ( in_promotion_range(lvl) && has_promotion() && lvl > promotion_->first)
		return false;
	else if ( !plan_.empty() && lvl <= plan_.begin()->first)
		return false;
	return true;
}

bool Unit_Plan_Fates::is_promotion(int16_t level, int16_t job)
{
	if (!in_promotion_range(level) || !fe_fates::id_job_is_promo(job))
		return false;
	return true;
}

void Unit_Plan_Fates::remove(int16_t lvl)
{
	auto it = plan_.find(lvl);
	if (it != plan_.end())
		remove(it);
}

void Unit_Plan_Fates::remove(std::map<int16_t, int16_t>::iterator it)
{
	if (it == plan_.end())
		return;
	if (has_promotion() && it == promotion_)
		promotion_ = plan_.end();
	plan_.erase(it);
}

void Unit_Plan_Fates::remove_invalid_promoted()
{
	if (!has_promotion())
		return;
	auto it_lower = promotion_;
	it_lower++;
	if (it_lower == plan_.end() || it_lower->first > 20)
		return;
	auto it_upper = plan_.upper_bound(20);
	plan_.erase(it_lower, it_upper);
}

void Unit_Plan_Fates::force_promotion()
{
	if (has_promotion() || plan_.empty())
		return;

	auto it = plan_.upper_bound(20);
	it--;
	int16_t id = it->second + 1;
	promotion_ = plan_.emplace(20, id).first;
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::emplace(int16_t lvl, int16_t job)
{
	if (job == NULL)
		plan_.end();
	else if (!is_proper_lvl(lvl))
		plan_.end();
	else if (lvl < 10 && fe_fates::id_job_is_promo(job))
		plan_.end();
	else if (lvl > 20 && !fe_fates::id_job_is_promo(job))
		plan_.end();

	remove(plan_.find(lvl));

	if (in_promotion_range(lvl) && fe_fates::id_job_is_promo(job)) {
		if (has_promotion())
			plan_.erase(promotion_);
		auto result = plan_.emplace(lvl, job);
		if (result.second) {
			promotion_ = result.first;
			remove_invalid_promoted();
			return promotion_;
		}
		else
			return plan_.end();
	}
	else {
		return plan_.emplace(lvl, job).first;
	}
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::get_first()
{
	return plan_.begin();
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::get_prev(int16_t lvl)
{
	return plan_.lower_bound(lvl);
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::get_next(int16_t lvl)
{
	return plan_.upper_bound(lvl);
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::get_end()
{
	return plan_.end();
}

std::map<int16_t, int16_t>::iterator Unit_Plan_Fates::get_promotion() const
{
	return promotion_;
}

bool Unit_Plan_Fates::empty()
{
	return plan_.empty();
}

bool Unit_Plan_Fates::has_promotion()
{
	return (promotion_ != plan_.end()) ? true : false;
}

bool Unit_Plan_Fates::in_promotion_range(int16_t level)
{
	return (level > 9 && level < 21) ? true : false;
}

void Unit_Plan_Fates::build_learned_abilities()
{
	auto it_plan = plan_.begin();
	if (it_plan == plan_.end())
		return;

	std::unordered_set<int16_t> learned = {};
	int16_t level = 0;
	for(;;)
	{
		auto possible_to_learn = common_table.get_job_ptr(fe_fates::id_job_base(it_plan->second))->ability_list();
		if (fe_fates::id_job_is_promo(it_plan->second)) {
			auto temp = common_table.get_job_ptr(it_plan->second)->ability_list();
			possible_to_learn.insert(possible_to_learn.end(), temp.begin(), temp.end());
		}
		for(auto temp_it = possible_to_learn.begin(); temp_it != possible_to_learn.end();)
		{
			if (learned.count(temp_it->id))
				temp_it = possible_to_learn.erase(temp_it);
			else
				temp_it++;
		}

		it_plan++;
		if (it_plan == plan_.end())
			break;

		auto skill = possible_to_learn.begin();
		if (skill == possible_to_learn.end())
			continue;

		do {
			level++;
			if (level >= skill->requirement) {
				learned.emplace(skill->id);
			}

		}while (level < it_plan->first)
		
		
		



	}


	//////RESUME HERE
}




void swap(Unit_Plan_Fates& left, Unit_Plan_Fates& right)
{
	using std::swap;
	swap(left.plan_, right.plan_);
	swap(left.promotion_, right.promotion_);
}
