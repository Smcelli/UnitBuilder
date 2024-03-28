#include "Job_Fates.h"

Job_Fates::Job_Fates(const Job_Fates& source)
    : StatBlock_Fates(source),
    promotion(source.promotion),
    move(source.move),
    weapon_ranks(source.weapon_ranks),
    ability_list(source.ability_list) {}
    

void swap(Job_Fates& left_side, Job_Fates& right_side)
{
    using std::swap;
    swap(left_side.promotion, right_side.promotion);
    swap(left_side.move, right_side.move);
    swap(left_side.weapon_ranks, right_side.weapon_ranks);
    swap(left_side.ability_list, right_side.ability_list);
    swap(static_cast<StatBlock_Fates&>(left_side), static_cast<StatBlock_Fates&>(right_side));
}

Job_Fates& Job_Fates::operator=(Job_Fates source)
{
    swap(*this, source);
    return *this;
}

Job_Fates::Job_Fates(Job_Fates&& source) noexcept
    : StatBlock_Fates{ std::move(source) }
{
    swap(*this, source);
}
