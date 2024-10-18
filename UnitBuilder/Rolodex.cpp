#include <Rolodex.h>

Rolodex::Rolodex()
{
	populate_fates_jobs();
	populate_supports_h();
	populate_fates_units();
	populate_fates_abilities();
}

Unit_Base_Fates Rolodex::get_unit(int16_t id) const
{
	const auto target = units.find(id);
	if (target == units.end()) {
		return Unit_Base_Fates();
	}
	return Unit_Base_Fates(target->second);
}

Job_Fates* Rolodex::get_job_ptr(int16_t job_id)
{
	auto it = jobs.find(job_id);
	if (it == jobs.end())
		return NULL;
	return &it->second;
}


void Rolodex::add_ability(Ability_Job_Fates ability, int16_t job_id, int16_t job_id_dup, int16_t job_id_third)
{

	auto it = common_table.get_job_ptr(job_id);
	if (it)
		it->add_ability(ability);
	else
		std::cout << "ERROR : FAILED TO ADD ABILITY " << ability.id << " " << ability.name << " JOB NOT FOUND" << std::endl;

	if (job_id_dup) 
		add_ability(ability, job_id_dup);
	if (job_id_third)
		add_ability(ability, job_id_third);
}

void Rolodex::add_unit(Unit_Base_Fates unit, bool sf = 0)
{
	auto it = units.try_emplace(unit.id_, unit).first;
	if (sf)
		serenes_forest(it);
	return;
}

void Rolodex::add_job(Job_Fates job, int16_t alt_job =0, int16_t alt_alt_job =0)
{
	jobs.try_emplace(job.id_, job);
	if (alt_job) {
		add_job(alt_job, job);
	}
	if (alt_alt_job) {
		add_job(alt_alt_job, job);
	}
}

void Rolodex::add_job(int16_t duplicate, Job_Fates temp)
{
	temp.id_ = fe_fates::id_job(duplicate);
	jobs.try_emplace(temp.id_, temp);
}

