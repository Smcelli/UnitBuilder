#include <fe_fates_namespace.h>

int16_t fe_fates::id_skill_job(int16_t id, int16_t value)  {
	if (value < 0 || value > 6)
		return 0;
	else if (id > ID_SKILL_JOB * 2)
		return 0;
	else if (id * 2 < ID_SKILL_JOB)
		return (id * 2) + ID_SKILL_JOB + value;
	else
		return id;
}

int16_t fe_fates::id_type(int16_t id, int16_t type)  {
	if (id > type * 2)
		return 0;
	if (id < type)
		return id + type;
	return id;
}

int16_t fe_fates::id_job(int16_t id)  {
	return id_type(id, ID_JOB);
};
int16_t fe_fates::id_unit(int16_t id)  {
	return id_type(id, ID_UNIT);
};
int16_t fe_fates::id_skill_unit(int16_t id)  {
	return id_type(id, ID_SKILL_UNIT);
};

int16_t fe_fates::id_job_base(int16_t id)  {
	return id - (id % 4);
};
int16_t fe_fates::id_job_is_promo(int16_t id)  {
	return id % 4;
}
int16_t fe_fates::id_job_get_genderless(int16_t id)
{
	id = id_job_base(id);
	if (!id_job_is_gendered(id))
		return id;
	if (id < fe_fates::ids::troubadour)
		return fe_fates::ids::monk_maiden;
	else
		return fe_fates::ids::troubadour;
}

int16_t fe_fates::id_job_get_gendered(int16_t id, bool female)
{
	using namespace fe_fates::ids;
	id = id_job_base(id);
	id = id_job_get_genderless(id);
	if (id == troubadour) {
		if (female)
			return troubadour_f;
		return troubadour_m;
	}
	else if (id == monk_maiden) {
		if (female)
			return shrine_maiden;
		return monk;
	}
	else
		return id;
}

int16_t fe_fates::id_get_type(int16_t id)
{
	if (id > 0) {
		if (id < ID_STAT)
			return 0; 
		else if (id < ID_JOB)
			return ID_STAT; 
		else if (id < ID_SKILL_JOB)
			return ID_JOB; 
		else if (id < ID_UNIT)
			return ID_SKILL_JOB; 
		else
			return ID_UNIT; 
	}
	return 0;
}

bool fe_fates::id_job_is_gendered(int16_t id)
{
	if (id > fe_fates::ids::debug_job_gendered || id < fe_fates::ids::debug_job_gendered_end)
		return true;
	return false;
}

bool fe_fates::in_level_range(int16_t level)
{
	return (level > 0 && level < 1024);
}

int16_t fe_fates::get_parallel_job(int16_t job)
{
	using namespace fe_fates::ids;
	job = id_job_base(job);
	switch (job) {
		case cavalier:
			return ninja;
		case knight:
			return spear_fighter;
		case fighter:
			return oni_savage;
		case mercenary:
			return samurai;
		case outlaw:
			return archer;
		case samurai:
			return mercenary;
		case oni_savage:
			return fighter;
		case spear_fighter:
			return knight;
		case diviner:
			return dark_mage;
		case sky_knight:
			return wyvern_rider;
		case archer:
			return outlaw;
		case wyvern_rider:
			return sky_knight;
		case ninja:
			return cavalier;
		case dark_mage:
			return diviner;
		case wolfskin:
			return outlaw;
		case kitsune:
			return apothecary;
		case songstress:
			return troubadour;
		case villager:
			return apothecary;
		default:
			return job;
	}
}

