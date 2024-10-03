#pragma once
#include <Stat_FE.h>
#include <fe_fates_namespace.h>
#include <array>

using fe_fates::BLOCK_SIZE, std::array;

class StatBlock_Fates
{
	typedef std::array<int16_t, fe_fates::BLOCK_SIZE> arr_b;
	using enum fe_fates::ids::Stat_type;
public:

	StatBlock_Fates(arr_b stats, arr_b growths, arr_b maxs);

	arr_b get_stats() const;
	arr_b get_growths() const;
	arr_b get_maxs() const;
	StatBlock_Fates& add_block(const StatBlock_Fates&);
	StatBlock_Fates& add_block(const StatBlock_Fates*);
	StatBlock_Fates& subtract_block(const StatBlock_Fates&);
	StatBlock_Fates& subtract_block(const StatBlock_Fates*);
	
	
	int16_t operator[](const size_t location) const;
	StatBlock_Fates& operator+= (std::pair<int16_t, size_t>);

	std::pair<size_t, size_t> to_indexes(size_t) const;
	void prep_average();
	void levelup_average(int16_t);
	void levelup(int16_t);
	void serenes_forest(std::array<int16_t, BLOCK_SIZE>);
	void debug_console_print() const;

	virtual ~StatBlock_Fates() = default;
	StatBlock_Fates() = default;
	StatBlock_Fates(const StatBlock_Fates& source) : block_(source.block_) {};
	friend void swap(StatBlock_Fates& left, StatBlock_Fates& right) {std::swap( left.block_, right.block_ );};
	StatBlock_Fates& operator=(StatBlock_Fates);
	StatBlock_Fates(StatBlock_Fates&& source) noexcept { swap(*this, source); };

protected:
	int16_t& operator[](const size_t location);
	std::array <Stat_FE, fe_fates::BLOCK_SIZE> block_;
};

