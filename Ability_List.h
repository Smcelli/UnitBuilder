#pragma once
#include "Stat_FE.h"
#include <map>

class Ability_List
{
public:
	Ability_List();
	Ability_List(const Ability_List&);
	Ability_List(Ability_List&&) noexcept;
	~Ability_List();
	Ability_List& operator=(const Ability_List&);
	friend void swap(Ability_List&, Ability_List&);
	Ability_FE* add_personal_skill(Ability_FE);
private:
	std::map<unsigned short int, Ability_FE> personal_skills;
	std::map<unsigned short int, Ability_FE> job_skills;
};

