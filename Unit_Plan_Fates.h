#pragma once
#include <map>
#include "fe_fates_namespace.h"

using std::map;
class Unit_Plan_Fates
{
public:
	~Unit_Plan_Fates() = default;
	Unit_Plan_Fates() = default;
	Unit_Plan_Fates(uint16_t, uint16_t);
	Unit_Plan_Fates(const Unit_Plan_Fates&);
	friend void swap(Unit_Plan_Fates&, Unit_Plan_Fates&);
	Unit_Plan_Fates& operator= (Unit_Plan_Fates);
	Unit_Plan_Fates(Unit_Plan_Fates&&) noexcept;

	bool is_proper_lvl(uint16_t);
	bool is_proper_action(uint16_t);
	void emplace(uint16_t, uint16_t);
	void remove(uint16_t);
	void remove(map<uint16_t, uint16_t>::iterator);
	map<uint16_t, uint16_t>::iterator get_first();
	map<uint16_t, uint16_t>::iterator get_next(uint16_t);

private:
	map<uint16_t, uint16_t> plan;
};

