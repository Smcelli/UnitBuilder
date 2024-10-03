#pragma once
#include <fe_fates_namespace.h>
#include <vector>
#include <array>

class Bonus_list
{

	typedef std::pair<int16_t, size_t> bonus;
	friend class Rolodex;
public:
	Bonus_list(std::array<int16_t, fe_fates::BLOCK_SIZE>);


	~Bonus_list() = default;
	Bonus_list() : list_({}) {};
	Bonus_list(const Bonus_list& source) :list_(source.list_) {};
	friend void swap(Bonus_list& left, Bonus_list& right) { std::swap(left.list_, right.list_); };
	Bonus_list& operator= (Bonus_list);
	Bonus_list(Bonus_list&& source) noexcept { std::swap(*this, source); };
protected:
	std::vector<bonus> list_;
};

