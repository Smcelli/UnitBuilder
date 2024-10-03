#pragma once
#include <string>
#include <iostream>
#include <unordered_set>
#include <fe_fates_namespace.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using std::unordered_map, std::pair, std::unordered_set;

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
	void emplace(int16_t unit, int type, unordered_set<int16_t> supports);
	unordered_set<int16_t> get_marraiges(int16_t) const;
	unordered_set<int16_t> get_friends(int16_t) const;
	pair<int16_t, int16_t> get_children(int16_t) const;
	pair<int16_t, int16_t> get_parents(int16_t) const;
	void debug_console_print() const;

private:
	unordered_map<int16_t, unordered_set< int16_t>> marriages;
	unordered_map<int16_t, unordered_set< int16_t>> friends;
	unordered_map<int16_t, pair<int16_t, int16_t>> children;
	unordered_map<int16_t, pair<int16_t, int16_t>> parents;
	void emplace(int16_t unit1, int16_t unit2, unordered_map<int16_t, unordered_set<int16_t>>* type);
	void emplace_primary_child(int16_t, int16_t);	
};

