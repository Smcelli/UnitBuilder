#pragma once
#include "fe_fates_namespace.h"
#include "Rolodex.h"
#include <Job_Fates.h>
#include <Unit_Plan_Fates.h>

class Unit_Active : public StatBlock_Fates 
{
	
public:

	Unit_Active(const StatBlock_Fates&, const Unit_Plan_Fates&, Job_Fates*, int16_t);


	void make_average_unit();
	void change_job(Job_Fates*);
	void change_job(int16_t id);
	void level_to(int16_t);

	~Unit_Active() = default;
	Unit_Active() = default;

protected:
	bool is_average = false;
	int16_t level;
	Job_Fates* currect_job;
	Unit_Plan_Fates plan;
	std::pair <int16_t, int16_t> aptitude;

	void level_to_ambiguous(int16_t);
};