#pragma once
#include <fe_fates_namespace.h>
#include <random>
#include <iostream>
#include <array>

class Stat_FE
{
	friend class Statblock_fates;
	using enum fe_fates::ids::Stat_type;
	typedef std::array<int16_t, fe_fates::STAT_SIZE> arr_s;

public:

	Stat_FE(int16_t stat_ = 0, int16_t growth_ =0, int16_t max_ =0) 
		:stat_growth_max_{stat_, growth_, max_} {};
	Stat_FE(arr_s values) 
		:stat_growth_max_(values) {};

	Stat_FE& operator += (const Stat_FE&);
	Stat_FE& operator += (const int16_t&);

	Stat_FE& operator -= (const Stat_FE&);
	Stat_FE& operator -= (const int16_t&);

	
	int16_t operator [] (const size_t& location) const {return stat_growth_max_[location];};
	int16_t& operator [] (const size_t& location) { return stat_growth_max_[location]; };

	int16_t levelup_average(int16_t count) { return  (*this)[stat_val] += ((*this)[growth] * count); };
	int16_t levelup_random(int16_t count);
	bool is_less_than_max() const{	return ((*this)[stat_val] < (*this)[max]); };
	void debug_console_print() const;

	virtual ~Stat_FE() = default;
	Stat_FE(const Stat_FE& source);
	friend void swap(Stat_FE&, Stat_FE&);
	Stat_FE& operator= (Stat_FE);
	Stat_FE(Stat_FE&& source) noexcept { swap(*this, source); };

protected:
	arr_s stat_growth_max_;
};