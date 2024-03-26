#pragma once
#include <random>
#include <iostream>
#include <string>

const int STAT_MAX = 99;

struct Weapon_Rank_FE
{
	std::string name;
	unsigned short int rank, id;
	auto compare_id(const Weapon_Rank_FE left, const Weapon_Rank_FE right) {
		if (left.id < right.id) return		std::strong_ordering::less;
		if (left.id > right.id) return		std::strong_ordering::greater;
		return								std::strong_ordering::equal;
	}
};

struct Ability_FE
{
	std::string name, description;
	unsigned short int id, requirement;
	auto compare_req(const Ability_FE left, const Ability_FE right) {
		if(left.requirement < right.requirement) return		std::strong_ordering::less;
		if (left.requirement > right.requirement) return	std::strong_ordering::greater;
		return												std::strong_ordering::equal;
	}
	auto compare_id(const Ability_FE left, const Ability_FE right) {
		if (left.id < right.id) return	std::strong_ordering::less;
		if (left.id > right.id) return	std::strong_ordering::greater;
		return							std::strong_ordering::equal;
	}
};

struct Stat_FE
{
	std::string name;
	unsigned short int stat, growth, max;
	Stat_FE();
	Stat_FE(const Stat_FE&);
	Stat_FE(Stat_FE&&) noexcept;
	Stat_FE(const std::string&);
	Stat_FE(const std::string&, 
		const unsigned short int stat,
		const unsigned short int growth,
		const unsigned short int max);
	~Stat_FE();
	friend void swap(Stat_FE&, Stat_FE&);
	Stat_FE& operator ++ ();
	Stat_FE& operator += (const Stat_FE&);
	Stat_FE& operator += (const unsigned short int);
	Stat_FE& operator -= (const Stat_FE&);
	Stat_FE& operator -= (const unsigned short int);
	Stat_FE& operator = (Stat_FE);
	int roll_stat_up(unsigned short int = 0);
	int roll_growth() const;
	int is_less_than_mac() const;
	int is_less_than_max(const unsigned short int) const;
	void print_To_Console() const;
};