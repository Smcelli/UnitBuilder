#pragma once
#include <cstdint>

namespace fe_fates {
	const uint16_t BLOCK_SIZE = 8;
	enum Stat_name { hp, str, mag, skl, spd, lck, def, res };
	const uint16_t UNIQ_JOB_ID = 4, HOSH_JOB_ID = 64, NOHR_JOB_ID = 256;
	enum Job_id_unique {
		nohr_prince = 0,
		hoshido_nob,
		nohr_nob,
		songstress = 3,
		kitsune = 6,
		ninetails,
		wolfskin = 9,
		wolfssegner
	};
	enum Job_id_hosh {
		samurai			= 0,
		sword_master,
		master_arms_sam,
		villager		= 3,
		master_arms_vil,
		merchant_vil,
		apothecary		= 6,
		merchant_apo,
		mechanist_apo,
		ninja			= 9,
		mechanist_nin,
		master_nin,
		oni_savage		= 12,
		oni_chief,
		blacksmith,
		spear_fighter	= 15,
		spear_master,
		basara_spr,
		diviner			= 18,
		basara_div,
		onmyoji_div,
		monk			= 21,
		onmyoji_mon,
		great_master,
		shrine_maiden	= 24,
		onmyoji_shr,
		priestess,
		sky_knight		= 27,
		falcon_knight,
		kinshi_sky,
		archer			= 30,
		kinshi_arc,
		sniper
	};
	enum Job_id_nohr {
		cavalier		= 0,
		paladin,
		great_knight_cav,
		knight			= 3,
		great_knight_kni,
		general,
		fighter			= 6,
		berserker,
		hero_fight,
		mercenary		= 9,
		hero_merc,
		bow_knight_merc,
		outlaw			=12,
		bow_knight_out,
		adventurer,
		wyvern_rider	=15,
		wyvern_lord,
		malig_knight,
		dark_mage		=18,
		sorcerer,
		dark_knight,
		troubadour		=21,
		startegist,
		maid_butler
	};
}