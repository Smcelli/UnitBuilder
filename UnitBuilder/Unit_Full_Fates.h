#pragma once
#include <Rolodex.h>
#include <Unit_Plan_Fates.h>
#include <Unit_Active.h>
#include <set>


class Unit_Full_Fates
{

public:
    Unit_Full_Fates(int16_t id);

    void add_pal(Unit_Base_Fates* p) { pal = p; };
    void add_spouse(Unit_Base_Fates* s) { spouse = s; };

    fe_fates::Job_list_fates get_valid_jobs(int16_t avatar_job = 0);
    void debug_console_print() const;



protected:
    Unit_Base_Fates base;
    Unit_Plan_Fates plan;
    Job_Fates* current_job;
    Unit_Base_Fates* pal = NULL, * spouse = NULL;
};