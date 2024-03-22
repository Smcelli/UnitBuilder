#include "Stat_FE.h"

Stat_FE::Stat_FE()
{
	name = "default";
	stat_ = growth_ = max_ = 0;
}

Stat_FE::Stat_FE(const Stat_FE &old_stat_obj)
{
	stat_ = old_stat_obj.stat_;
	growth_ = old_stat_obj.growth_;
	max_ = old_stat_obj.max_;
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
					const int stat, 
					const int growth, 
					const int max) 
					: Stat_FE(given_name)
{
	stat_ = stat;
	growth_ = growth;
	max_ = max;
}

Stat_FE::~Stat_FE()
{
}

void swap(Stat_FE& left, Stat_FE& right)
{
	using std::swap;
	swap(left.stat_, right.stat_);
	swap(left.growth_, right.growth_);
	swap(left.max_, right.max_);
}

Stat_FE& Stat_FE::operator++()
{
	stat_++;
	return *this;
}

Stat_FE& Stat_FE::operator+=(const Stat_FE &right_stat)
{
	this->stat_ += right_stat.stat_;
	this->growth_ += right_stat.stat_;
	this->max_ += right_stat.max_;
	return *this;
}

inline Stat_FE operator+(const Stat_FE& left_stat, const Stat_FE& right_stat)
{
	return Stat_FE(left_stat) += right_stat;
}

Stat_FE& Stat_FE::operator+=(const int val)
{
	this->stat_ += val;
	return *this;
}

inline Stat_FE operator+(const Stat_FE& left_stat, int right_val)
{
	return Stat_FE(left_stat) += right_val;
}

Stat_FE& Stat_FE::operator-=(const int val)
{
	this->stat_ -= val;
	return *this;
}

inline Stat_FE operator-(const Stat_FE& left_stat, int right_val)
{
	return Stat_FE(left_stat) -= right_val;
}

Stat_FE& Stat_FE::operator-=(const Stat_FE& right_stat)
{
	this->stat_ -= right_stat.stat_;
	this->growth_ -= right_stat.stat_;
	this->max_ -= right_stat.max_;
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


int Stat_FE::roll_Stat_Up() const
{
	if (growth_ > rand() % 100)
		return 0;
	return 1;
}

int Stat_FE::is_less_than_max(int x) const
{
	if (x < max_)
		return 1;
	return 0;
}

int Stat_FE::stat() const
{
	return stat_;
}

void Stat_FE::print_To_Console() const
{
	std::cout << " " << name 
		<< " " << stat_
		<< " " << growth_
		<< " " << max_ << " ";
}

