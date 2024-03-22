#include "StatBlock_Fates.h"

StatBlock_Fates::StatBlock_Fates()
{
}

StatBlock_Fates::StatBlock_Fates(const StatBlock_Fates& other)
{
	block_ = other.block_;
}

StatBlock_Fates::StatBlock_Fates(StatBlock_Fates&& other) noexcept
	:StatBlock_Fates()
{
	swap(*this, other);
}

StatBlock_Fates::~StatBlock_Fates()
{
}

std::array<int, BLOCK_SIZE> StatBlock_Fates::get_stats()
{
	std::array<int, BLOCK_SIZE> result;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i].stat_;
	}
	return result;
}

std::array<int, BLOCK_SIZE> StatBlock_Fates::get_growths()
{
	std::array<int, BLOCK_SIZE> result;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i].growth_;
	}
	return result;
}

std::array<int, BLOCK_SIZE> StatBlock_Fates::get_maxs()
{
	std::array<int, BLOCK_SIZE> result;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i].max_;
	}
	return result;
}

StatBlock_Fates& StatBlock_Fates::operator=(const StatBlock_Fates& other)
{
	StatBlock_Fates temp(other);
	swap(*this, temp);
	return *this;
}

StatBlock_Fates& StatBlock_Fates::add_block(const StatBlock_Fates& other)
{
	if (this->block_.size() != other.block_.size()) {
		std::cout << " DEBUG Stat_block add_block : size does not match ";
		return *this;
	}
	for (auto i = 0; i < this->block_.size(); i++) {
		this->block_[i] += other.block_[i];
	}
	return *this;
}

StatBlock_Fates& StatBlock_Fates::subtract_block(const StatBlock_Fates& other)
{
	if (this->block_.size() != other.block_.size()) {
		std::cout << " DEBUG Stat_block subtract_block : size does not match ";
		return *this;
	}
	for (auto i = 0; i < this->block_.size(); i++) {
		this->block_[i] -= other.block_[i];
	}
	return *this;
}

void StatBlock_Fates::debug_print()
{
	for (const auto& stats : block_) {
		stats.print_To_Console();
	}
}

void swap(StatBlock_Fates &left_side, StatBlock_Fates &right_side)
{
	using std::swap;
	swap(left_side.block_, right_side.block_);
}