#include "Unit_Factory_Fates.h"

Unit_Factory_Fates::Unit_Factory_Fates(const Unit_Factory_Fates& source)
	:base(source.base),
	job(source.job){}

Unit_Factory_Fates& Unit_Factory_Fates::operator=(Unit_Factory_Fates temp)
{
	swap(*this, temp);
	return *this;
}

Unit_Factory_Fates::Unit_Factory_Fates(Unit_Factory_Fates&& temp) noexcept
{
	swap(*this, temp);
}

void swap(Unit_Factory_Fates& left, Unit_Factory_Fates& right)
{
	swap(left.base, right.base);
	swap(left.job, right.job);
}
