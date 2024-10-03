#include <Stat_FE.h>

Stat_FE& Stat_FE::operator+=(const Stat_FE& rhs)
{
	for (auto i = 0; i < fe_fates::STAT_SIZE; i++) {
		(*this)[i] += rhs[i];
	}
	return *this;
}

Stat_FE& Stat_FE::operator+=(const int16_t& rhs)
{
	(*this)[stat_val] += rhs;
	return *this;
}

Stat_FE& Stat_FE::operator-=(const Stat_FE& rhs)
{
	for (int16_t i = 0; i < fe_fates::STAT_SIZE; i++) {
		(*this)[i] -= rhs[i];
	}
	return *this;
}

Stat_FE& Stat_FE::operator-=(const int16_t& rhs)
{
	(*this)[stat_val] -= rhs;
	return *this;
}

int16_t Stat_FE::levelup_random(int16_t count = 1)
{
	for (auto i = 0; i < count; i++) {
		if (!is_less_than_max())
			break;
		if ((rand() % 100) < (*this)[growth])
			(*this)[stat_val]++;
	}
	return (*this)[stat_val];
}

void Stat_FE::debug_console_print() const
{
	std::cout << "Stat [" << (*this)[stat_val] << "] Growth [" << (*this)[growth] << "] Max [" << (*this)[max] << "]";
}

Stat_FE::Stat_FE(const Stat_FE& source)
{
	stat_growth_max_ = source.stat_growth_max_;
}

Stat_FE& Stat_FE::operator=(Stat_FE source)
{
	swap(*this, source);
	return *this;
}

void swap(Stat_FE& left, Stat_FE& right)
{
	swap(left.stat_growth_max_, right.stat_growth_max_);
}
