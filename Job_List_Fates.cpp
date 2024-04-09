#include "Job_List_Fates.h"

Job_List_Fates::Job_List_Fates(const Job_List_Fates& source)
{
	jobs = source.jobs;
}

Job_List_Fates& Job_List_Fates::operator=(Job_List_Fates source)
{
	swap(*this, source);
	return *this;
}

Job_List_Fates::Job_List_Fates(Job_List_Fates&& source) noexcept
	:Job_List_Fates()
{
	swap(*this, source);
}

void Job_List_Fates::add_job(Job_Fates job)
{
	jobs.try_emplace(job.id, job);
}

void Job_List_Fates::add_job(uint16_t duplicate, uint16_t original)
{
	Job_Fates dup = jobs.at(original+ID_JOB_COMMON);
	dup.id = duplicate+ID_JOB_COMMON;
	jobs.try_emplace(duplicate+ID_JOB_COMMON, dup);
}

void Job_List_Fates::debug_console_print() const
{
	for (auto const& [key, val] : jobs) {
		val.debug_console_print();
	}
}

void swap(Job_List_Fates& left, Job_List_Fates& right)
{
	swap(left.jobs, right.jobs);
}
