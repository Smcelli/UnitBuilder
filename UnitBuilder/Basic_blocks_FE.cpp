#include <Basic_blocks_FE.h>

void Support_Table_FE::emplace(Support_FE temp)
{
	switch (temp.type) {
	case 1: 
		emplace(temp.unit1, temp.unit2, &marriages);
		emplace(temp.unit2, temp.unit1, &marriages);
		break;
	case 2:
		emplace(temp.unit1, temp.unit2, &friends);
		emplace(temp.unit1, temp.unit2, &friends);
		break;
	case 3:
		emplace_primary_child(temp.unit1, temp.unit2);
	}
}

void Support_Table_FE::emplace(int16_t unit, int type, unordered_set<int16_t> supports)
{
	using fe_fates::ID_UNIT;
	switch (type) {
	case 1:
		for (auto i : supports) {
			emplace(unit+ID_UNIT, i+ID_UNIT, &marriages);
			emplace(i+ID_UNIT, unit+ID_UNIT, &marriages);
		}
		break;
	case 2:
		for (auto i : supports) {
			emplace(unit+ID_UNIT, i+ID_UNIT, &friends);
			emplace(i+ID_UNIT, unit+ID_UNIT, &friends);
		}
		break;
	}
}

unordered_set<int16_t> Support_Table_FE::get_marraiges(int16_t unit) const
{
	auto target = marriages.find(unit);
	return target->second;
}

unordered_set<int16_t> Support_Table_FE::get_friends(int16_t unit) const
{
	auto target = friends.find(unit);
	return target->second;
}

pair<int16_t, int16_t> Support_Table_FE::get_children(int16_t unit) const
{
	auto target = children.find(unit);
	return target->second;
}

pair<int16_t, int16_t> Support_Table_FE::get_parents(int16_t unit) const
{
	auto target = children.find(unit);
	return target->second;
}

void Support_Table_FE::debug_console_print() const
{
	using std::cout, std::endl;
	cout << " SUPPORT TABLE";
	for (auto i : marriages) {
		cout << endl<< " supports marriage id: " << i.first << "  possible partners: ";
			for (auto y : i.second) {
				cout << y << "  ";
			}
	}
	for (auto i : friends) {
		cout << endl<< " supports friend id: " << i.first << "  possible friends: ";
		for (auto y : i.second) {
			cout << y << "  ";
		}
	}
	for (auto i : children) {
		cout << endl << " supports children id:" << i.first << " possible children: "
			<< i.second.first << ", " << i.second.second;
	}
	for (auto i : parents) {
		cout << endl << " supports parents id: " << i.first << " possible parents: "
			<< i.second.first << ", " << i.second.second;
	}

}

void Support_Table_FE::emplace(int16_t unit1, int16_t unit2, unordered_map<int16_t, unordered_set<int16_t>>* type) {
	unordered_map< int16_t, unordered_set<int16_t>>::iterator target = type->find(unit1);
	if (target == type->end()) {
		type->try_emplace(unit1, std::unordered_set<int16_t> {unit2});
	}
	else {
		target->second.insert(unit2);
	}
}

void Support_Table_FE::emplace_primary_child(int16_t parent, int16_t child) {
	unordered_map< int16_t, pair<int16_t, int16_t>>::iterator target = children.find(parent);
	if (target == children.end()) {
		children.try_emplace(parent, std::pair<int16_t, int16_t> {child, 0});
	}
	
	target = parents.find(child);
	if (target == parents.end()) {
		parents.try_emplace(child, std::pair<int16_t, int16_t> {parent, 0});
	}
}
