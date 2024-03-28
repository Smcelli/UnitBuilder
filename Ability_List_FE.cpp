#include "Ability_List_FE.h"

Ability_List_Fates::~Ability_List_Fates()
{
    job_skills.clear();
}

Ability_List_Fates::Ability_List_Fates(const Ability_List_Fates& other)
{
    job_skills = other.job_skills;
}

void swap(Ability_List_Fates& left_side, Ability_List_Fates& right_side)
{
    swap(left_side.job_skills, right_side.job_skills);
}

Ability_List_Fates& Ability_List_Fates::operator=(Ability_List_Fates source)
{
    swap(*this, source);
    return *this;
}

Ability_List_Fates::Ability_List_Fates(Ability_List_Fates&& source) noexcept
    : Ability_List_Fates()
{
    swap(*this, source);
}

void Ability_List_Fates::add_skill(Ability_Job_Fates ability)
{
    job_skills.try_emplace(ability.id, new Ability_Job_Fates(ability));
}

void Ability_List_Fates::debug_console_print()
{
    for (auto const& [key, val] : job_skills) {
        val->debug_console_print();
    }
}


