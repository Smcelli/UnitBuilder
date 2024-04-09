#pragma once
#include "fe_fates_namespace.h"
#include <array>

using namespace fe_fates;
class Bonus_statblock
{
private:
	uint16_t move_;
	std::array<uint16_t, BLOCK_SIZE> block_;
public:
	~Bonus_statblock() = default;
	Bonus_statblock() = default;
	Bonus_statblock(const Bonus_statblock&);
	friend void swap(Bonus_statblock&, Bonus_statblock&);
	Bonus_statblock& operator=(Bonus_statblock);
	Bonus_statblock(Bonus_statblock&&) noexcept;

	Bonus_statblock(
		std::array<int, BLOCK_SIZE>,
		int move = 0
	);
	uint16_t move() const { return move_; }
	uint16_t block_val(int i) const { return block_[i]; }
	void set_move(uint16_t m) { move_ = m; }
	void set_block(std::array<uint16_t, BLOCK_SIZE>);
	void debug_console_print() const;

	Bonus_statblock operator+= (const Bonus_statblock&);
	Bonus_statblock operator-= (const Bonus_statblock&);
};

