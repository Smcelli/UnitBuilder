#pragma once
#include <StatBlock_Fates.h>
#include <algorithm>
#include <vector>
#include <Bonus_list.h>

class Unit_Base_Fates : public StatBlock_Fates
{
	friend class Rolodex;
public:
	Unit_Base_Fates(std::string name,
		StatBlock_Fates block,
		Bonus_list pair_bonus,
		std::vector<int16_t> jobs,
		int16_t id, int16_t level, int16_t level_offset = 0);

	std::string name() { return name_; }
	int16_t id() const {return id_;};
	std::pair<int16_t, int16_t> level() { return std::pair<int16_t, int16_t> {level_, level_offset_}; };
	std::vector<int16_t> jobs() const;
	int16_t get_prim_job() const { return jobs_[0]; };
	void set_jobs(std::vector<int16_t> const &new_jobs) { jobs_ = new_jobs; };
	void debug_console_print() const;

	~Unit_Base_Fates() = default;
	Unit_Base_Fates() = default;
	Unit_Base_Fates(const Unit_Base_Fates& source)	
		:StatBlock_Fates(source),
		name_(source.name_),
		id_(source.id_),
		level_(source.level_),
		level_offset_(source.level_offset_),
		pair_bonus(source.pair_bonus),
		jobs_(source.jobs_) {};
	friend void swap(Unit_Base_Fates&, Unit_Base_Fates&);
	Unit_Base_Fates& operator= (Unit_Base_Fates);
	Unit_Base_Fates(Unit_Base_Fates&& source) noexcept :Unit_Base_Fates() { swap(*this, source); };

private:
	std::string name_;
	std::vector<int16_t> jobs_;
	Bonus_list pair_bonus;
	int16_t id_, level_, level_offset_;
};