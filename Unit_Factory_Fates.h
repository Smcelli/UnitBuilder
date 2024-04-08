#pragma once
#include "fe_fates_namespace.h"
#include "Unit_Base_Fates.h"
#include "Job_Fates.h"

class Unit_Factory_Fates
{
private:
	Unit_Base_Fates base;
	Job_Fates job;
	

public:
	~Unit_Factory_Fates() = default;
	Unit_Factory_Fates() = default;
	Unit_Factory_Fates(const Unit_Factory_Fates&);
	friend void swap(Unit_Factory_Fates&, Unit_Factory_Fates&);
	Unit_Factory_Fates& operator=(Unit_Factory_Fates);
	Unit_Factory_Fates(Unit_Factory_Fates&&) noexcept;

	
};

