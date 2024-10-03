#include <fe_fates_namespace.h>

int16_t fe_fates::id_skill_job(int16_t id, int16_t value) {
	if (value < 0 || value > 6)
		return 0;
	else if (id > ID_SKILL_JOB * 2)
		return 0;
	else if (id * 2 < ID_SKILL_JOB)
		return (id * 2) + ID_SKILL_JOB + value;
	else
		return id;
}

int16_t fe_fates::id_type(int16_t id, int16_t type) {
	if (id > type * 2)
		return 0;
	if (id < type)
		return id + type;
	return id;
}

int16_t fe_fates::id_job(int16_t id) {
	return id_type(id, ID_JOB);
};
int16_t fe_fates::id_unit(int16_t id) {
	return id_type(id, ID_UNIT);
};
int16_t fe_fates::id_skill_unit(int16_t id) {
	return id_type(id, ID_SKILL_UNIT);
};

int16_t fe_fates::id_job_base(int16_t id) {
	return id -= id % 4;
};
int16_t fe_fates::id_job_is_promo(int16_t id) {
	return id % 4;
};
bool fe_fates::in_level_range(int16_t level)
{
	return (level > 0 && level < 1024);
};

