#include "Ability_List.h"

Ability_List::Ability_List()
{
}

Ability_List::Ability_List(const Ability_List& other)
{
    personal_skills = other.personal_skills;
    job_skills = other.job_skills;
}

Ability_List::Ability_List(Ability_List&& other) noexcept
    : Ability_List(other)
{
    swap(*this, other);
}

Ability_List& Ability_List::operator=(const Ability_List& other)
{
    Ability_List temp(other);
    swap(*this, temp);
    return *this;
}

Ability_List::~Ability_List()
{
    personal_skills.clear();
    job_skills.clear();
}

Ability_FE* Ability_List::add_personal_skill(Ability_FE temp)
{
    
}

void swap(Ability_List& left_side, Ability_List& right_side)
{
    swap(left_side.personal_skills, right_side.personal_skills);
    swap(left_side.job_skills, right_side.job_skills);

}
