#pragma once
#include <string>
#include <iostream>

struct Ability_FE
{
	friend class Rolodex;
	std::string name;
	
	virtual ~Ability_FE() = default;
	Ability_FE() = default;
	Ability_FE(const Ability_FE&);
	friend void swap(Ability_FE&, Ability_FE&);
	Ability_FE& operator=(Ability_FE);
	Ability_FE(Ability_FE&&) noexcept;
	
	Ability_FE(std::string name)
		:name(name) {}
	virtual void debug_console_print() const;
	virtual void ability_effect() {};
};

struct Ability_Job_Fates : public Ability_FE
{
	int16_t id, requirement;


	~Ability_Job_Fates() = default;
	Ability_Job_Fates() = default;
	Ability_Job_Fates(const Ability_Job_Fates&);
	friend void swap(Ability_Job_Fates&, Ability_Job_Fates&);
	Ability_Job_Fates& operator=(Ability_Job_Fates);
	Ability_Job_Fates(Ability_Job_Fates&&) noexcept;

	Ability_Job_Fates(std::string name, int16_t id, int16_t requirement)
		: Ability_FE(name),
		requirement(requirement),
		id(id) {}
		
	int16_t get_job_id() const { return id / 2; };
	void ability_effect() {};
	void debug_console_print() const;
};

bool compare_req(const Ability_FE, const Ability_FE);
bool compare_id(const Ability_FE, const Ability_FE);

