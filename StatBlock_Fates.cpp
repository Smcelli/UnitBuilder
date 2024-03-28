#include "StatBlock_Fates.h"


StatBlock_Fates::StatBlock_Fates(const StatBlock_Fates& source)
{
	block_ = source.block_;
}

void swap(StatBlock_Fates& left_side, StatBlock_Fates& right_side)
{
	using std::swap;
	swap(left_side.block_, right_side.block_);
}

StatBlock_Fates& StatBlock_Fates::operator=(StatBlock_Fates source)
{
	swap(*this, source);
	return *this;
}

StatBlock_Fates::StatBlock_Fates(StatBlock_Fates&& source) noexcept
	: StatBlock_Fates{}
{
	swap(*this, source);
}

std::array<unsigned short int, BLOCK_SIZE> StatBlock_Fates::get_stats()
{
	std::array<unsigned short int, BLOCK_SIZE> result;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i].stat;
	}
	return result;
}

std::array<unsigned short int, BLOCK_SIZE> StatBlock_Fates::get_growths()
{
	std::array<unsigned short int, BLOCK_SIZE> result;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i].growth;
	}
	return result;
}

std::array<unsigned short int, BLOCK_SIZE> StatBlock_Fates::get_maxs()
{
	std::array<unsigned short int, BLOCK_SIZE> result;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i].max;
	}
	return result;
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