void Rolodex::populate_fates_abilities()
{
	using namespace fe_fates::ids;
	using fe_fates::id_skill_job, std::string;
	//debug abilities//
	{
		add_ability(Ability_Job_Fates{
				string("debug ability"),
				debug_job_ability,
				unpromo_first },
				debug_job);
	};

	//Unique Job Skills//
	{
		add_ability(Ability_Job_Fates{
				string("nobility"),
				nobility,
				unpromo_first },
				nohr_prince);
		add_ability(Ability_Job_Fates{
				string("Dragon Fang"),
				dragon_fang,
				unpromo_second},
				nohr_prince);

		add_ability(Ability_Job_Fates{
				"Draconic Hex",
				draconic_hex,
				promo_first },
				nohr_nob);
		add_ability(Ability_Job_Fates{
				"Nohrian Trust",
				nohrian_trust,
				promo_second },
				nohr_nob);

		add_ability(Ability_Job_Fates{
				"Dragon Ward",
				dragon_ward,
				promo_first },
				hoshido_nob);
		add_ability(Ability_Job_Fates{
				"Hoshidan Unity",
				hoshidan_unity,
				promo_second},
				hoshido_nob);

		add_ability(Ability_Job_Fates{
				string("Luck +4"),
				luck_4,
				unpromo_first },
				songstress);
		add_ability(Ability_Job_Fates{
				string("Inspiring Song"),
				inspiring_song,
				unpromo_second },
				songstress);
		add_ability(Ability_Job_Fates{
				string("Voice of Peace"),
				voice_of_peace,
				(promo_first) },
				songstress);
		add_ability(Ability_Job_Fates{
				string("Foreign Princess"),
				foreign_princess,
				(promo_second) },
				songstress);
		
		add_ability(Ability_Job_Fates{ 
				string("Odd Shaped"),
				odd_shaped,
				unpromo_first },
				wolfskin);
		add_ability(Ability_Job_Fates{
				string("Beastbane"),
				beastbane,
				(unpromo_second) },
				wolfskin, kitsune);

		add_ability(Ability_Job_Fates{
				string("Better Odds"),
				better_odds,
				(promo_first) },
				wolfssegner);
		add_ability(Ability_Job_Fates{
				string("Grisly Wound"),
				grisly_wound,
				(promo_second) },
				wolfssegner, ninetails);

		add_ability(Ability_Job_Fates{
				string("Evenhanded"),
				evenhanded,
				(unpromo_first) },
				kitsune);
		add_ability(Ability_Job_Fates{
				string("Even Better"),
				even_better,
				(promo_first) },
				ninetails);
	};


	//Nohr Jobs Abilities//
	{
		add_ability(Ability_Job_Fates{
				string("Elbow Room"),
				elbow_room,
				(unpromo_first) },
				cavalier);
		add_ability(Ability_Job_Fates{
				string("Shelter"),
				shelter,
				(unpromo_second) },
				cavalier);

		add_ability(Ability_Job_Fates{
				string("Defender"),
				defender,
				(promo_first) },
				paladin);
		add_ability(Ability_Job_Fates{
				string("Aegis"),
				aegis,
				(promo_second) },
				paladin);

		add_ability(Ability_Job_Fates{
				string("Luna"),
				luna,
				(promo_first) },
				great_knight_cav, great_knight_kni);
		add_ability(Ability_Job_Fates{
				string("Armored Blow"),
				armored_blow,
				(promo_second) },
				great_knight_cav, great_knight_kni);

		add_ability(Ability_Job_Fates{
				string("Defence +2"),
				defence_2,
				(unpromo_first) },
				knight);
		add_ability(Ability_Job_Fates{
				string("Natural Cover"),
				natural_cover,
				(unpromo_second) },
				knight);

		add_ability(Ability_Job_Fates{
				string("Wary Fighter"),
				wary_fighter,
				(promo_first) },
				general);
		add_ability(Ability_Job_Fates{
				string("Pavise"),
				pavise,
				(promo_second) },
				general);

		add_ability(Ability_Job_Fates{
				string("HP +5"),
				hp_5,
				(unpromo_first) }, 
				fighter);
		add_ability(Ability_Job_Fates{
				string("Gamble"),
				gamble,
				(unpromo_second) },
				fighter);

		add_ability(Ability_Job_Fates{
				string("Rally Strength"),
				rally_strength,
				(promo_first) },
				berserker);
		add_ability(Ability_Job_Fates{
				string("Axefaire"),
				axefaire,
				(promo_second) },
				berserker);

		add_ability(Ability_Job_Fates{
				string("Good Fortune"),
				good_fortune,
				(unpromo_first) },
				mercenary);
		add_ability(Ability_Job_Fates{
				string("Strong Riposte"),
				strong_riposte,
				(unpromo_second) },
				mercenary);

		add_ability(Ability_Job_Fates{
				string("Sol"),
				sol,
				(promo_first) }, 
				hero_fight, hero_merc);
		add_ability(Ability_Job_Fates{
				string("Axebreaker"),
				axebreaker,
				(promo_second) },
				hero_fight, hero_merc);

		add_ability(Ability_Job_Fates{
				string("Rally Skill"),
				rally_skill,
				(promo_first) },
				bow_knight_merc, bow_knight_out);
		add_ability(Ability_Job_Fates{
				string("Shurikenbreaker"),
				shurikenbreaker,
				(promo_second) },
				bow_knight_merc, bow_knight_out);

		add_ability(Ability_Job_Fates{
				string("Locktouch"),
				locktouch,
				(unpromo_first) }, 
				outlaw, ninja);
		add_ability(Ability_Job_Fates{
				string("Movement +1"),
				movement_1,
				(unpromo_second) },
				outlaw);

		add_ability(Ability_Job_Fates{
				string("Lucky 7"),
				lucky_seven,
				(promo_first) },
				adventurer);
		add_ability(Ability_Job_Fates{
				string("Pass"),
				pass,
				(promo_second) },
				adventurer);

		add_ability(Ability_Job_Fates{
				string("Strength +2"),
				strength_2,
				(unpromo_first) },
				wyvern_rider);
		add_ability(Ability_Job_Fates{
				string("Lunge"),
				lunge,
				(unpromo_second) },
				wyvern_rider);

		add_ability(Ability_Job_Fates{
				string("Rally Defence"),
				rally_defence,
				(promo_first) },
				wyvern_lord);
		add_ability(Ability_Job_Fates{
				string("Swordbreaker"),
				swordbreaker,
				(promo_second) },
				wyvern_lord);

		add_ability(Ability_Job_Fates{
				string("Savage Blow"),
				savage_blow,
				(promo_first) },
				malig_knight);
		add_ability(Ability_Job_Fates{
				string("Trample"),
				trample,
				(promo_second) },
				malig_knight);

		add_ability(Ability_Job_Fates{
				string("HeartSeeker"),
				heartseeker,
				(unpromo_first) },
				dark_mage);
		add_ability(Ability_Job_Fates{
				string("Malefic Aura"),
				malefic_aura,
				(unpromo_second) },
				dark_knight);

		add_ability(Ability_Job_Fates{
				string("Vengeance"),
				vengeance,
				(promo_first) },
				sorcerer);
		add_ability(Ability_Job_Fates{
				string("Bowbreaker"),
				bowbreaker,
				(promo_second) },
				sorcerer);

		add_ability(Ability_Job_Fates{
				string("Seal Magic"),
				seal_magic,
				(promo_first) },
				dark_knight);
		add_ability(Ability_Job_Fates{
				string("Lifetaker"),
				lifetaker,
				(promo_second) },
				dark_knight);

		add_ability(Ability_Job_Fates{
				string("Resistance +2"),
				id_skill_job(troubadour_f),
				(unpromo_first) },
				troubadour_f, troubadour_m);
		add_ability(Ability_Job_Fates{
				string("Gentilhomme"),
				gentilhomme,
				(unpromo_second) },
				troubadour_m);
		add_ability(Ability_Job_Fates{
				string("Demoiselle"),
				demoiselle,
				(unpromo_second) },
				troubadour_f);

		add_ability(Ability_Job_Fates{
				string("Rally Resistance"),
				rally_resistance,
				(promo_first) },
				strategist_f, strategist_m);
		add_ability(Ability_Job_Fates{
				string("Inspiration"),
				inspiration,
				(promo_second) },
				strategist_f, strategist_m);
		add_ability(Ability_Job_Fates{
				string("Live to Serve"),
				live_to_serve,
				(promo_first) },
				maid, butler);
		add_ability(Ability_Job_Fates{
				string("Tomebreaker"),
				tomebreaker,
				(promo_second) },
				maid, butler);
	};


	//Hosh Job Abilities//
	{
		add_ability(Ability_Job_Fates{
				string("Duelist's Blow"),
				duelists_blow,
				(unpromo_first) },
				samurai);
		add_ability(Ability_Job_Fates{
				string("Vantage"),
				vantage,
				(unpromo_second) },
				samurai);

		add_ability(Ability_Job_Fates{
				string("Astra "),
				astra,
				(promo_first) },
				sword_master);
		add_ability(Ability_Job_Fates{
				string("Swordfaire"),
				swordfaire,
				(promo_second) },
				sword_master);

		add_ability(Ability_Job_Fates{
				string("Seal Strength"),
				seal_strength,
				(promo_first) },
				master_arms_sam, master_arms_vil);
		add_ability(Ability_Job_Fates{
				string("Life and Death"),
				life_and_death,
				(promo_second) },
				master_arms_sam, master_arms_vil);

		add_ability(Ability_Job_Fates{
				string("Seal Resistance"),
				seal_resistance,
				(unpromo_first) },
				oni_savage);
		add_ability(Ability_Job_Fates{
				string("Shove"),
				shove,
				(unpromo_second) },
				oni_savage);

		add_ability(Ability_Job_Fates{
				string("Death Blow"),
				deathblow,
				(promo_first) },
				oni_chief);
		add_ability(Ability_Job_Fates{
				string("Counter"),
				counter,
				(promo_second) },
				oni_chief);

		add_ability(Ability_Job_Fates{
				string("Salvage Blow"),
				salvage_blow,
				(promo_first) },
				blacksmith);
		add_ability(Ability_Job_Fates{
				string("Lancebreaker"),
				lance_breaker,
				(promo_second) },
				blacksmith);

		add_ability(Ability_Job_Fates{
				string("Seal Defence"),
				seal_defence,
				(unpromo_first) },
				spear_fighter);
		add_ability(Ability_Job_Fates{
				string("Swap"),
				swap_ab,
				(unpromo_second) },
				spear_fighter);

		add_ability(Ability_Job_Fates{
				string("Seal Speed"),
				seal_speed,
				(promo_first) },
				spear_master);
		add_ability(Ability_Job_Fates{
				string("Lancefaire"),
				lancefaire,
				(promo_second) },
				spear_master);

		add_ability(Ability_Job_Fates{
				string("Rend Heavern"),
				rend_heaven,
				(promo_first) },
				basara_div, basara_spr);
		add_ability(Ability_Job_Fates{
				string("Quixotic"),
				quixotic,
				(promo_second) },
				basara_div, basara_spr);

		add_ability(Ability_Job_Fates{
				string("Magic +2"),
				magic_2,
				(unpromo_first) },
				diviner);
		add_ability(Ability_Job_Fates{
				string("Future Sight"),
				future_sight,
				(unpromo_second) },
				diviner);

		add_ability(Ability_Job_Fates{
				string("Rally Magic"),
				rally_magic,
				(promo_first) },
				onmyoji_div, onmyoji_mon, onmyoji_shr);
		add_ability(Ability_Job_Fates{
				string("Tomefaire"),
				tomefaire,
				(promo_second) },
				onmyoji_div, onmyoji_mon, onmyoji_shr);

		add_ability(Ability_Job_Fates{
				string("Miracle"),
				miracle,
				(unpromo_first) },
				monk, monk_maiden);
		add_ability(Ability_Job_Fates{
				string("Rally Luck"),
				rally_luck,
				(unpromo_second) },
				monk, monk_maiden);

		add_ability(Ability_Job_Fates{
				string("Renewal"),
				renewal,
				(promo_first) },
				great_master, priestess);
		add_ability(Ability_Job_Fates{
				string("Countermagic"),
				countermagic,
				(promo_second) },
				great_master, priestess);

		add_ability(Ability_Job_Fates{
				string("Darting Blow"),
				darting_blow,
				(unpromo_first) },
				sky_knight);
		add_ability(Ability_Job_Fates{
				string("Camaraderie"),
				camaraderie,
				(unpromo_second) },
				sky_knight);

		add_ability(Ability_Job_Fates{
				string("Rally Speed"),
				rally_speed,
				(promo_first) },
				falcon_knight);
		add_ability(Ability_Job_Fates{
				string("Warding Blow"),
				warding_blow,
				(promo_second) },
				falcon_knight);

		add_ability(Ability_Job_Fates{
				string("Air Superiority"),
				air_superiority,
				(promo_first) },
				kinshi_arc, kinshi_sky);
		add_ability(Ability_Job_Fates{
				string("Amaterasu"),
				amaterasu,
				(promo_second) },
				kinshi_arc, kinshi_sky);

		add_ability(Ability_Job_Fates{
				string("Skill +2"),
				skill_2,
				(unpromo_first) },
				archer);
		add_ability(Ability_Job_Fates{
				string("Quick Draw"),
				quick_draw,
				(unpromo_second) },
				archer);

		add_ability(Ability_Job_Fates{
				string("Certain Blow"),
				certain_blow,
				(promo_first) },
				sniper);
		add_ability(Ability_Job_Fates{
				string("Bowfaire"),
				bowfaire,
				(promo_second) },
				sniper);

		add_ability(Ability_Job_Fates{
				string("Poison Strike"),
				poison_strike,
				(unpromo_second) },
				ninja);

		add_ability(Ability_Job_Fates{
				string("Lethality"),
				lethality,
				(promo_first) },
				master_nin);
		add_ability(Ability_Job_Fates{
				string("Shurikenfaire"),
				shurikenfaire,
				(promo_second) },
				master_nin);

		add_ability(Ability_Job_Fates{
				string("Golembane"),
				golembane,
				(promo_first) },
				mechanist_apo, mechanist_nin);
		add_ability(Ability_Job_Fates{
				string("Replicate"),
				replicate,
				(promo_second) },
				mechanist_apo, mechanist_nin);

		add_ability(Ability_Job_Fates{
				string("Potent Potion"),
				potent_potion,
				(unpromo_first) },
				apothecary);
		add_ability(Ability_Job_Fates{
				string("Quick Salve"),
				quick_salve,
				(unpromo_second) },
				apothecary);

		add_ability(Ability_Job_Fates{
				string("Profiteer"),
				profiteer,
				(promo_first) },
				merchant_apo, merchant_vil);
		add_ability(Ability_Job_Fates{
				string("Spendthrift"),
				spendthrift,
				(promo_second) },
				merchant_apo, merchant_vil);

		add_ability(Ability_Job_Fates{
				string("Aptitudes"),
				aptitude,
				(unpromo_first) },
				villager);
		add_ability(Ability_Job_Fates{
				string("Underdog"),
				underdog,
				(unpromo_second) },
				villager);
		};	

	/*personal Hosh*/
	/*
	{
		add_ability(
			Ability_FE{
				string("Supportive"),
				(avatar_m) });
		add_ability(
			Ability_FE{
				string("Supportive"),
				(avatar_f) });
		add_ability(
			Ability_FE{
				string("Devoted Partner"),
				(felicia_1) });
		add_ability(
			Ability_FE{
				string("Devoted Partner"),
				(felicia_2) });
		add_ability(
			Ability_FE{
				string("Evasive Partner"),
				(jacob_1) });
		add_ability(
			Ability_FE{
				string("Evasive Partner"),
				(jacob_2) });
		add_ability(
			Ability_FE{
				string("Miraculous Save"),
				(kaze_h) });
		add_ability(
			Ability_FE{
				string("Healing Descant"),
				(azura) });
		add_ability(
			Ability_FE{
				string("Vow of Friendship"),
				(silas_h) });
		add_ability(
			Ability_FE{
				string("Highwayman"),
				(shura_h) });
		add_ability(
			Ability_FE{
				string("Peacebringer"),
				(izana) });
		add_ability(
			Ability_FE{
				string("Forager"),
				(mozu) });

		add_ability(
			Ability_FE{
				string("Fiery Blood"),
				(rinkah) });
		add_ability(
			Ability_FE{
				string("Quiet Strength"),
				(sakura) });
		add_ability(
			Ability_FE{
				string("Fearsome Blow"),
				(hana) });
		add_ability(
			Ability_FE{
				string("Perfectionist"),
				(subaki) });
		add_ability(
			Ability_FE{
				string("Pyrotechnics"),
				(saizo) });
		add_ability(
			Ability_FE{
				string("Capture"),
				(orochi) });
		add_ability(
			Ability_FE{
				string("Rallying Cry"),
				(hinoka) });
		add_ability(
			Ability_FE{
				string("Devine Retribution"),
				(azama) });
		add_ability(
			Ability_FE{
				string("Optimist"),
				(setsuna) });
		add_ability(
			Ability_FE{
				string("Pride"),
				id_skill_unit(hayato) });
		add_ability(
			Ability_FE{
				string("Nohr Enmity"),
				id_skill_unit(oboro) });
		add_ability(
			Ability_FE{
				string("Triple Threat"),
				id_skill_unit(hinata) });
		add_ability(
			Ability_FE{
				string("Competitive"),
				id_skill_unit(takumi) });
		add_ability(
			Ability_FE{
				string("Shiruken Mastery"),
				id_skill_unit(kagero) });
		add_ability(
			Ability_FE{
				string("Morbid Celebration"),
				id_skill_unit(reina) });
		add_ability(
			Ability_FE{
				string("Reciprocity"),
				id_skill_unit(kaden) });
		add_ability(
			Ability_FE{
				string("Bushido"),
				id_skill_unit(ryoma) });
		add_ability(
			Ability_FE{
				string("In Extremis"),
				id_skill_unit(scarlet) });
		add_ability(
			Ability_FE{
				string("Perspicacious"),
				id_skill_unit(yukimura) });
	};
	*/
}

