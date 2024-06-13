#include "Unit_Base_Fates.h"

std::vector<uint16_t> Unit_Base_Fates::get_jobs() const
{
	return std::vector<uint16_t> {job_prim, job_sec, job_tert};
}

uint16_t Unit_Base_Fates::get_primary_job() const
{
	return job_prim;
}

uint16_t Unit_Base_Fates::get_promotion() const
{
	return promotion;
}

uint16_t Unit_Base_Fates::get_lvl() const
{
	return level;
}

std::string Unit_Base_Fates::get_name() const
{
	return name;
}

uint16_t Unit_Base_Fates::get_id() const
{
	return id;
}

Unit_Base_Fates::Unit_Base_Fates(const Unit_Base_Fates& source)
	: StatBlock_Fates(	source),
	name(				source.name),
	pair_bonus(			source.pair_bonus),
	id(					source.id),
	level(				source.level),
	level_offset(		source.level_offset),
	promotion(			source.promotion),
	job_prim(			source.job_prim),
	job_sec(			source.job_sec),
	job_tert(			source.job_tert){}

Unit_Base_Fates& Unit_Base_Fates::operator=(Unit_Base_Fates temp)
{
	swap(*this, temp);
	return *this;
}

Unit_Base_Fates::Unit_Base_Fates(Unit_Base_Fates&& source) noexcept
	: Unit_Base_Fates()
{
	swap(*this, source);
}

void Unit_Base_Fates::debug_console_print() const
{
	using std::cout, std::endl;
	cout << " UNIT: " << name
		<< "   ID: " << id << endl
		<< " Stats: ";
	StatBlock_Fates::debug_console_print();
	cout << endl << "Pair Bonus: "; 
	pair_bonus.debug_console_print();
	cout << endl << "  level: " << level
		<< "  offset: " << level_offset
		<< "  promotion: " << promotion
		<< "  job id: " << job_prim
		<< "  off job id: " << job_sec << endl;
}

Unit_Base_Fates::Unit_Base_Fates(std::string n, 
	StatBlock_Fates sb, 
	Bonus_statblock bb, 
	uint16_t id, uint16_t job_p, uint16_t job_s,
	int l, int l_off, int promo, uint16_t job_t)
	: StatBlock_Fates (sb),
	name(n),
	pair_bonus(bb),
	id(id),
	level(l),
	level_offset(l_off),
	promotion(promo),
	job_prim(job_p),
	job_sec(job_s),
	job_tert(job_t){}

void swap( Unit_Base_Fates& left,  Unit_Base_Fates& right)
{
	using std::swap;
	swap(static_cast<StatBlock_Fates&>(left), static_cast<StatBlock_Fates&>(right));
	swap(left.name,				right.name);
	swap(left.pair_bonus,		right.pair_bonus);
	swap(left.id,				right.id);
	swap(left.level,			right.level);
	swap(left.level_offset,		right.level_offset);
	swap(left.promotion,		right.promotion);
	swap(left.job_prim,			right.job_prim);
	swap(left.job_sec,			right.job_sec);
	swap(left.job_tert,			right.job_tert);
}
