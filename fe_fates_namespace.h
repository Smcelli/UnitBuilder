#pragma once
#include <cstdint>

namespace fe_fates {
	const uint16_t BLOCK_SIZE = 8, COMMON_JOB = 16, JOB_SKILL = 128;
	enum Stat_name : uint16_t { hp, str, mag, skl, spd, lck, def, res };

	enum Skill_requirements : uint16_t {
		unpromo_first = 1,
		unpromo_second = 10,
		promo_first = 25,
		promo_second = 35
	};

	enum Job_name : uint16_t {
		debug_job,
		nohr_prince = 3,
		hoshido_nob,
		nohr_nob,
		songstress = 6,
		kitsune = 9,
		ninetails,
		wolfskin = 12,
		wolfssegner,

		samurai			= 18,
		sword_master,
		master_arms_sam,
		villager		= 21,
		master_arms_vil,
		merchant_vil,
		apothecary		= 24,
		merchant_apo,
		mechanist_apo,
		ninja			= 27,
		mechanist_nin,
		master_nin,
		oni_savage		= 30,
		oni_chief,
		blacksmith,
		spear_fighter	= 33,
		spear_master,
		basara_spr,
		diviner			= 36,
		basara_div,
		onmyoji_div,
		monk			= 39,
		onmyoji_mon,
		great_master,
		shrine_maiden	= 42,
		onmyoji_shr,
		priestess,
		sky_knight		= 45,
		falcon_knight,
		kinshi_sky,
		archer			= 48,
		kinshi_arc,
		sniper,

		cavalier		= 51,
		paladin,
		great_knight_cav,
		knight			= 54,
		great_knight_kni,
		general,
		fighter			= 57,
		berserker,
		hero_fight,
		mercenary		= 60,
		hero_merc,
		bow_knight_merc,
		outlaw			= 63,
		bow_knight_out,
		adventurer,
		wyvern_rider	= 66,
		wyvern_lord,
		malig_knight,
		dark_mage		= 69,
		sorcerer,
		dark_knight,
		troubadour		= 72,
		startegist,
		maid_butler
	};
}