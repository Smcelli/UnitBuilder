#pragma once
#include <random>
#include <iostream>
#include <string>

const int STAT_MAX = 99;
struct Stat_FE
{
	std::string name;
	int stat_, growth_, max_;
	Stat_FE();
	Stat_FE(const Stat_FE&);
	Stat_FE(Stat_FE&&) noexcept;
	Stat_FE(const std::string&);
	Stat_FE(const std::string&, 
		const int stat, 
		const int growth, 
		const int max);
	~Stat_FE();
	friend void swap(Stat_FE&, Stat_FE&);
	Stat_FE& operator ++ ();
	Stat_FE& operator += (const Stat_FE&);
	Stat_FE& operator += (const int);
	Stat_FE& operator -= (const Stat_FE&);
	Stat_FE& operator -= (const int);
	Stat_FE& operator = (Stat_FE);
	int roll_Stat_Up() const;
	int is_less_than_max(const int) const;
	int stat() const;
	void print_To_Console() const;
};

