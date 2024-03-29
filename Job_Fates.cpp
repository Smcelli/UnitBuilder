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

Job_Fates& Job_Fates::operator=(Job_Fates source)
{
    swap(*this, source);
    return *this;
}

Job_Fates::Job_Fates(Job_Fates&& source) noexcept
    : StatBlock_Fates{ std::move(source) },
    name(std::string("default")),
    id(0),
    move(0),
    promotion(0),
    pair_bonus({})
{
    swap(*this, source);
}

Job_Fates::Job_Fates(std::string name,
    StatBlock_Fates block,
    Bonus_statblock b_block,
    fe_fates::Job_name id,
    int promotion,
    int move)
    :StatBlock_Fates(block),
    pair_bonus(b_block),
    name(name),
    id(id),
    promotion(static_cast<uint16_t>(promotion)),
    move(static_cast<uint16_t>(move)) {}

void Job_Fates::debug_console_print() const
{
    using std::cout, std::endl;
    cout << " " << name
        << " id: " << id
        << " promoted: " << promotion
        << " move: " << move 
        << endl << "pair up bonus: ";
    for (auto i = 0; i < BLOCK_SIZE; i++) {
        cout << " " << i
            << ":" << pair_bonus.block_val(i)
            << " ";
    }
    cout << pair_bonus.move() << endl;
    StatBlock_Fates::debug_console_print();
    cout << endl;
}
