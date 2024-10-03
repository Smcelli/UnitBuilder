#include "Unit_Full_Fates.h"

Unit_Full_Fates::Unit_Full_Fates(int16_t id)
	:base(common_table.get_unit(id))
{
	current_job = common_table.get_job_ptr(base.get_prim_job());
	Unit_Plan_Fates plan{ base.level().first, current_job->id()};
	pal = spouse = NULL;
	base.add_block(current_job);
}

void Unit_Full_Fates::debug_console_print() const
{
	using std::cout, std::endl;
	cout << std::endl << "FULL UNIT" << endl;
	base.debug_console_print();
	if (current_job) cout << " job: " << current_job->name() << ",  id: " << current_job->id() << endl;
	if (spouse) cout  << " spouse: " << spouse->base.name() << ",  id: " << spouse->base.id() << endl;
	if (pal) cout << " friend: " << pal->base.name() << ",  id: " << pal->base.id() << endl;
}

std::unordered_set<int16_t> Unit_Full_Fates::get_valid_jobs() const
{
	std::unordered_set<int16_t> result{};
	auto jobs = base.jobs();
	auto it = jobs.begin();
	for (it = jobs.begin(); it != jobs.end(); it++) {
		result.insert(*it);
	}
	int16_t pal_job = get_inhereted_job(pal, result);

	int16_t spouse_job = get_inhereted_job(spouse, result);

	if (pal_job)
		result.insert(pal_job);
	if (spouse_job)
		result.insert(spouse_job);
	return result;
}

int16_t Unit_Full_Fates::get_inhereted_job(Unit_Full_Fates* partner, std::unordered_set<int16_t>& job_set) const
{
	if (!partner)
		return 0;
	auto jobs = partner->base.jobs();
	if (!jobs.empty()) {
		auto it = jobs.begin();
		if (*it < fe_fates::ids::debug_job_unique_end)
			it++;
		for (it; it != jobs.end(); it++) {
			if (!job_set.count(*it)) {
				return *it;
			}
		}
		it = jobs.begin();
		return common_table.get_backup_job_id(*it);
	}
	return 0;
}