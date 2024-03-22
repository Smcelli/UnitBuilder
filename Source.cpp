#include "StatBlock_Fates.h"
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	StatBlock_Fates stats;
	stats.debug_print();
}