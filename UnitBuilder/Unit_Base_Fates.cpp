#include "Unit_Base_Fates.h"

Unit_Base_Fates::Unit_Base_Fates(std::string name, 
	StatBlock_Fates block, 
	Bonus_list pair_bonus, 
	std::vector<int16_t> jobs, 
	int16_t id, 
	int16_t level, 
	int16_t level_offset)
	:StatBlock_Fates(block),
	name_(name),
	jobs_(jobs),
	pair_bonus(pair_bonus),
	id_(fe_fates::id_unit(id)), level_(level), level_offset_(level_offset) 
{
	if (jobs_.empty()) {
		jobs_.push_back(fe_fates::ids::debug_job);
	}
	for (auto& element : jobs_)
		element = fe_fates::id_job(element);
}

std::vector<int16_t> Unit_Base_Fates::jobs() const
{
	auto result = jobs_;
	auto it = result.begin();
	if (*it % 4)
		*it = *it - *it % 4;
	return result;
}

void Unit_Base_Fates::debug_console_print() const
{
	std::cout << std::endl << " " << id_ << " : " << name_;
	StatBlock_Fates::debug_console_print();
}

Unit_Base_Fates& Unit_Base_Fates::operator=(Unit_Base_Fates temp)
{
	swap(*this, temp);
	return *this;
}

void swap( Unit_Base_Fates& left,  Unit_Base_Fates& right)
{
	using std::swap;
	swap(left.name_, right.name_);
	swap(left.jobs_, right.jobs_);
	swap(left.pair_bonus, right.pair_bonus);
	swap(left.id_, right.id_);
	swap(left.level_, right.level_);
	swap(left.level_offset_,	right.level_offset_);
	swap(static_cast<StatBlock_Fates&>(left), static_cast<StatBlock_Fates&>(right));
}
