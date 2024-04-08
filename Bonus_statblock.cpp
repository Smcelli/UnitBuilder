#include "Bonus_statblock.h"

Bonus_statblock::Bonus_statblock(const Bonus_statblock& source)
{
	move_ = source.move_;
	block_ = source.block_;
}

Bonus_statblock& Bonus_statblock::operator=(Bonus_statblock source)
{
	swap(*this, source);
	return *this;
}

Bonus_statblock::Bonus_statblock(Bonus_statblock&& source) noexcept
	: Bonus_statblock()
{
	swap(*this, source);
}

Bonus_statblock::Bonus_statblock(
	std::array<int, BLOCK_SIZE> block, 
	int move)
	:move_(move)
{
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		block_[i] = static_cast<uint16_t>(block[i]);
	}
}

void Bonus_statblock::set_block( std::array<uint16_t, BLOCK_SIZE> b)
{
	block_ = b;
}

void Bonus_statblock::debug_console_print() const
{
	using std::cout, std::endl;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		cout << " [" << fe_fates::fates_names.at(ID_STAT + i) << " : "
			<< block_[i] << "] ";
	}
	cout << " [Movement : " << move_;
}

Bonus_statblock Bonus_statblock::operator+=(const Bonus_statblock& right)
{
	move_ += right.move_;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		block_[i] += right.block_[i];
	}
	return *this;
}

inline Bonus_statblock operator+ (const Bonus_statblock& left, const Bonus_statblock& right) 
{
	return Bonus_statblock(left) += right;
}

Bonus_statblock Bonus_statblock::operator-=(const Bonus_statblock& right)
{
	move_ -= right.move_;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		block_[i] -= right.block_[i];
	}
	return *this;
}

inline Bonus_statblock operator-(const Bonus_statblock& left, const Bonus_statblock& right)
{
	return Bonus_statblock(left) -= right;
}

void swap(Bonus_statblock& left, Bonus_statblock& right)
{
	using std::swap;
	swap(left.move_, right.move_);
	swap(left.block_, right.block_);
}