void Rolodex::populate_fates_jobs() {
	using namespace fe_fates::ids;
	using fe_fates::id_job;
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	typedef std::vector<int16_t> ability_list;
	
	/* template */
	/*
	add_job(Job_Fates{ "",
			id, move,
			ability_list{},
			Bonus_list{{}},
			StatBlock_Fates{
				arr_b {},
				arr_b {},
				arr_b {}
			} });
	*/

	add_job(Job_Fates{ "debug",
		debug_job, 5,
		ability_list{debug_job_ability},
		Bonus_list {{0}},
		StatBlock_Fates{
			arr_b {0},
			arr_b {0},
			arr_b {0},
		}});
	add_job(Job_Fates{ "debug promo",
		debug_job + 1, 6,
		ability_list{debug_job_ability},
		Bonus_list {{0}},
		StatBlock_Fates{
		arr_b {0},
		arr_b {0},
		arr_b {0}
		}});
	

	/* Unique Jobs */
	{
		add_job(Job_Fates{ "Nohr Prince",
			nohr_prince, 5,
			Bonus_list {{2,0,1,1,2,0,0,0}},
			StatBlock_Fates{
			arr_b {17,7,3,4,5,2,5,2},
			arr_b {15,15,10,10,10,10,10,5},
			arr_b {40,23,17,19,21,22,21,19}
			}});
		
		add_job(Job_Fates{ "Nohr Noble",
			nohr_nob, 6,
			Bonus_list {{2,2,1,1,0,0,2,0}},
			StatBlock_Fates{
				arr_b {18,8,6,4,7,2,6,6},
				arr_b {15,10,15,5,15,5,5,15},
				arr_b {60,32,31,28,32,27,29,32}
			} });
		add_job(Job_Fates{ "Hoshido Noble",
			hoshido_nob, 6,
			Bonus_list{{}},
			StatBlock_Fates{
				arr_b {19,10,4,5,6,4,7,3},
				arr_b {15,15,10,10,10,10,15,0},
				arr_b {60,34,28,29,30,33,31,28}
			} });
	}

	/* Hosh Jobs */
	{
		add_job(Job_Fates{ "Samurai",
			samurai, 5,
			Bonus_list {{0, 0, 0, 4, 2, 0, 0, 0}},
			StatBlock_Fates{
				arr_b {17, 4, 0, 5, 8, 3, 3, 3},
				arr_b {10, 10, 0, 15, 20, 15, 0, 10},
				arr_b {40, 20, 16, 23, 25, 24, 18, 20}
			} });
		add_job(Job_Fates{ "SwordMaster",
			sword_master, 6,
			Bonus_list {{0,0,0,5,3,0,0,0}},
			StatBlock_Fates{
				arr_b {18,6,2,7,11,4,5,5},
				arr_b {10,10,5,15,20,15,0,10},
				arr_b {55,30,28,32,35,33,27,31}
			} });
		add_job(Job_Fates{ "Master of Arms",
			master_arms_sam, 6,
			Bonus_list {{2,0,2,2,0,2,0,0}},
			StatBlock_Fates{
				arr_b {20,8,0,6,9,3,7,3},
				arr_b {20,15,0,10,10,10,10,0},
				arr_b {65,33,25,30,30,31,31,28}
			} }, master_arms_vil);
		add_job(Job_Fates{ "Oni Savage",
			oni_savage, 5,
			Bonus_list {{4,0,0,0,0,2,0,0}},
			StatBlock_Fates{
				arr_b {18,6,1,2,5,0,7,1},
				arr_b {20,20,10,0,10,0,20,0},
				arr_b {45,24,19,16,20,17,23,18}
			} });
		add_job(Job_Fates{ "Oni Chieftain",
			oni_chief, 6,
			Bonus_list {{4,0,0,0,0,4,0,0}},
			StatBlock_Fates{
				arr_b {19,9,5,2,7,0,10,5},
				arr_b {10,20,15,0,10,0,20,5},
				arr_b {60,34,28,25,30,25,36,31}
			} });
		add_job(Job_Fates{ "Blacksmith",
			blacksmith, 6,
			Bonus_list {{3,0,2,0,0,3,0,0}},
			StatBlock_Fates{
				arr_b {21,8,0,9,8,3,8,2},
				arr_b {20,15,0,15,10,5,15,0},
				arr_b {65,33,25,32,31,30,32,27}
			} });
		add_job(Job_Fates{ "Spear Fighter",
			spear_fighter, 5,
			Bonus_list {{2,0,2,2,0,0,0,0}},
			StatBlock_Fates{
				arr_b {17,6,0,6,6,2,5,2},
				arr_b {15,15,0,15,15,5,10,5},
				arr_b {40,22,15,23,22,21,22,21}
			} });
		add_job(Job_Fates{ "Spear Master",
			spear_master, 6,
			Bonus_list {{3,0,3,2,0,0,0,0}},
			StatBlock_Fates{
				arr_b {18,9,0,8,8,3,7,3},
				arr_b {15,15,0,15,15,5,10,5},
				arr_b {60,34,25,33,32,29,30,29}
			} });
		add_job(Job_Fates{ "Basara",
			basara_div, 6,
			Bonus_list {{0,0,0,0,5,0,3,0}},
			StatBlock_Fates{
				arr_b {20,7,5,7,7,5,7,6},
				arr_b {20,10,10,10,10,15,5,10},
				arr_b {65,31,30,30,31,35,30,32}
			} }, basara_spr);
		add_job(Job_Fates{ "Diviner",
			diviner, 5,
			Bonus_list {{0,3,0,3,0,0,0,0}},
			StatBlock_Fates{
				arr_b {15,0,4,5,6,1,1,3},
				arr_b {0,5,15,10,15,5,0,10},
				arr_b {35,17,22,20,23,19,16,20}
			} });
		add_job(Job_Fates{ "Onmyoji",
			onmyoji_div, 6,
			Bonus_list {{0,4,0,4,0,0,0,0}},
			StatBlock_Fates{
				arr_b {16,0,7,6,7,2,3,6},
				arr_b {0,0,20,10,15,0,0,15},
				arr_b {45,25,33,31,32,27,25,31}
			} }, onmyoji_mon, onmyoji_shr);
		add_job(Job_Fates{ "Monk",
			monk, 5,
			Bonus_list {{0,2,0,0,2,0,2,0}},
			StatBlock_Fates{
				arr_b {16,0,3,5,5,4,2,5},
				arr_b {0,5,10,10,15,15,0,20},
				arr_b {35,18,21,20,22,23,17,24}
			} },shrine_maiden);
		add_job(Job_Fates{ "Great Master",
			great_master, 6,
			Bonus_list{{0,3,0,0,2,0,3,0}},
			StatBlock_Fates{
				arr_b {19,8,6,6,8,5,6,7},
				arr_b {10,15,5,5,15,15,10,10},
				arr_b {55,32,30,31,33,32,28,32}
			} });
		add_job(Job_Fates{ "Priestess",
			priestess, 6,
			Bonus_list{{0,3,0,0,2,0,3,0}},
			StatBlock_Fates{
				arr_b {19,6,7,6,9,5,5,8},
				arr_b {10,10,10,5,15,15,0,20},
				arr_b {50,29,32,30,33,34,26,34}
			} });
		add_job(Job_Fates{ "Sky Knight",
			sky_knight, 7,
			Bonus_list{{0,0,0,3,0,0,3,0}},
			StatBlock_Fates{
				arr_b {16,3,0,5,7,4,2,6},
				arr_b {0,10,0,10,15,20,0,20},
				arr_b {35,19,16,21,23,25,18,25}
			} });
		add_job(Job_Fates{ "Falcon Knight",
			falcon_knight, 8,
			Bonus_list{{0,0,0,3,0,0,3,1}},
			StatBlock_Fates{
				arr_b {18,5,4,6,10,5,5,9},
				arr_b {0,10,10,10,15,20,0,20},
				arr_b {55,28,27,30,34,35,27,35}
			} });
		add_job(Job_Fates{ "Kinshi Knight",
			kinshi_arc, 8,
			Bonus_list{{0,0,2,2,2,0,0,1}},
			StatBlock_Fates{
				arr_b {17,4,1,9,8,5,4,7},
				arr_b {0,5,0,15,15,15,0,15},
				arr_b {50,27,26,33,31,34,25,31}
			} }, kinshi_sky);
		add_job(Job_Fates{ "Archer",
			archer,5,
			Bonus_list{{2,0,2,2,0,0,0,0}},
			StatBlock_Fates{
				arr_b {17,5,0,7,5,2,4,1},
				arr_b {10,15,0,15,15,5,10,0},
				arr_b {40,21,15,23,21,20,20,17}
			} });
		add_job(Job_Fates{ "Sniper",
			sniper,6,
			Bonus_list{{2,0,3,3,0,0,0,0}},
			StatBlock_Fates{
				arr_b {19,7,0,10,9,3,6,2},
				arr_b {10,15,0,20,15,5,10,0},
				arr_b {55,31,25,35,33,30,31,28}
			} });
		add_job(Job_Fates{ "Ninja",
			ninja,5,
			Bonus_list{{0,0,1,3,0,0,0,1}},
			StatBlock_Fates{
				arr_b {16,3,0,8,8,1,3,3},
				arr_b {5,5,0,20,20,0,5,15},
				arr_b {35,17,15,25,25,18,19,20}
			} });
		add_job(Job_Fates{ "Master Ninja",
			master_nin,6,
			Bonus_list{{0,0,2,4,0,0,0,1}},
			StatBlock_Fates{
				arr_b {17,5,0,10,11,2,4,8},
				arr_b {5,5,0,20,20,0,5,20},
				arr_b {55,27,25,35,35,28,26,34}
			} });
		add_job(Job_Fates{ "Mechanist",
			mechanist_apo,7,
			Bonus_list{{2,0,2,0,0,2,2,0}},
			StatBlock_Fates{
				arr_b {18,7,0,9,7,2,6,6},
				arr_b {10,10,0,15,10,5,5,15},
				arr_b {60,30,25,33,30,30,31,31}
			} }, mechanist_nin);
		add_job(Job_Fates{ "Apothecary",
			apothecary,5,
			Bonus_list{{3,0,0,0,0,2,1,0}},
			StatBlock_Fates{
				arr_b {18,6,0,4,4,2,6,2},
				arr_b {20,20,0,10,10,5,10,5},
				arr_b {45,24,15,19,19,21,23,20}
			} });
		add_job(Job_Fates{ "Merchant",
			merchant_apo,6,
			Bonus_list{{3,0,0,0,0,3,2,0}},
			StatBlock_Fates{
				arr_b {20,8,0,6,5,4,8,5},
				arr_b {20,20,0,10,5,15,10,5},
				arr_b {65,33,25,29,28,32,33,30}
			} }, merchant_vil);
		add_job(Job_Fates{ "Villager",
			villager,5,
			Bonus_list{{0,0,3,0,3,0,0,0}},
			StatBlock_Fates{
				arr_b {17,5,0,4,5,3,4,0},
				arr_b {10,10,0,10,10,20,10,0},
				arr_b {35,19,15,19,19,22,18,15}
			} });
	};
	/* Nohr Jobs */
	{
		add_job(Job_Fates{ "Cavalier",
			cavalier,7,
			Bonus_list{{2,0,0,0,0,2,2,0}},
			StatBlock_Fates{
				arr_b {17,6,0,5,5,3,5,3},
				arr_b {10,15,0,10,10,15,10,5},
				arr_b {40, 22,15,21,20,24,22,21}
			} });
		add_job(Job_Fates{ "Paladin",
			paladin,8,
			Bonus_list{{2,0,0,0,0,2,2,1}},
			StatBlock_Fates{
				arr_b {19,8,1,7,7,4,7,6},
				arr_b {10,15,0,10,10,15,10,10},
				arr_b {60, 31,26,30,30,32,32,32}
			} });
		add_job(Job_Fates{ "Great Knight",
			great_knight_cav,7,
			Bonus_list{{2,0,0,0,0,4,0,1}},
			StatBlock_Fates{
				arr_b {21,10,0,6,6,3,10,2},
				arr_b {10,15,0,10,10,15,10,10},
				arr_b {65, 35,25,29,27,28,37,28}
			} },great_knight_kni);
	};
}

