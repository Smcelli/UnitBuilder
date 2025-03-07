#pragma once
#include <Ability_FE.h>
#include <unordered_map>

class Ability_List_Fates
{
private:
	std::unordered_map<int16_t,Ability_FE> abilities_;

public:
	~Ability_List_Fates() = default;
	Ability_List_Fates() = default;
	Ability_List_Fates(const Ability_List_Fates&);
	friend void swap(Ability_List_Fates&, Ability_List_Fates&);
	Ability_List_Fates& operator=(Ability_List_Fates);
	Ability_List_Fates(Ability_List_Fates&&) noexcept;

	//void add_skill(Ability_Job_Fates);
	void add_skill(Ability_FE);
	void debug_console_print() const;
protected:

};