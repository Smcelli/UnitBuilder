#pragma once
#include <string>
#include <iostream>

struct Ability_FE
{
	std::string name;
	unsigned short int id;
	
	virtual ~Ability_FE() = default;
	Ability_FE() = default;
	Ability_FE(const Ability_FE&);
	friend void swap(Ability_FE&, Ability_FE&);
	Ability_FE& operator=(Ability_FE);
	Ability_FE(Ability_FE&&) noexcept;
	
	Ability_FE(std::string name, unsigned short int id)
		:name(name),
		id(id) {}
	virtual void debug_console_print() const;
	virtual void ability_effect() {};
};

struct Ability_Job_Fates : public Ability_FE
{
	unsigned short int requirement;

	~Ability_Job_Fates() = default;
	Ability_Job_Fates() = default;
	Ability_Job_Fates(const Ability_Job_Fates&);
	friend void swap(Ability_Job_Fates&, Ability_Job_Fates&);
	Ability_Job_Fates& operator=(Ability_Job_Fates);
	Ability_Job_Fates(Ability_Job_Fates&&) noexcept;

	Ability_Job_Fates(std::string name, unsigned short int id, unsigned short int requirement)
		: requirement(requirement),
		Ability_FE(name, id){}
	unsigned short int get_job_id() const { return id / 2; };
	void ability_effect() {};
	void debug_console_print() const;
};

bool compare_req(const Ability_FE, const Ability_FE);
bool compare_id(const Ability_FE, const Ability_FE);

