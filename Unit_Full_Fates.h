#pragma once
#include "Unit_Base_Fates.h"
#include "Unit_Plan_Fates.h"
#include "fe_fates_namespace.h"
#include "Job_Fates.h"
#include "Rolodex.h"

class Unit_Full_Fates
{
private:
    Unit_Base_Fates base;
    Unit_Plan_Fates plan;
    Job_Fates* current_job;
    Unit_Full_Fates* pal, * spouse;
    void generate_base();
protected:

public:
    Unit_Full_Fates(uint16_t id, Rolodex* table);
    void remove_friend();
    void remove_spouse();
    void add_spouse(Unit_Full_Fates* s);
    void debug_console_print() const;
    void promote_unit(int);
};

