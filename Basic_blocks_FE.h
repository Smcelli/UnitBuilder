#pragma once
#include <string>
#include <iostream>
#include "fe_fates_namespace.h"
#include <unordered_set>

using std::unordered_map, std::unordered_set, std::pair;

struct Weapon_Rank_FE
{
	std::string name;
	uint16_t rank, id;
	auto compare_id(const Weapon_Rank_FE left, const Weapon_Rank_FE right) {
		if (left.id < right.id) return		std::strong_ordering::less;
		if (left.id > right.id) return		std::strong_ordering::greater;
		return								std::strong_ordering::equal;
	}
};

struct Support_FE {
	uint16_t unit1 = 0, unit2 = 0, type = 0;
	Support_FE(uint16_t u1, uint16_t u2, int t)
	: unit1(u1),
	unit2(u2),
	type(static_cast<uint16_t>(t)){}
	Support_FE(uint16_t u1, uint16_t u2, uint16_t t) 
	:unit1(u1),
	unit2(u2),
	type(t){}
};

class Support_Table_FE {
private:
	unordered_map<uint16_t, unordered_set< uint16_t>> marriages;
	unordered_map<uint16_t, unordered_set< uint16_t>> friends;
	unordered_map<uint16_t, pair<uint16_t, uint16_t>> children;
	unordered_map<uint16_t, pair<uint16_t, uint16_t>> parents;
	void emplace(uint16_t unit1, uint16_t unit2, unordered_map<uint16_t, unordered_set<uint16_t>>* type);
	void emplace_primary_child(uint16_t, uint16_t);

public:
	void emplace(Support_FE);
	void emplace(uint16_t unit, int type, unordered_set<uint16_t> supports);
	unordered_set<uint16_t> get_marraiges(uint16_t) const;
	unordered_set<uint16_t> get_friends(uint16_t) const;
	pair<uint16_t, uint16_t> get_children(uint16_t) const;
	pair<uint16_t, uint16_t> get_parents(uint16_t) const;
	void debug_console_print() const;
};

