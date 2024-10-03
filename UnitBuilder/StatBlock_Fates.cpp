#include <StatBlock_Fates.h>

StatBlock_Fates::arr_b StatBlock_Fates::get_stats() const
{
	arr_b result;
	for (int16_t i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i][stat_val];
	}
	return result;
}

StatBlock_Fates::arr_b StatBlock_Fates::get_growths() const
{
	arr_b result;
	for (int16_t i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i][growth];
	}
	return result;
}

StatBlock_Fates::arr_b StatBlock_Fates::get_maxs() const
{
	arr_b result;
	for (auto i = 0; i < BLOCK_SIZE; i++) {
		result[i] = block_[i][max];
	}
	return result;
}

StatBlock_Fates& StatBlock_Fates::add_block(const StatBlock_Fates& other)
{
	if (this->block_.size() != other.block_.size()) {
		std::cout << " DEBUG Stat_block add_block : size does not match ";
		return *this;
	}
	for (int i = 0; i < BLOCK_SIZE; i++) {
		this->block_[i] += other.block_[i];
	}
	return *this;
}

StatBlock_Fates& StatBlock_Fates::add_block(const StatBlock_Fates* other)
{
	return add_block(*other);
}

StatBlock_Fates& StatBlock_Fates::subtract_block(const StatBlock_Fates& other)
{
	if (this->block_.size() != other.block_.size()) {
		std::cout << " DEBUG Stat_block subtract_block : size does not match ";
		return *this;
	}
	for (int i = 0; i < BLOCK_SIZE; i++) {
		this->block_[i] -= other.block_[i];
	}
	return *this;
}

StatBlock_Fates& StatBlock_Fates::subtract_block(const StatBlock_Fates* other)
{
	return subtract_block(*other);
}

int16_t& StatBlock_Fates::operator[](const size_t location)
{
	if (location < fe_fates::ids::move) {
		auto coords = to_indexes(location);
		return block_[coords.first][coords.second];
	}
	else {
		std::cout << "DEBUG Statblock[] index out of bounds" << std::endl;
		return block_[0][0];
	}
}

int16_t StatBlock_Fates::operator[](const size_t location) const
{
	if (location < fe_fates::ids::move) {
		auto coords = to_indexes(location);
		return block_[coords.first][coords.second];
	}
	else {
		std::cout << "DEBUG Statblock[] index out of bounds" << std::endl;
		return block_[0][0];
	}
}

StatBlock_Fates& StatBlock_Fates::operator+=(std::pair<int16_t,size_t> bonus)
{
	(*this)[bonus.second] += bonus.first;
	return *this;
}

std::pair<size_t, size_t> StatBlock_Fates::to_indexes(size_t location) const
{
	return std::pair <size_t, size_t> {location % fe_fates::BLOCK_SIZE, location / fe_fates::BLOCK_SIZE};
}

void StatBlock_Fates::prep_average()
{
	for (auto element : block_) {
		element[stat_val] *= 100;
	}
}

void StatBlock_Fates::levelup_average(int16_t count)
{
	if (count < 0) {
		std::cout << std::endl << "ERROR: statblock levelup_average overflow count < 0" << std::endl;
		return;
	}
	for (auto element : block_) {
		element.levelup_average(count);
	}
}

void StatBlock_Fates::levelup(int16_t count)
{
	if (count < 0) {
		std::cout << std::endl << "ERROR: statblock levelup overflow count < 0" << std::endl;
		return;
	}
	for (auto element : block_) {
		element.levelup_random(count);
	}
}

void StatBlock_Fates::serenes_forest(std::array<int16_t, BLOCK_SIZE> stats)
{
	for (int i = 0; i < BLOCK_SIZE-1; i++) {
		block_[i] -= stats[i];
	}
}

void StatBlock_Fates::debug_console_print() const
{
	std::string l = " | ";
	std::array<std::string, BLOCK_SIZE> names{ "HP", "STR", "MAG", "SKL", "SPD", "LCK", "DEF", "RES" };

	std::cout << std::endl;
	for (auto element : names) {
		std::cout << l << std::setw(4) << element;
	}
	std::cout << l << std::endl;

	auto temp = get_stats();
	for (auto element : temp) {
		std::cout << l << std::setw(4) << element;
	}
	std::cout << l << std::endl;

	temp = get_growths();
	for (auto element : temp) {
		std::cout << l << std::setw(4) << element;
	}

	std::cout << l << std::endl;
	temp = get_maxs();
	for (auto element : temp) {
		std::cout << l << std::setw(4) << element;
	}
	std::cout << l << std::endl;
}


StatBlock_Fates& StatBlock_Fates::operator=(StatBlock_Fates source)
{
	swap(*this, source);
	return *this;
}

StatBlock_Fates::StatBlock_Fates(arr_b stats, arr_b growths, arr_b maxs) {

	for (auto i = 0; i < BLOCK_SIZE; i++) {
		block_[i] = Stat_FE{ stats[i], growths[i],maxs[i] };
	}
}