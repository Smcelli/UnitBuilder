#include "Unit_Full_Fates.h"

Unit_Full_Fates::Unit_Full_Fates(int16_t id)
	:base(common_table.get_unit(id))
{
	current_job = common_table.get_job_ptr(base.get_prim_job());
	Unit_Plan_Fates plan{ base.level().first, current_job->id()};
	pal = spouse = NULL;
	base.add_block(current_job);
}

fe_fates::Job_list_fates Unit_Full_Fates::get_valid_jobs(int16_t avatar_job)
{
	fe_fates::Job_list_fates result;
	result.jobs = base.jobs();


	auto get_borrowed_job = [&](Unit_Base_Fates* donor) -> int16_t
	{
		auto jobs = donor->jobs();
		if (jobs.empty())
			return 0;

		auto borrowed_job = jobs[0];
		if (borrowed_job < fe_fates::ids::debug_job_unique_end || borrowed_job == result.jobs[0])
		{
			if (jobs.size() < 2)
				return 0;
			else
				borrowed_job = jobs[1];
		}
		if (borrowed_job != result.jobs[0])
			return borrowed_job;
		else
			return fe_fates::get_parallel_job(jobs[0]);
	};

	result.pal_job = get_borrowed_job(pal);
	result.spouse_job = get_borrowed_job(spouse);

	if (avatar_job) {
		avatar_job = fe_fates::id_job_get_genderless(fe_fates::id_job_base(avatar_job));
		if (avatar_job == result.jobs[0] && fe_fates::get_parallel_job(avatar_job))
			avatar_job = fe_fates::get_parallel_job(avatar_job);

		if (pal->id() < fe_fates::ids::debug_unit_avatar_end)
			result.pal_job = avatar_job;
		else if (spouse->id() < fe_fates::ids::debug_unit_avatar_end)
			result.spouse_job = avatar_job;
	}

	return result;
}

void Unit_Full_Fates::debug_console_print() const
{
	using std::cout, std::endl;
	cout << std::endl << "FULL UNIT" << endl;
	base.debug_console_print();
	if (current_job) cout << " job: " << current_job->name() << ",  id: " << current_job->id() << endl;
	if (spouse) cout  << " spouse: " << spouse->name() << ",  id: " << spouse->id() << endl;
	if (pal) cout << " friend: " << pal->name() << ",  id: " << pal->id() << endl;
}