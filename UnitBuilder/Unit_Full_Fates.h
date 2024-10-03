#pragma once
#include <Rolodex.h>
#include <Unit_Plan_Fates.h>
#include <Unit_Active.h>
#include <set>


class Unit_Full_Fates
{

public:
    Unit_Full_Fates(int16_t id);
    void add_pal(Unit_Full_Fates* p) { pal = p; };
    void add_spouse(Unit_Full_Fates* s) { spouse = s; };
    void debug_console_print() const;
    std::unordered_set<int16_t> get_valid_jobs() const;

    int16_t get_inhereted_job(Unit_Full_Fates* partner, std::unordered_set<int16_t>& job_set) const;
    

protected:
    Unit_Base_Fates base;
    Unit_Plan_Fates plan;
    Job_Fates* current_job;
    Unit_Full_Fates* pal = NULL, * spouse = NULL;
    std::vector<Unit_Active> actives = {};
};