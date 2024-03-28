#include "Ability_List_FE.h"
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	Ability_List_Fates abilities;
	abilities.populate_Fates();
	abilities.debug_console_print();
}