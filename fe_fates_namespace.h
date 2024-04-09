#pragma once
#include <cstdint>
#include <unordered_map>
#include <string>
#include <iostream>

namespace fe_fates {
	const uint16_t BLOCK_SIZE = 8,
		ID_STAT = 4,
		ID_JOB_UNIQUE = 16,
		ID_JOB_COMMON = 32,
		ID_SKILL_JOB = 128,
		ID_UNIT = 256,
		ID_SKILL_UNIT = 512;


	enum Stat_places : uint16_t { hp, str, mag, skl, spd, lck, def, res, mov };
	const std::unordered_map<uint16_t, std::string> fates_names {
		{hp  + ID_STAT, "Max Health"},
		{str + ID_STAT, "Strength"},
		{mag + ID_STAT, "Magic"},
		{skl + ID_STAT, "Skill"},
		{spd + ID_STAT, "Speed"},
		{lck + ID_STAT, "Luck"},
		{def + ID_STAT, "Defence"},
		{res + ID_STAT, "Resistance"},
		{mov + ID_STAT, "Movement"}
	};

	const enum Skill_requirements : uint16_t {
		unpromo_first = 1,
		unpromo_second = 10,
		promo_first = 25,
		promo_second = 35
	};

	const enum Job_ids : uint16_t {
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