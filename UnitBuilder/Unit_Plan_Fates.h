#pragma once
#include <map>
#include "fe_fates_namespace.h"
#include "Rolodex.h"
#include "Job_Fates.h"

class Unit_Plan_Fates
{
public:
	Unit_Plan_Fates(int16_t, int16_t);

	bool is_proper_lvl(int16_t);
	bool is_promotion(int16_t, int16_t);
	
	void remove(int16_t);
	void remove(std::map<int16_t, int16_t>::iterator);
	void remove_invalid_promoted();
	void force_promotion();
	std::map<int16_t, int16_t>::iterator emplace(int16_t, int16_t);
	std::map<int16_t, int16_t>::iterator get_first();
	std::map<int16_t, int16_t>::iterator get_prev(int16_t);
	std::map<int16_t, int16_t>::iterator get_next(int16_t);
	std::map<int16_t, int16_t>::iterator get_end();
	std::map<int16_t, int16_t>::iterator get_promotion() const;
	bool empty();
	bool has_promotion();
	bool in_promotion_range(int16_t);


	~Unit_Plan_Fates() = default;
	Unit_Plan_Fates() = default;
	Unit_Plan_Fates(const Unit_Plan_Fates&);
	friend void swap(Unit_Plan_Fates&, Unit_Plan_Fates&);
	Unit_Plan_Fates& operator= (Unit_Plan_Fates);
	Unit_Plan_Fates(Unit_Plan_Fates&&) noexcept;

private:
	std::map<int16_t, int16_t> plan;
	std::map<int16_t, int16_t>::iterator promotion;
};