void Rolodex::populate_fates_units() {
	using namespace fe_fates::ids;
	using fe_fates::id_job, fe_fates::id_unit;
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	typedef std::vector < int16_t > jobs;
	bool sf = true; //bool for serene's forest base stat correction
		/*
		offsets
		Felicia, Jakob: 0
		Gunter: 5
		Camilla, Reina: 15
		Leo: 18
		*/

		/*template*//*
		add_unit(Unit_Base_Fates{ "",
			StatBlock_Fates {
				arr_b {},
				arr_b {},
				arr_b {}},
			Bonus_list {{}},
			jobs {},
		
			}, sf);
		*/



		/* Common Units */
	{
		add_unit(Unit_Base_Fates{ "Avatar", male,
			StatBlock_Fates {
				arr_b {19,7,4,7,6,5,6,2},
				arr_b {45,45,30,40,45,45,35,25},
				arr_b {0}},
			Bonus_list {},
			jobs {nohr_prince},
			avatar_m,1
			}, sf);
		add_unit(Unit_Base_Fates{ "Avatar",
			StatBlock_Fates {
				arr_b {19,7,4,7,6,5,6,2},
				arr_b {45,45,30,40,45,45,35,25},
				arr_b {0}},
			Bonus_list {},
			jobs {nohr_prince},
			avatar_f,1
			}, sf);
		add_unit(Unit_Base_Fates{ "Silas",
			StatBlock_Fates {
				arr_b {22, 11, 0, 9, 8, 7, 10, 5},
				arr_b {40, 45, 5, 50, 40, 40, 40, 25},
				arr_b {0, 1, 0, 2, 0, -1, 0, -1}},
			Bonus_list {},
			jobs {cavalier,mercenary},
			silas_h,6
			}, sf);
	};

	/* Hosh Units */
	{
		add_unit(Unit_Base_Fates{ "Ryoma",
			StatBlock_Fates {
				arr_b {36, 20, 2, 18, 24, 20, 16, 13},
				arr_b {50, 45, 0, 50, 45, 40, 35, 25},
				arr_b {0, 1, 0, 2, 1, 1, -2, -2}},
			Bonus_list {{}},
			jobs {sword_master,sky_knight},
			ryoma, 24
			}, sf);
		add_unit(Unit_Base_Fates{ "Rinkah",
			StatBlock_Fates {
				arr_b {20,8,2,6,8,5,10,3},
				arr_b {20,25,15,50,45,35,45,20},
				arr_b {0,-1,0,-2,1,0,2,0}},
			Bonus_list {{}},
			jobs {oni_savage,ninja},
			rinkah,4
			}, sf);
		add_unit(Unit_Base_Fates{ "Sakura",
			StatBlock_Fates {
				arr_b {16,3,6,5,7,9,5,7},
				arr_b {45,30,50,40,40,55,30,20},
				arr_b {0,0,2,-1,1,0,-1,0}},
			Bonus_list {{}},
			jobs {shrine_maiden,sky_knight},
			sakura,1
			}, sf);
		add_unit(Unit_Base_Fates{ "Hana",
			StatBlock_Fates {
				arr_b {20,9,0,11,11,5,6,9},
				arr_b {25,55,10,45,55,25,20,30},
				arr_b {0,1,0,1,2,-1,-3,1}},
			Bonus_list {{}},
			jobs {samurai,shrine_maiden},
			hana,4
			}, sf);
		add_unit(Unit_Base_Fates{ "Subaki",
			StatBlock_Fates {
				arr_b {22,8,0,13,10,7,9,10},
				arr_b {55,30,20,50,20,25,45,5},
				arr_b {0,-1,0,2,-2,-1,3,-1}},
			Bonus_list {{}},
			jobs {sky_knight,samurai},
			subaki,5
			}, sf);
		add_unit(Unit_Base_Fates{ "Saizo",
			StatBlock_Fates {
				arr_b {23,11,3,14,11,9,9,7},
				arr_b {40,50,45,60,30,55,45,10},
				arr_b {0,1,0,3,-2,0,1,-2}},
			Bonus_list {{}},
			jobs {ninja,samurai},
			saizo,7
			}, sf);
		add_unit(Unit_Base_Fates{ "Orochi",
			StatBlock_Fates {
				arr_b {20,0,9,11,7,6,5,10},
				arr_b {35,5,65,50,15,35,25,45},
				arr_b {0,0,3,2,-2,-1,-2,1}},
			Bonus_list {{}},
			jobs {diviner,apothecary},
			orochi,5
			}, sf);
		add_unit(Unit_Base_Fates{ "Hinoka",
			StatBlock_Fates {
				arr_b {23,9,4,13,16,12,9,15},
				arr_b {45,45,15,40,45,40,35,40},
				arr_b {0,1,-1,-1,1,0,-1,2}},
			Bonus_list {{}},
			jobs {sky_knight,spear_fighter},
			hinoka, 8
			}, sf);

		add_unit(Unit_Base_Fates{ "Azama",
			StatBlock_Fates {
				arr_b {24,9,7,9,10,12,10,8},
				arr_b {55,50,20,40,45,40,40,20},
				arr_b {0,2,-3,0,1,0,1,0}},
			Bonus_list {{}},
			jobs {monk,apothecary},
			azama,7
			}, sf);
		add_unit(Unit_Base_Fates{ "Setsuna",
			StatBlock_Fates {
				arr_b {19,8,0,9,10,6,5,3},
				arr_b {30,20,0,30,60,30,15,40},
				arr_b {0,0,0,1,3,-1,-1,-1}},
			Bonus_list {{}},
			jobs {archer,ninja},
			setsuna, 3
			}, sf);
		add_unit(Unit_Base_Fates{ "Hayato",
			StatBlock_Fates {
				arr_b {16,1,4,5,7,8,4,5},
				arr_b {50,30,40,30,45,60,40,20},
				arr_b {0,0,1,-1,2,1,-1,-1}},
			Bonus_list {{}},
			jobs {diviner,oni_savage},
			hayato, 1
			}, sf);
		add_unit(Unit_Base_Fates{ "Oboro",
			StatBlock_Fates {
				arr_b {25,13,0,11,12,11,13,8},
				arr_b {30,40,20,40,40,40,40,30},
				arr_b {0,1,-1,1,1,-1,1,-1}},
			Bonus_list {{}},
			jobs {spear_fighter,apothecary},
			oboro,10
			}, sf);
		add_unit(Unit_Base_Fates{ "Hinata",
			StatBlock_Fates {
				arr_b {26,11,0,9,14,10,12,4},
				arr_b {55,35,0,25,15,45,45,15},
				arr_b {0,1,0,-1,-2,0,2,0}},
			Bonus_list {{}},
			jobs {samurai,oni_savage},
			hinata,10
			}, sf);
	};
};

