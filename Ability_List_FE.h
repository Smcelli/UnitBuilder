#pragma once
#include "Ability_FE.h"
#include "fe_fates_namespace.h"
#include <map>
#include <algorithm>

class Ability_List_Fates
{
private:
	std::map<uint16_t,Ability_FE*> job_skills;

public:
	~Ability_List_Fates();
	Ability_List_Fates() = default;
	Ability_List_Fates(const Ability_List_Fates&);
	friend void swap(Ability_List_Fates&, Ability_List_Fates&);
	Ability_List_Fates& operator=(Ability_List_Fates);
	Ability_List_Fates(Ability_List_Fates&&) noexcept;

	void add_skill(Ability_Job_Fates);
	void debug_console_print();

};

