#include "Ability_List_FE.h"

Ability_List_Fates::Ability_List_Fates(const Ability_List_Fates& source)
{
    abilities = source.abilities;
}

void swap(Ability_List_Fates& left_side, Ability_List_Fates& right_side)
{
    swap(left_side.abilities, right_side.abilities);
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
/*
void Ability_List_Fates::add_skill(Ability_Job_Fates ability)
{
    abilities.try_emplace(ability.id, ability);
}
*/
void Ability_List_Fates::add_skill(Ability_FE ability)
{
    abilities.try_emplace(ability.id, ability);
}

void Ability_List_Fates::debug_console_print() const
{
    for (const auto& [key, val] : abilities) {
        val.debug_console_print();
        std::cout << std::endl;
    }
}


