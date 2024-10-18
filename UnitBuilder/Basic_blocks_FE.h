#pragma once
#include <string>
#include <iostream>
#include <unordered_set>
#include <fe_fates_namespace.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>


struct Weapon_Rank_FE
{
	std::string name;
	int16_t rank, id;
	auto compare_id(const Weapon_Rank_FE left, const Weapon_Rank_FE right) {
		if (left.id < right.id) return		std::strong_ordering::less;
		if (left.id > right.id) return		std::strong_ordering::greater;
		return								std::strong_ordering::equal;
	}
};

struct Support_FE {
	int16_t unit1 = 0, unit2 = 0, type = 0;
	Support_FE(int16_t u1, int16_t u2, int t)
	: unit1(u1),
	unit2(u2),
	type(static_cast<int16_t>(t)){}
	Support_FE(int16_t u1, int16_t u2, int16_t t) 
	:unit1(u1),
	unit2(u2),
	type(t){}
};

struct Support_Table_FE {
	
	void emplace(Support_FE);
	void emplace(int16_t unit, int type, std::unordered_set<int16_t> supports);
	std::unordered_set<int16_t> get_marraiges(int16_t) const;
	std::unordered_set<int16_t> get_friends(int16_t) const;
	std::pair<int16_t, int16_t> get_children(int16_t) const;
	std::pair<int16_t, int16_t> get_parents(int16_t) const;
	void debug_console_print() const;

private:
	std::unordered_map<int16_t, std::unordered_set< int16_t>> marriages;
	std::unordered_map<int16_t, std::unordered_set< int16_t>> friends;
	std::unordered_map<int16_t, std::pair<int16_t, int16_t>> children;
	std::unordered_map<int16_t, std::pair<int16_t, int16_t>> parents;
	void emplace(int16_t unit1, int16_t unit2, std::unordered_map<int16_t, std::unordered_set<int16_t>>* type);
	void emplace_primary_child(int16_t, int16_t);	
};

