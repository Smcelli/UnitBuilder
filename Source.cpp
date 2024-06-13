#include "fe_fates_namespace.h"
#include "Rolodex.h"
#include "Unit_Full_Fates.h"
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	Rolodex table;
	table.debug_console_print();
	Unit_Full_Fates unit(hayato + ID_UNIT, &table);
	unit.debug_console_print();
	Unit_Full_Fates ryoma_unit{ID_UNIT + ryoma, &table};
	ryoma_unit.debug_console_print();
}