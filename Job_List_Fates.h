#pragma once
#include<unordered_map>
#include"Job_Fates.h"

class Job_List_Fates
{
private:
	std::unordered_map<uint16_t, Job_Fates> jobs;

public:
	~Job_List_Fates() = default;
	Job_List_Fates() = default;
	Job_List_Fates(const Job_List_Fates&);
	friend void swap(Job_List_Fates&, Job_List_Fates&);
	Job_List_Fates& operator=(Job_List_Fates);
	Job_List_Fates(Job_List_Fates&&) noexcept;

	Job_Fates get_job(uint16_t) const;
	Job_Fates* get_job_ptr(uint16_t);
	void add_job(Job_Fates);
	void add_job(uint16_t duplicate, uint16_t original);
	void debug_console_print() const;
};

