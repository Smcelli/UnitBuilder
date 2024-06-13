#include "Unit_Full_Fates.h"

void Unit_Full_Fates::generate_base()
{
	if (!current_job)
		return;
	auto growths = current_job->get_growths();
	auto maxs = current_job->get_maxs();
	auto stats_but_zero = maxs;
	for (auto value : stats_but_zero)
		value = 0;
	
	StatBlock_Fates temp{ stats_but_zero, growths, maxs };
	base.add_block(temp);
}

Unit_Full_Fates::Unit_Full_Fates(uint16_t id, Rolodex* table)
	:base(table->get_unit(id))
{
	current_job = table->get_job_ptr(base.get_primary_job());
	Unit_Plan_Fates plan{ base.get_lvl(), current_job->id};
	pal = spouse = NULL;
	generate_base();
}

void Unit_Full_Fates::remove_friend()
{
	if (!pal)
		return;
	if (pal->pal == this)
		pal->pal = NULL;
	pal = NULL;
}

void Unit_Full_Fates::remove_spouse()
{
	if (!spouse)
		return;
	if (spouse->spouse == this)
		spouse->spouse = NULL;
	spouse = NULL;

}

void Unit_Full_Fates::add_spouse(Unit_Full_Fates* s)
{
	remove_spouse();
	s->remove_spouse();
	spouse = s;
	s->spouse = this;
}

void Unit_Full_Fates::debug_console_print() const
{
	using std::cout, std::endl;
	base.debug_console_print();
	if (current_job) cout << " job: " << current_job->name << ",  id: " << current_job->id << endl;
	if (spouse) cout  << " spouse: " << spouse->base.get_name() << ",  id: " << spouse->base.get_id() << endl;
	if (pal) cout << " friend: " << pal->base.get_name() << ",  id: " << pal->base.get_id() << endl;
}