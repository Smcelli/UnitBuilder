#pragma once
#include <random>
#include <iostream>
#include <string>

const int STAT_MAX = 99;

class Stat_FE
{
public:
	std::string name;
	unsigned short int stat, growth, max;

	virtual ~Stat_FE() = default;
	Stat_FE() = default;
	Stat_FE(const Stat_FE&);
	friend void swap(Stat_FE&, Stat_FE&);
	Stat_FE& operator=(Stat_FE);
	Stat_FE(Stat_FE&& source) noexcept;

	Stat_FE(const std::string& name,
		const unsigned short int	stat = 0,
		const unsigned short int	growth = 0,
		const unsigned short int	max = 0)
		: name(name),
		stat(stat),
		growth(growth),
		max(max) {};
	
	
	Stat_FE& operator ++ ();
	Stat_FE& operator += (const Stat_FE&);
	Stat_FE& operator += (const unsigned short int);
	Stat_FE& operator -= (const Stat_FE&);
	Stat_FE& operator -= (const unsigned short int);

	int roll_stat_up(unsigned short int = 0);
	int roll_growth() const;
	int is_less_than_max() const;
	int is_less_than_max(const unsigned short int) const;
	void print_To_Console() const;
};