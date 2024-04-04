#include "Job_Fates.h"

Job_Fates::Job_Fates(const Job_Fates& source)
    : StatBlock_Fates(source),
    name(source.name),
    id(source.id),
    promotion(source.promotion),
    move(source.move),
    //weapon_ranks(source.weapon_ranks),
    ability_list(source.ability_list),
    pair_bonus(source.pair_bonus) {}
    

void swap(Job_Fates& left_side, Job_Fates& right_side)
{
    using std::swap;
    swap(left_side.name, right_side.name);
    swap(left_side.promotion, right_side.promotion);
    swap(left_side.move, right_side.move);
    //swap(left_side.weapon_ranks, right_side.weapon_ranks);
    swap(left_side.ability_list, right_side.ability_list);
    swap(left_side.pair_bonus, right_side.pair_bonus);
    swap(static_cast<StatBlock_Fates&>(left_side), static_cast<StatBlock_Fates&>(right_side));
}

Job_Fates& Job_Fates::operator=(Job_Fates temp)
{
    swap(*this, temp);
    return *this;
}

Job_Fates::Job_Fates(Job_Fates&& source) noexcept
    : Job_Fates()
{
    swap(*this, source);
}

Job_Fates::Job_Fates(std::string name,
    StatBlock_Fates block,
    Bonus_statblock b_block,
    uint16_t id,
    int promotion,
    int move)
    :StatBlock_Fates(block),
    pair_bonus(b_block),
    name(name),
    id(id),
    promotion(static_cast<int16_t>(promotion)),
    move(static_cast<int16_t>(move)) {}

void Job_Fates::debug_console_print() const
{
    using std::cout, std::endl;
    cout << " " << name
        << " id: " << id
        << " promoted: " << promotion
        << " move: " << move 
        << endl << " pair up bonus: ";
    pair_bonus.debug_console_print();
    cout << endl << " Stats ";
    StatBlock_Fates::debug_console_print();
    cout << endl;
}
