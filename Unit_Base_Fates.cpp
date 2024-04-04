#include "Unit_Base_Fates.h"

Unit_Base_Fates::Unit_Base_Fates(const Unit_Base_Fates& source)
	: StatBlock_Fates(	source),
	name(				source.name),
	pair_bonus(			source.pair_bonus),
	ability_personal(	source.ability_personal),
	id(					source.id),
	level(				source.level),
	level_offset(		source.level_offset),
	promotion(			source.promotion),
	job_prim(			source.job_prim),
	job_sec(			source.job_sec),
	ability_learned(	source.ability_learned),
	supports_friend(	source.supports_friend),
	supports_marry(		source.supports_marry){}

Unit_Base_Fates Unit_Base_Fates::operator=(Unit_Base_Fates temp)
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
	cout << endl << "personal skill "; 
	ability_personal.debug_console_print();
	cout << "  level: " << level
		<< "  offset: " << level_offset
		<< "  promotion: " << promotion
		<< "  job id: " << job_prim
		<< "  off job id: " << job_sec << endl;
	cout << " learned abilities [ ";
	for (const auto& i : ability_learned)
		cout << i << ", ";
	cout << "]" << endl
		<< " friends: [ ";
	for (const auto& i : supports_friend)
		cout << i << ", ";
	cout << "]" << endl
		<< " spouses: [ ";
	for (const auto& i : supports_marry)
		cout << i << ", ";
	cout << "]" << endl;
}

Unit_Base_Fates::Unit_Base_Fates(std::string n, 
	StatBlock_Fates sb, 
	Bonus_statblock bb, 
	Ability_FE ap, 
	uint16_t id, uint16_t job_p, uint16_t job_s,
	int l, int l_off, int promo,
	std::vector<uint16_t> sf, 
	std::vector<uint16_t> sm, 
	std::vector<uint16_t> al)
	: StatBlock_Fates (sb),
	name(n),
	pair_bonus(bb),
	ability_personal(ap),
	id(id),
	level(l),
	level_offset(l_off),
	promotion(promo),
	job_prim(job_p),
	job_sec(job_s),
	supports_friend(sf),
	supports_marry(sm),
	ability_learned(al)
{
	if(!supports_friend.empty() && supports_friend[0] < UNIT_ID)
		std::for_each(supports_friend.begin(), supports_friend.end(), 
			[](uint16_t& i) {i += UNIT_ID; });
	if (!supports_marry.empty() && supports_marry[0] < UNIT_ID)
		std::for_each(supports_marry.begin(), supports_marry.end(),
			[](uint16_t& i) {i += UNIT_ID; });
	if (!ability_learned.empty() && ability_learned[0] < JOB_SKILL_ID)
		std::for_each(ability_learned.begin(), ability_learned.end(),
			[](uint16_t& i) {i += JOB_SKILL_ID; });
}

void swap( Unit_Base_Fates& left,  Unit_Base_Fates& right)
{
	using std::swap;
	swap(static_cast<StatBlock_Fates&>(left), static_cast<StatBlock_Fates&>(right));
	swap(left.name,				right.name);
	swap(left.pair_bonus,		right.pair_bonus);
	swap(left.ability_personal, right.ability_personal);
	swap(left.id,				right.id);
	swap(left.level,			right.level);
	swap(left.level_offset,		right.level_offset);
	swap(left.promotion,		right.promotion);
	swap(left.job_prim,			right.job_prim);
	swap(left.job_sec,			right.job_sec);
	swap(left.ability_learned,	right.ability_learned);
	swap(left.supports_friend,	right.supports_friend);
	swap(left.supports_marry,	right.supports_marry);
}
