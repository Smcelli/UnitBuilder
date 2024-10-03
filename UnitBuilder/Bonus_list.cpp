#include "Bonus_list.h"

Bonus_list::Bonus_list(std::array<int16_t, fe_fates::BLOCK_SIZE> char_pairup_bonus_input)
{
	size_t index = 1;
	for (auto element : char_pairup_bonus_input) {
		if (element == 0)
			continue;
		else if (index == fe_fates::BLOCK_SIZE) {
			index = fe_fates::ids::move;
			list_.push_back(bonus{ element, index });
			break;
		}
		else {
			list_.push_back(bonus{ element, index});
		}
		index++;
	}
}

Bonus_list& Bonus_list::operator=(Bonus_list temp)
{
	std::swap(*this, temp);
	return *this;
}
