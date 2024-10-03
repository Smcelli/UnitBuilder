#include <Bonus_statblock.h>






Bonus_statblock::Bonus_statblock(const Bonus_statblock& source)
{
	bonuses = source.bonuses;
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

void swap(Bonus_statblock& left, Bonus_statblock& right)
{
	using std::swap;
	swap(left.bonuses, right.bonuses);
}

