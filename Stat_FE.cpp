#include "Stat_FE.h"

Stat_FE::Stat_FE()
{
	name = "default";
	stat = growth = max = 0;
}

Stat_FE::Stat_FE(const Stat_FE &old_stat_obj)
{
	stat = old_stat_obj.stat;
	growth = old_stat_obj.growth;
	max = old_stat_obj.max;
}

Stat_FE::Stat_FE(Stat_FE&& other) noexcept
	: Stat_FE()
{
	swap(*this, other);
}

Stat_FE::Stat_FE(const std::string& given_name)
	: Stat_FE()
{
	name = given_name;
}

Stat_FE::Stat_FE(const std::string& given_name, 
					const unsigned short int new_stat,
					const unsigned short int new_growth,
					const unsigned short int new_max)
					: Stat_FE(given_name)
{
	stat = new_stat;
	growth = new_growth;
	max = new_max;
}

Stat_FE::~Stat_FE()
{
}

void swap(Stat_FE& left, Stat_FE& right)
{
	using std::swap;
	swap(left.stat, right.stat);
	swap(left.growth, right.growth);
	swap(left.max, right.max);
}

Stat_FE& Stat_FE::operator++()
{
	stat++;
	return *this;
}

Stat_FE& Stat_FE::operator+=(const Stat_FE &right_stat)
{
	this->stat += right_stat.stat;
	this->growth += right_stat.stat;
	this->max += right_stat.max;
	return *this;
}

inline Stat_FE operator+(const Stat_FE& left_stat, const Stat_FE& right_stat)
{
	return Stat_FE(left_stat) += right_stat;
}

Stat_FE& Stat_FE::operator+=(const unsigned short int val)
{
	this->stat += val;
	return *this;
}

inline Stat_FE operator+(const Stat_FE& left_stat, unsigned short int right_val)
{
	return Stat_FE(left_stat) += right_val;
}

Stat_FE& Stat_FE::operator-=(const unsigned short int val)
{
	this->stat -= val;
	return *this;
}

inline Stat_FE operator-(const Stat_FE& left_stat, unsigned short int right_val)
{
	return Stat_FE(left_stat) -= right_val;
}

Stat_FE& Stat_FE::operator-=(const Stat_FE& right_stat)
{
	this->stat -= right_stat.stat;
	this->growth -= right_stat.stat;
	this->max -= right_stat.max;
	return *this;
}

inline Stat_FE operator-(const Stat_FE& left_stat, const Stat_FE& right_stat)
{
	return Stat_FE(left_stat) -= right_stat;
}

Stat_FE& Stat_FE::operator=(Stat_FE other)
{
	swap(*this, other);
	return *this;
}

int Stat_FE::roll_stat_up(unsigned short int count)
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

int Stat_FE::is_less_than_mac() const
{
	if (stat < max)
		return max - stat;
	else
		return 0;
}

int Stat_FE::is_less_than_max(unsigned short int x) const
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