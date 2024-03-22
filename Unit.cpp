#include "Unit.h"

Unit::Unit()
{
	U_Stat hp, str, mag, skl, spd, lck, def, res;
}

void Unit::debug_print()
{
	size_t i = 0;
	while (i <= res) {
		statblock[i].print();
		std::cout << std::endl;
		i++;
	}
}
