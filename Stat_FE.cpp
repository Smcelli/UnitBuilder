#include "Stat_FE.h"

Stat_FE::Stat_FE(const Stat_FE& source)
	:stat(source.stat),
	growth(source.growth),
	max(source.max) {}

void swap(Stat_FE& left, Stat_FE& right)
{
	using std::swap;
	swap(left.stat, right.stat);
	swap(left.growth, right.growth);
	swap(left.max, right.max);
}

Stat_FE& Stat_FE::operator=(Stat_FE other)
{
	swap(*this, other);
	return *this;
}

Stat_FE::Stat_FE(Stat_FE&& source) noexcept
	: Stat_FE{}
{
	swap(*this, source);
}

Stat_FE& Stat_FE::operator++()
{
	stat++;
	return *this;
}

Stat_FE& Stat_FE::operator+=(const Stat_FE &right_stat)
{
	stat += right_stat.stat;
	growth += right_stat.stat;
	max += right_stat.max;
	return *this;
}

inline Stat_FE operator+(const Stat_FE& left_stat, const Stat_FE& right_stat)
{
	return Stat_FE(left_stat) += right_stat;
}

Stat_FE& Stat_FE::operator+=(const uint16_t val)
{
	stat += val;
	return *this;
}

inline Stat_FE operator+(const Stat_FE& left_stat, uint16_t right_val)
{
	return Stat_FE(left_stat) += right_val;
}

Stat_FE& Stat_FE::operator-=(const uint16_t val)
{
	stat -= val;
	return *this;
}

inline Stat_FE operator-(const Stat_FE& left_stat, uint16_t right_val)
{
	return Stat_FE(left_stat) -= right_val;
}

Stat_FE& Stat_FE::operator-=(const Stat_FE& right_stat)
{
	stat -= right_stat.stat;
	growth -= right_stat.stat;
	max -= right_stat.max;
	return *this;
}

inline Stat_FE operator-(const Stat_FE& left_stat, const Stat_FE& right_stat)
{
	return Stat_FE(left_stat) -= right_stat;
}



int Stat_FE::roll_stat_up(uint16_t count)
{
	for (auto i = 0; i < count; i++) {
		if (!is_less_than_max())
			break;
		if (roll_growth())
			stat++;
	}
	return stat;
}


int Stat_FE::roll_growth() const
{
	if (growth > rand() % 100)
		return 0;
	return 1;
}

int Stat_FE::is_less_than_max() const
{
	if (stat < max)
		return max - stat;
	else
		return 0;
}

int Stat_FE::is_less_than_max(uint16_t x) const
{
	if (x < max)
		return max-x;
	return 0;
}

void Stat_FE::print_To_Console() const
{
	std::cout << " " << name 
		<< " " << stat
		<< " " << growth
		<< " " << max << " ";
}