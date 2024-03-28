#include "fe_fates_namespace.h"
#include "Ability_List_FE.h"
#include <stdlib.h>
#include <time.h>

void populate_Fates(Ability_List_Fates*);

int main() {
	srand(time(NULL));
	Ability_List_Fates abilities;
	populate_Fates(&abilities);
	abilities.debug_console_print();
}

void populate_Fates(Ability_List_Fates* list)
{
	using namespace fe_fates;
	list->add_skill(Ability_Job_Fates{ 
		static_cast<std::string>("default"), 
		static_cast<uint16_t>(0) , 
		static_cast<uint16_t>(0) });
	list->add_skill(Ability_Job_Fates{ 
		static_cast<std::string>("elbow room"), 
		static_cast<uint16_t>(cavalier*2) , 
		static_cast<uint16_t>(1) });
	list->add_skill(Ability_Job_Fates{ 
		static_cast<std::string>("shelter"),
		static_cast<uint16_t>(cavalier*2+1) ,
		static_cast<uint16_t>(10) });
	list->add_skill(Ability_Job_Fates{
		static_cast<std::string>("defender"),
		static_cast<uint16_t>(paladin*2) ,
		static_cast<uint16_t>(25) });
	list->add_skill(Ability_Job_Fates{
		static_cast<std::string>("aegis"),
		static_cast<uint16_t>(paladin*2+1) ,
		static_cast<uint16_t>(35) });
}