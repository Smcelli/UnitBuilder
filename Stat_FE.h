#pragma once
#include <random>
#include <iostream>
#include <string>

const int STAT_MAX = 99;

class Stat_FE
{
public:
	std::string name;
	uint16_t stat, growth, max;

	virtual ~Stat_FE() = default;
	Stat_FE() = default;
	Stat_FE(const Stat_FE&);
	friend void swap(Stat_FE&, Stat_FE&);
	Stat_FE& operator=(Stat_FE);
	Stat_FE(Stat_FE&& source) noexcept;

	Stat_FE(const std::string& name,
		uint16_t	stat = 0,
		uint16_t	growth = 0,
		uint16_t	max = 0)
		: name(name),
		stat(stat),
		growth(growth),
		max(max) {};
	
	
	Stat_FE& operator ++ ();
	Stat_FE& operator += (const Stat_FE&);
	Stat_FE& operator += (const uint16_t);
	Stat_FE& operator -= (const Stat_FE&);
	Stat_FE& operator -= (const uint16_t);

	int roll_stat_up(uint16_t = 0);
	int roll_growth() const;
	int is_less_than_max() const;
	int is_less_than_max(const uint16_t) const;
	void print_To_Console() const;
};