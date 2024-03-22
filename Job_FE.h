#pragma once
#include "Stat_FE.h"
#include <array>
#include <string>

class Job_Fates
{
	std::string job_name;
	int job_id;
	std::array <Stat_FE, 8> job_statblock;


	virtual bool isPromotedJob();
};

