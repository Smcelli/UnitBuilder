#include "Ability_FE.h"

bool compare_req(const Ability_Job_Fates left, const Ability_Job_Fates right)
{
	if (left.requirement < right.requirement) return	true;
	return												false;
}

bool compare_id(const Ability_FE left, const Ability_FE right)
{
	if (left.id < right.id) return	true;
	return							false;
}

Ability_FE::Ability_FE(const Ability_FE& source)
	: name(source.name),
	id(source.id){}

void swap(Ability_FE& left, Ability_FE& right)
{
	using std::swap;
	swap(left.id, right.id);
	swap(left.name, right.name);
}

Ability_FE& Ability_FE::operator=(Ability_FE source)
{
	swap(*this, source);
	return *this;
}

Ability_FE::Ability_FE(Ability_FE&& source) noexcept
	: Ability_FE{}
{
	swap(*this, source);
}

void Ability_FE::debug_console_print() const
{
	std::cout << " " << name << ", id: " << id;
}

Ability_Job_Fates::Ability_Job_Fates(const Ability_Job_Fates& source)
	:requirement(source.requirement),
	Ability_FE(source){}

void swap(Ability_Job_Fates& left, Ability_Job_Fates& right)
{
	using std::swap;
	swap(left.requirement, right.requirement);
	swap(static_cast<Ability_FE&>(left), static_cast<Ability_FE&>(right));
}

Ability_Job_Fates& Ability_Job_Fates::operator=(Ability_Job_Fates source)
{
	swap(*this, source);
	return *this;
}

Ability_Job_Fates::Ability_Job_Fates(Ability_Job_Fates&& source) noexcept
	: Ability_FE(std::move(source)),
	requirement(0)
	
{
	swap(*this, source);
}

void Ability_Job_Fates::debug_console_print() const
{
	using std::cout;
	Ability_FE::debug_console_print(); //this?
	cout << " requirement: " << requirement;
}


