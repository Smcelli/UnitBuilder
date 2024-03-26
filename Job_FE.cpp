#include "Job_FE.h"

Job_Fates::Job_Fates()
{
    promotion_ = 0;
    move_ = 4;
}

Job_Fates::Job_Fates(const Job_Fates& other)
    : StatBlock_Fates(other)
{
    promotion_ = other.promotion_;
    move_ = other.move_;
    weapon_ranks_ = other.weapon_ranks_;
    ability_list_ = other.ability_list_;
}

Job_Fates::Job_Fates(Job_Fates&& other) noexcept
    : Job_Fates()
{
    swap(*this, other);
}

Job_Fates& Job_Fates::operator=(const Job_Fates& other)
{
    Job_Fates temp(other);
    swap(*this, temp);
    return *this;
}

void swap(Job_Fates& left_side, Job_Fates& right_side)
{
    using std::swap;
    swap(left_side.promotion_, right_side.promotion_);
    swap(left_side.move_, right_side.move_);
    swap(left_side.weapon_ranks_, right_side.weapon_ranks_);
    swap(left_side.ability_list_, right_side.ability_list_);
}