void Rolodex::populate_supports_h() {
	using namespace fe_fates::ids;
	using std::unordered_set;
	/* Hosh Supports */
	{
		unordered_set<int16_t> wives_common_h{ hinoka, sakura, felicia_1, felicia_2, azura, mozu, rinkah, orochi, kagero, hana, setsuna, oboro };
		supports.emplace(silas_h, 1, wives_common_h);
		supports.emplace(jacob_1, 1, wives_common_h);
		supports.emplace(kaze_h, 1, wives_common_h);
		supports.emplace(saizo, 1, wives_common_h);
		supports.emplace(kaden, 1, wives_common_h);
		supports.emplace(hinata, 1, wives_common_h);
		supports.emplace(azama, 1, wives_common_h);
		supports.emplace(subaki, 1, wives_common_h);
		supports.emplace(hayato, 1, wives_common_h);
		wives_common_h.erase(hinoka);
		wives_common_h.erase(sakura);
		supports.emplace(ryoma, 1, wives_common_h);
		supports.emplace(takumi, 1, wives_common_h);

		supports.emplace(silas_h, 2,
			unordered_set<int16_t>{ryoma, jacob_1, jacob_2, kaze_h});
		supports.emplace(ryoma, 2,
			unordered_set<int16_t>{saizo, silas_h, takumi});
		supports.emplace(jacob_1, 2,
			unordered_set<int16_t>{silas_h, takumi});
		supports.emplace(kaze_h, 2,
			unordered_set<int16_t>{saizo, silas_h});
		supports.emplace(saizo, 2,
			unordered_set<int16_t>{ryoma, subaki, kaze_h});
		supports.emplace(kaden, 2,
			unordered_set<int16_t>{hinata, azama, hayato});
		supports.emplace(hinata, 2,
			unordered_set<int16_t>{takumi, kaden, subaki});
		supports.emplace(azama, 2,
			unordered_set<int16_t>{kaden, subaki, hayato});
		supports.emplace(subaki, 2,
			unordered_set<int16_t>{azama, saizo, hinata});
		supports.emplace(hayato, 2,
			unordered_set<int16_t>{kaden, azama});
		supports.emplace(takumi, 2,
			unordered_set<int16_t>{ryoma, hinata, jacob_1});

	};
}

void Rolodex::serenes_forest(std::unordered_map<int16_t, Unit_Base_Fates>::iterator unit)
{
	auto job = jobs.find(unit->second.get_prim_job());
	if (job == jobs.end()) {
		std::cout << std::endl << "ERROR rolodex.serenes_forest job not found ERROR" << std::endl << "ERROR " << unit->first << " " << unit->second.name_ 
			<< " Expected job id: " << unit->second.get_prim_job() << std::endl;
		return;
	}
	unit->second.serenes_forest(job->second.get_stats());
}

void Rolodex::debug_console_print()
{
	for (const auto& [key, val] : units) {
		val.debug_console_print();
		std::cout << std::endl;
	}
	for (const auto& [key, val] : jobs) {
		val.debug_console_print();
		std::cout << std::endl;
	}

	supports.debug_console_print();
}


Rolodex common_table {};