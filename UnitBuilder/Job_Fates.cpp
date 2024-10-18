#include <Job_Fates.h>


void swap(Job_Fates& left_side, Job_Fates& right_side)
{
    using std::swap;
    swap(left_side.name_, right_side.name_);
    swap(left_side.id_, right_side.id_);
    swap(left_side.move_, right_side.move_);
    swap(left_side.ability_list_, right_side.ability_list_);
    swap(left_side.pair_bonus, right_side.pair_bonus);
    swap(left_side.block_, right_side.block_);
}

void Job_Fates::debug_console_print() const
{
    std::cout << std::endl << " " << id_ << " : " << name_;
    StatBlock_Fates::debug_console_print();
}

Job_Fates& Job_Fates::operator=(Job_Fates temp)
{
    swap(*this, temp);
    return *this;
}

void Job_Fates::add_ability(Ability_Job_Fates ability)
{
    auto it = ability_list_.begin();
    while (it != ability_list_.end()) {
        if (ability.requirement > it->requirement)
            it++;
        if (ability.requirement == it->requirement) {
            std::cout << "ERROR : cannot place duplicate level requirement skill to job " << id << " " << name
                << " NEW SKILL " << ability.id << " " << ability.name << " "
                << " EXISTING SKILL " << it->id << " " << it->name << std::endl;
            return;
        }
    }
    ability_list_.emplace(it, ability);
}
