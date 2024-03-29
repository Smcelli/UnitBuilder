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

StatBlock_Fates::StatBlock_Fates(
	std::array<uint16_t, fe_fates::BLOCK_SIZE> stats, 
	std::array<uint16_t, fe_fates::BLOCK_SIZE> growths, 
	std::array<uint16_t, fe_fates::BLOCK_SIZE> maxs)
{
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		block_[i] = Stat_FE{"", stats[i], growths[i], maxs[i]};
	}
}

StatBlock_Fates::StatBlock_Fates(
	std::array<int, fe_fates::BLOCK_SIZE> stats,
	std::array<int, fe_fates::BLOCK_SIZE> growths,
	std::array<int, fe_fates::BLOCK_SIZE> maxs)
{
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		block_[i] = Stat_FE{ "", 
			static_cast<uint16_t>(stats[i]), 
			static_cast<uint16_t>(growths[i]),
			static_cast<uint16_t>(maxs[i])};
	}
}

std::array<uint16_t, BLOCK_SIZE> StatBlock_Fates::get_stats()
{
	std::array<uint16_t, BLOCK_SIZE> result;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i].stat;
	}
	return result;
}

std::array<uint16_t, BLOCK_SIZE> StatBlock_Fates::get_growths()
{
	std::array<uint16_t, BLOCK_SIZE> result;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i].growth;
	}
	return result;
}

std::array<uint16_t, BLOCK_SIZE> StatBlock_Fates::get_maxs()
{
	std::array<uint16_t, BLOCK_SIZE> result;
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

void StatBlock_Fates::debug_console_print() const
{
	for (const auto& stats : block_) {
		stats.debug_console_print();
	}
}

