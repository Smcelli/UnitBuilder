#pragma once
#include "Unit_Full_Fates.h"
#include <Rolodex.h>


class Unit_Corrin : public Unit_Full_Fates
{
    int16_t boon_ = -1, bane_ = -1;

public:
    Unit_Corrin(int16_t boon, int16_t bane, int16_t talent, bool gender=0);
    void set_talent(int16_t talent);
    void set_boon(int16_t boon);
    void set_bane(int16_t bane);
    void remove_boon();
    void remove_bane();

protected:
    StatBlock_Fates hp_boon();
    StatBlock_Fates hp_bane();
    StatBlock_Fates str_boon();
    StatBlock_Fates str_bane();
    StatBlock_Fates mag_boon();
    StatBlock_Fates mag_bane();
    StatBlock_Fates skl_boon();
    StatBlock_Fates skl_bane();
    StatBlock_Fates spd_boon();
    StatBlock_Fates spd_bane();
    StatBlock_Fates lck_boon();
    StatBlock_Fates lck_bane();
    StatBlock_Fates def_boon();
    StatBlock_Fates def_bane();
    StatBlock_Fates res_boon();
    StatBlock_Fates res_bane();
};

