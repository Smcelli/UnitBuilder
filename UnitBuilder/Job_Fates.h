#pragma once
#include <StatBlock_Fates.h>
#include <vector>
#include <string>
#include <tuple>
#include <Bonus_list.h>
#include <Ability_FE.h>

class Job_Fates : public StatBlock_Fates
{
	friend class Rolodex;
public:
	Job_Fates(std::string name,
		int16_t id, int16_t move,
		Bonus_list pairup,
		StatBlock_Fates block)
		:StatBlock_Fates(block),
		name_(name), 
		id_(fe_fates::id_job(id)), 
		move_(move),
		pair_bonus(pairup){};

	int16_t id() const { return id_; };
	std::string name() const { return name_; };
	int16_t is_promoted_job() const { return id_%4; };
	int16_t get_unpromoted_id() const { return id_ - (id_ % 4); };
	std::vector<Ability_Job_Fates> ability_list() const { return ability_list_; };
	void debug_console_print() const;

	~Job_Fates() = default;
	Job_Fates() = default;
	Job_Fates(const Job_Fates& source)
		: StatBlock_Fates(source),
		name_(source.name_),
		id_(source.id_),
		move_(move_),
		ability_list_(source.ability_list_),
		pair_bonus(source.pair_bonus) {};
	friend void	swap(Job_Fates&, Job_Fates&);
	Job_Fates& operator=(Job_Fates);
	Job_Fates(Job_Fates&& source) noexcept
	{	swap(*this, source);};

protected:
	std::string name_;
	int16_t id_, move_;
	std::vector<Ability_Job_Fates> ability_list_;
	Bonus_list pair_bonus;

	void add_ability(Ability_Job_Fates ability);
};

