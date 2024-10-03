#include "Unit_Corrin.h"


/*
typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,0,0,0,0,0},
		arr_b{0,0,0,0,0,0,0,0},
		arr_b{0,0,0,0,0,0,0,0}
		};
*/


Unit_Corrin::Unit_Corrin(int16_t boon, int16_t bane, int16_t talent, bool gender)
	:Unit_Full_Fates(gender ? fe_fates::ids::avatar_m : fe_fates::ids::avatar_f)
{
	set_talent(talent);
	set_boon(boon);
	set_bane(bane);
}

void Unit_Corrin::set_talent(int16_t talent)
{
	base.set_jobs(std::vector<int16_t>{fe_fates::id_job(fe_fates::ids::nohr_prince), fe_fates::id_job(talent)});
}

void Unit_Corrin::set_boon(int16_t boon)
{
	using namespace fe_fates::ids;
	if (boon = bane_)
		return;
	remove_boon();
	switch (boon) {
	case hp:
		base.add_block(hp_boon());
		boon_ = hp;
		break;
	case str:
		base.add_block(str_boon());
		boon_ = str;
		break;
	case mag:
		base.add_block(mag_boon());
		boon_ = mag;
		break;
	case skl:
		base.add_block(skl_boon());
		boon_ = skl;
		break;
	case spd:
		base.add_block(spd_boon());
		boon_ = spd;
		break;
	case lck:
		base.add_block(lck_boon());
		boon_ = lck;
		break;
	case def:
		base.add_block(def_boon());
		boon_ = def;
		break;
	case res:
		base.add_block(res_boon());
		boon_ = res;
		break;
	}
}

void Unit_Corrin::remove_boon()
{
	using namespace fe_fates::ids;
	if (boon_ != -1) {
		switch (boon_) {
		case hp:
			base.subtract_block(hp_boon());
			break;
		case str:
			base.subtract_block(str_boon());
			break;
		case mag:
			base.subtract_block(mag_boon());
			break;
		case skl:
			base.subtract_block(skl_boon());
			break;
		case spd:
			base.subtract_block(spd_boon());
			break;
		case lck:
			base.subtract_block(lck_boon());
			break;
		case def:
			base.subtract_block(def_boon());
			break;
		case res:
			base.subtract_block(res_boon());
			break;
		}
		boon_ = -1;
	}
}

void Unit_Corrin::set_bane(int16_t bane)
{
	if (bane == boon_)
		return;
	using namespace fe_fates::ids;
	remove_bane();
	switch (bane) {
	case hp:
		base.add_block(hp_bane());
		bane_ = hp;
		break;
	case str:
		base.add_block(str_bane());
		bane_ = str;
		break;
	case mag:
		base.add_block(mag_bane());
		bane_ = mag;
		break;
	case skl:
		base.add_block(skl_bane());
		bane_ = skl;
		break;
	case spd:
		base.add_block(spd_bane());
		bane_ = spd;
		break;
	case lck:
		base.add_block(lck_bane());
		bane_ = lck;
		break;
	case def:
		base.add_block(def_bane());
		bane_ = def;
		break;
	case res:
		base.add_block(res_bane());
		bane_ = res;
		break;
	}
}

void Unit_Corrin::remove_bane()
{
	using namespace fe_fates::ids;
	if (bane_ != -1) {
		switch (bane_) {
		case hp:
			base.subtract_block(hp_bane());
			break;
		case str:
			base.subtract_block(str_bane());
			break;
		case mag:
			base.subtract_block(mag_bane());
			break;
		case skl:
			base.subtract_block(skl_bane());
			break;
		case spd:
			base.subtract_block(spd_bane());
			break;
		case lck:
			base.subtract_block(lck_bane());
			break;
		case def:
			base.subtract_block(def_bane());
			break;
		case res:
			base.subtract_block(res_bane());
			break;
		}
		bane_ = -1;
	}
}

StatBlock_Fates Unit_Corrin::hp_boon()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{3,0,0,0,0,0,0,0},
		arr_b{15,0,0,0,0,0,0,0},
		arr_b{0,1,1,0,0,2,2,2}
	};
}

StatBlock_Fates Unit_Corrin::hp_bane()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{-2,0,0,0,0,0,0,0},
		arr_b{-10,0,0,0,0,0,-5,-5},
		arr_b{0,-1,-1,0,0,-1,-1,-1}
	};
}

StatBlock_Fates Unit_Corrin::str_boon()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,2,0,0,0,0,0,0},
		arr_b{0,15,0,0,0,0,0,0},
		arr_b{0,4,0,2,0,0,2,0}
	};
}

StatBlock_Fates Unit_Corrin::str_bane()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,-1,0,0,0,0,0,0},
		arr_b{0,-10,0,-5,0,0,-5,0},
		arr_b{0,-3,0,-1,0,0,-1,0}
	};
}

StatBlock_Fates Unit_Corrin::mag_boon()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,3,0,0,0,0,0},
		arr_b{0,0,20,0,0,0,0,0},
		arr_b{0,0,4,0,2,0,0,2}
	};
}

StatBlock_Fates Unit_Corrin::mag_bane()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,-2,0,0,0,0,0},
		arr_b{0,0,-15,0,-5,0,0,-5},
		arr_b{0,0,-3,0,-1,0,0,-1}
	};
}

StatBlock_Fates Unit_Corrin::skl_boon()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,3,0,0,0,0},
		arr_b{0,0,0,25,0,0,0,0},
		arr_b{0,2,0,4,0,0,2,0}
	};
}

StatBlock_Fates Unit_Corrin::skl_bane()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,-2,0,0,0,0},
		arr_b{0,0 - 5,0,-20,0,0,-5,0},
		arr_b{0,-1,0,-3,0,0,-1,0}
	};
}

StatBlock_Fates Unit_Corrin::spd_boon()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,0,2,0,0,0},
		arr_b{0,0,0,0,15,0,0,0},
		arr_b{0,0,0,2,4,2,0,0}
	};
}

StatBlock_Fates Unit_Corrin::spd_bane()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,0,-1,0,0,0},
		arr_b{0,0,0,-5,-10,-5,0,0},
		arr_b{0,0,0,-1,-3,-1,0,0}
	};
}

StatBlock_Fates Unit_Corrin::lck_boon()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,0,0,3,0,0},
		arr_b{0,0,0,0,0,25,0,0},
		arr_b{0,2,2,0,0,4,0,0}
	};
}

StatBlock_Fates Unit_Corrin::lck_bane()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,0,0,-2,0,0},
		arr_b{0,-5,-5,0,0,-20,0,0},
		arr_b{0,-1,-1,0,0,-3,0,0}
	};
}

StatBlock_Fates Unit_Corrin::def_boon()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,0,0,0,1,0},
		arr_b{0,0,0,0,0,0,10,0},
		arr_b{0,0,0,0,0,2,4,2}
	};
}

StatBlock_Fates Unit_Corrin::def_bane()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,0,0,0,-1,0},
		arr_b{0,0,0,0,0,-5,-10,-5},
		arr_b{0,0,0,0,0,-1,-3,-1}
	};
}

StatBlock_Fates Unit_Corrin::res_boon()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,0,0,0,0,1},
		arr_b{0,0,0,0,0,0,0,10},
		arr_b{0,0,2,0,2,0,0,4}
	};
}

StatBlock_Fates Unit_Corrin::res_bane()
{
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	return StatBlock_Fates{
		arr_b{0,0,0,0,0,0,0,-1},
		arr_b{0,0,-5,0,-5,0,0,-10},
		arr_b{0,0,-1,0,-1,0,0,-3}
	};
}