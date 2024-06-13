#pragma once
#include <cstdint>
#include <unordered_map>
#include <string>
#include <iostream>

namespace fe_fates {

	const uint16_t BLOCK_SIZE = 8,
		ID_JOB = 256,
		ID_SKILL_JOB = 512,
		ID_UNIT = 1024,
		ID_SKILL_UNIT = 2048;


	inline uint16_t id_type(uint16_t id, uint16_t type) {
		if (id < type)
			return id + type;
		if (id > type * 2)
			return 0;
		return id;
	};
	inline uint16_t id_job(uint16_t id) {
		id_type(id, ID_JOB);
	};
	inline uint16_t id_skill_job(uint16_t id) {
		id_type(id, ID_SKILL_JOB);
	};
	inline uint16_t id_unit(uint16_t id) {
		id_type(id, ID_UNIT);
	};
	inline uint16_t id_skill_unit(uint16_t id) {
		id_type(id, ID_SKILL_UNIT);
	};

	enum Stat_places : uint16_t { hp, str, mag, skl, spd, lck, def, res, mov };
	const std::unordered_map<uint16_t, std::string> fates_names {
		{hp, "Max Health"},
		{str, "Strength"},
		{mag, "Magic"},
		{skl, "Skill"},
		{spd, "Speed"},
		{lck, "Luck"},
		{def, "Defence"},
		{res, "Resistance"},
		{mov, "Movement"}
	};

	const enum Skill_requirements : uint16_t {
		unpromo_first = 1,
		unpromo_second = 10,
		promo_first = 25,
		promo_second = 35
	};

	const enum Job_ids : uint16_t {
		debug_job,
		nohr_prince = 4,
		hoshido_nob,
		nohr_nob,
		songstress = 8,
		kitsune = 12,
		ninetails,
		wolfskin = 16,
		wolfssegner,
		end_unique_jobs = 20,

		start_common_jobs = 24,
		samurai			= 28,
		sword_master,
		master_arms_sam,
		villager		= 32,
		master_arms_vil,
		merchant_vil,
		apothecary		= 36,
		merchant_apo,
		mechanist_apo,
		ninja			= 40,
		mechanist_nin,
		master_nin,
		oni_savage		= 44,
		oni_chief,
		blacksmith,
		spear_fighter	= 48,
		spear_master,
		basara_spr,
		diviner			= 52,
		basara_div,
		onmyoji_div,
		monk			= 56,
		onmyoji_mon,
		great_master,
		shrine_maiden	= 60,
		onmyoji_shr,
		priestess,
		sky_knight		= 64,
		falcon_knight,
		kinshi_sky,
		archer			= 68,
		kinshi_arc,
		sniper,

		cavalier		= 72,
		paladin,
		great_knight_cav,
		knight			= 76,
		great_knight_kni,
		general,
		fighter			= 80,
		berserker,
		hero_fight,
		mercenary		= 84,
		hero_merc,
		bow_knight_merc,
		outlaw			= 88,
		bow_knight_out,
		adventurer,
		wyvern_rider	= 72,
		wyvern_lord,
		malig_knight,
		dark_mage		= 76,
		sorcerer,
		dark_knight,
		troubadour		= 80,
		strategist,
		maid_butler
	};

	const enum Unit_ids : uint16_t {
		debug_unit,

		avatar,
		azura,
		felicia_1,
		felicia_2,
		jacob_1,
		jacob_2,
		kaze_h,
		kaze_n,
		silas_h,
		silas_n,
		shura_h,
		shura_n,
		izana,
		mozu,

		rinkah,
		sakura,
		hana,
		subaki,
		saizo,
		orochi,
		hinoka,
		azama,
		setsuna,
		hayato,
		oboro,
		hinata,
		takumi,
		kagero,
		reina,
		kaden,
		ryoma,
		scarlet,
		yukimura,

		gunter,
		elise,
		arthur,
		effie,
		odin,
		niles,
		nyx,
		camilla,
		selena,
		beruka,
		laslow,
		peri,
		benny,
		charlotte,
		leo,
		keaton,
		xander,
		flora,

		kana,
		shigure,
		dwyer,
		sophie,
		midori,

		shiro,
		kiragi,
		asugi,
		selkie,
		hisame,
		mitama,
		caeldori,
		rhajat,

		siegbert,
		forrest,
		ignatius,
		velouria,
		percy,
		ophelia,
		soleil,
		nina,

		end_units
	};
}