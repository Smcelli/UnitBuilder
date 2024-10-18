#pragma once
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <vector>

namespace fe_fates {

	const int16_t STAT_SIZE = 3,
		BLOCK_SIZE = 8,
		ID_STAT = 128,
		ID_JOB = 256,
		ID_SKILL_JOB = 512,
		ID_UNIT = 1024,
		ID_SKILL_UNIT = 2048;
	
	int16_t id_skill_job(int16_t id, int16_t value = 0);
	int16_t id_type(int16_t id, int16_t type);
	int16_t id_job(int16_t id);
	int16_t id_unit(int16_t id);
	int16_t id_skill_unit(int16_t id);
	int16_t id_job_base(int16_t id);
	int16_t id_job_is_promo(int16_t id);
	int16_t id_job_get_genderless(int16_t id);
	int16_t id_job_get_gendered(int16_t id, bool female = 0);
	int16_t id_get_type(int16_t id);
	bool id_job_is_gendered(int16_t);
	bool in_level_range(int16_t level);

	int16_t get_parallel_job(int16_t job);

	struct Job_list_fates {
		std::vector<int16_t> jobs;
		int16_t pal_job, spouse_job;
	};

	namespace ids {
		enum Stat_id : size_t { hp, str, mag, skl, spd, lck, def, res, 
			move = 24 };

		enum Stat_type : size_t {stat_val, growth, max};

		enum Bonus_source : int16_t {backpack, job, ability, weapon};

		enum Skill_requirement : int16_t {
			unpromoted = 0,
			promoted = 1,
			unpromo_first = 1,
			unpromo_second = 10,
			promo_first = 25,
			promo_second = 35
		};

		enum Job_ability_id : int16_t {
			debug_job_ability = ID_SKILL_JOB,

			nobility,
			dragon_fang,
			draconic_hex,
			nohrian_trust,
			dragon_ward,
			hoshidan_unity,

			odd_shaped,
			evenhanded,
			beastbane,
			better_odds,
			even_better,
			grisly_wound,

			luck_4,
			inspiring_song,
			voice_of_peace,
			foreign_princess,

			
			
			elbow_room,
			shelter,
			defender,
			aegis,
			luna,
			armored_blow,
			defence_2,
			natural_cover,
			wary_fighter,
			pavise,
			hp_5,
			gamble,
			rally_strength,
			axefaire,
			good_fortune,
			strong_riposte,
			sol,
			axebreaker,
			rally_skill,
			shurikenbreaker,
			locktouch,
			movement_1,
			lucky_seven,
			pass,
			strength_2,
			lunge,
			rally_defence,
			swordbreaker,
			savage_blow,
			trample,
			heartseeker,
			malefic_aura,
			vengeance,
			bowbreaker,
			seal_magic,
			lifetaker,
			resistance_2,
			gentilhomme,
			demoiselle,
			rally_resistance,
			inspiration,
			live_to_serve,
			tomebreaker,
			

			
			duelists_blow,
			vantage, 
			astra,
			swordfaire,
			seal_strength,
			life_and_death,
			seal_resistance,
			shove,
			deathblow,
			counter,
			salvage_blow,
			lance_breaker,
			seal_defence,
			swap_ab,
			seal_speed,
			lancefaire,
			rend_heaven,
			quixotic,
			magic_2,
			future_sight,
			rally_magic,
			tomefaire,
			miracle,
			rally_luck,
			renewal,
			countermagic,
			darting_blow,
			camaraderie,
			rally_speed,
			warding_blow,
			air_superiority,
			amaterasu,
			skill_2,
			quick_draw,
			certain_blow,
			bowfaire,
			poison_strike,
			lethality,
			shurikenfaire,
			golembane,
			replicate,
			potent_potion,
			quick_salve,
			profiteer,
			spendthrift,
			aptitude,
			underdog,
			

			debug_job_ability_end
		};

		enum Job_id : int16_t {
			debug_job = ID_JOB,

			nohr_prince = ID_JOB + 4,
			hoshido_nob,
			nohr_nob,
			songstress = ID_JOB + 8,
			kitsune = ID_JOB + 12,
			ninetails,
			wolfskin = ID_JOB + 16,
			wolfssegner,
			villager = ID_JOB + 20,
			master_arms_vil,
			merchant_vil,
			debug_job_unique_end = ID_JOB + 24,

			debug_job_common_start = ID_JOB + 28,
			samurai = ID_JOB + 32,
			sword_master,
			master_arms_sam,
			apothecary = ID_JOB + 36,
			merchant_apo,
			mechanist_apo,
			ninja = ID_JOB + 40,
			mechanist_nin,
			master_nin,
			oni_savage = ID_JOB + 44,
			oni_chief,
			blacksmith,
			spear_fighter = ID_JOB + 48,
			spear_master,
			basara_spr,
			diviner = ID_JOB + 52,
			basara_div,
			onmyoji_div,

			sky_knight = ID_JOB + 64,
			falcon_knight,
			kinshi_sky,
			archer = ID_JOB + 68,
			kinshi_arc,
			sniper,

			cavalier = ID_JOB + 72,
			paladin,
			great_knight_cav,
			knight = ID_JOB + 76,
			great_knight_kni,
			general,
			fighter = ID_JOB + 80,
			berserker,
			hero_fight,
			mercenary = ID_JOB + 84,
			hero_merc,
			bow_knight_merc,
			outlaw = ID_JOB + 88,
			bow_knight_out,
			adventurer,
			wyvern_rider = ID_JOB + 92,
			wyvern_lord,
			malig_knight,
			dark_mage = ID_JOB + 96,
			sorcerer,
			dark_knight,
			debug_job_common_end = ID_JOB + 100,

			debug_job_gendered= ID_JOB + 104,
			monk_maiden = ID_JOB + 108,
			monk = ID_JOB + 112,
			onmyoji_mon,
			great_master,
			shrine_maiden = ID_JOB + 116,
			onmyoji_shr,
			priestess,
			troubadour = ID_JOB + 120,
			troubadour_m = ID_JOB + 124,
			strategist_m,
			butler,
			troubadour_f = ID_JOB + 128,
			strategist_f,
			maid,
			debug_job_gendered_end = ID_JOB + 124,


			debug_job_end
		};

		enum Unit_id : int16_t {
			debug_unit = ID_UNIT,

			debug_unit_avatar,
			avatar_m,
			avatar_f,
			debug_unit_avatar_end,

			debug_unit_shared_start,
			azura,
			felicia_1,
			felicia_2,
			jacob_1,
			jacob_2,
			silas_h,
			silas_n,
			shura_h,
			shura_n,
			izana,
			mozu,
			debug_unit_shared_end,

			debug_unit_hosh_start,
			kaze_h,
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
			debug_unit_hosh_end,

			debug_unit_nohr_start,
			gunter,
			kaze_n,
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
			debug_unit_nohr_end,

			debug_unit_children_shared_start,
			kana_m,
			kana_f,
			shigure,
			dwyer,
			sophie,
			midori,
			debug_unit_children_shared_end,

			debug_unit_children_hosh_start,
			shiro,
			kiragi,
			asugi,
			selkie,
			hisame,
			mitama,
			caeldori,
			rhajat,
			debug_unit_children_hosh_end,

			debug_unit_children_nohr_start,
			siegbert,
			forrest,
			ignatius,
			velouria,
			percy,
			ophelia,
			soleil,
			nina,
			debug_unit_children_nohr_end,

			debug_unit_end
		};
	}
}