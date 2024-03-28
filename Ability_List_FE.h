#pragma once
#include "Ability_FE.h"
#include <map>
#include <algorithm>
#include <memory>

class Ability_List_Fates
{
private:
	std::map<int,std::unique_ptr<Ability_FE>> job_skills;

public:
	~Ability_List_Fates();
	Ability_List_Fates() = default;
	Ability_List_Fates(const Ability_List_Fates&);
	friend void swap(Ability_List_Fates&, Ability_List_Fates&);
	Ability_List_Fates& operator=(Ability_List_Fates);
	Ability_List_Fates(Ability_List_Fates&&) noexcept;

	void add_skill(Ability_FE);
	void populate_Fates();
	void debug_console_print();

};

