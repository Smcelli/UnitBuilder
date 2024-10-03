#include <Rolodex.h>

Rolodex::Rolodex()
{
	populate_fates_jobs();
	populate_fates_abilities();
	populate_supports_h();
	populate_fates_units();
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

int16_t Rolodex::get_id_custom()
{
	Id_custom_count--;
	return Id_custom_count;
}

int16_t Rolodex::get_backup_job_id(int16_t job_id)
{
	auto it = backup_job_table.find(job_id);
	if (it != backup_job_table.end())
		return it->second;
	else
		return 0;
}

void Rolodex::add_ability(Ability_FE ability)
{
	ability.id = fe_fates::id_skill_unit(ability.id);
	if (ability.id)
		abilities.try_emplace(ability.id, ability);
}

void Rolodex::add_ability(Ability_Job_Fates ability)
{
	ability.id = fe_fates::id_skill_job(ability.id);
	if (ability.id)
		abilities.try_emplace(ability.id, ability);
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

	/*Unique Jobs*/
	{
		add_ability(
			Ability_Job_Fates{
				string("Luck +4"),
				id_skill_job(songstress),
				unpromo_first });
		add_ability(
			Ability_Job_Fates{
				string("Inspiring Song"),
				id_skill_job(songstress, 1),
				unpromo_second });
		add_ability(
			Ability_Job_Fates{
				string("Voice of Peace"),
				id_skill_job(songstress, 2),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Foreign Princess"),
				id_skill_job(songstress, 3),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Evenhanded"),
				id_skill_job(kitsune),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Beastbane"),
				id_skill_job(kitsune, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Even Better"),
				id_skill_job(ninetails),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Grisly Wound"),
				id_skill_job(ninetails, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Wolfskin"),
				id_skill_job(wolfskin),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Beastbane"),
				id_skill_job(wolfskin, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Better Odds"),
				id_skill_job(wolfssegner),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Grisly Wound"),
				id_skill_job(wolfssegner, 1),
				(promo_second) });
	};
	/*Hosh Jobs*/
	{
		add_ability(
			Ability_Job_Fates{
				string("Duelist's Blow"),
				id_skill_job(samurai),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Vantage"),
				id_skill_job(samurai, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Astra "),
				id_skill_job(sword_master),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Swordfaire"),
				id_skill_job(sword_master, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Seal Strength"),
				id_skill_job(master_arms_sam),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Life and Death"),
				id_skill_job(master_arms_sam, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Seal Resistance"),
				id_skill_job(oni_savage),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Shove"),
				id_skill_job(oni_savage, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Death Blow"),
				id_skill_job(oni_chief),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Counter"),
				id_skill_job(oni_chief, 1),
				(promo_second) });
		add_ability(Ability_Job_Fates{
				string("Salvage Blow"),
				id_skill_job(blacksmith),
				(promo_first) });
		add_ability(Ability_Job_Fates{
				string("Lancebreaker"),
				id_skill_job(blacksmith, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Seal Defence"),
				id_skill_job(spear_fighter),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Swap"),
				id_skill_job(spear_fighter, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Seal Speed"),
				id_skill_job(spear_master),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Lancefaire"),
				id_skill_job(spear_master, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rend Heavern"),
				id_skill_job(basara_spr),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Quixotic"),
				id_skill_job(basara_spr, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Magic +2"),
				id_skill_job(diviner),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Future Sight"),
				id_skill_job(diviner, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Magic"),
				id_skill_job(onmyoji_div),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Tomefaire"),
				id_skill_job(onmyoji_div, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rend Heaven"),
				id_skill_job(basara_div),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Quixotic"),
				id_skill_job(basara_div, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Miracle"),
				id_skill_job(monk),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Luck"),
				id_skill_job(monk, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Renewal"),
				id_skill_job(great_master),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Countermagic"),
				id_skill_job(great_master, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Magic"),
				id_skill_job(onmyoji_mon),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Tomefaire"),
				id_skill_job(onmyoji_mon, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Miracle"),
				id_skill_job(shrine_maiden),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Luck"),
				id_skill_job(shrine_maiden, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Renewal"),
				id_skill_job(priestess),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Countermagic"),
				id_skill_job(priestess, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Magic"),
				id_skill_job(onmyoji_shr),
				(promo_first) });
		add_ability(Ability_Job_Fates{
				string("Tomefaire"),
				id_skill_job(onmyoji_shr, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Darting Blow"),
				id_skill_job(sky_knight),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Camaraderie"),
				id_skill_job(sky_knight, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Speed"),
				id_skill_job(falcon_knight),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Warding Blow"),
				id_skill_job(falcon_knight, 1),
				(promo_second) });
			add_ability(
			Ability_Job_Fates{
				string("Air Superiority"),
				id_skill_job(kinshi_sky),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Amaterasu"),
				id_skill_job(kinshi_sky, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Skill +2"),
				id_skill_job(archer),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Quick Draw"),
				id_skill_job(archer, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Certain Blow"),
				id_skill_job(sniper),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Bowfaire"),
				id_skill_job(sniper, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Air Superiority"),
				id_skill_job(kinshi_arc),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Amaterasu"),
				id_skill_job(kinshi_arc, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Locktouch"),
				id_skill_job(ninja),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Poinson Strike"),
				id_skill_job(ninja, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Lethality"),
				id_skill_job(master_nin),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Shurikenfaire"),
				id_skill_job(master_nin, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Golembane"),
				id_skill_job(mechanist_nin),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Replicate"),
				id_skill_job(mechanist_nin, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Potent Potion"),
				id_skill_job(apothecary),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Quick Salve"),
				id_skill_job(apothecary, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Profiteer"),
				id_skill_job(merchant_apo),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Spendthrift"),
				id_skill_job(merchant_apo, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Golembane"),
				id_skill_job(mechanist_apo),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Replicate"),
				id_skill_job(mechanist_apo, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Aptitudes"),
				id_skill_job(villager),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Underdog"),
				id_skill_job(villager, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Profiteer"),
				id_skill_job(merchant_vil),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Spendthrift"),
				id_skill_job(merchant_vil, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Seal Strength"),
				id_skill_job(master_arms_vil),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Life and Death"),
				id_skill_job(master_arms_vil, 1),
				(promo_second) });
	};
	/*Nohr Jobs*/
	{
		add_ability(
			Ability_Job_Fates{
				string("Elbow Room"),
				id_skill_job(cavalier),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Shelter"),
				id_skill_job(cavalier, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Defender"),
				id_skill_job(paladin),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Aegis"),
				id_skill_job(paladin, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Luna"),
				id_skill_job(great_knight_cav),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Armored Blow"),
				id_skill_job(great_knight_cav, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Defence +2"),
				id_skill_job(knight),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Natural Cover"),
				id_skill_job(knight, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Wary Fighter"),
				id_skill_job(general),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Pavise"),
				id_skill_job(general, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Luna"),
				id_skill_job(great_knight_kni),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Armored Blow"),
				id_skill_job(great_knight_kni, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("HP +5"),
				id_skill_job(fighter),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Gamble"),
				id_skill_job(fighter, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Strength"),
				id_skill_job(berserker),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Axefaire"),
				id_skill_job(berserker, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Sol"),
				id_skill_job(hero_fight),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Axebreaker"),
				id_skill_job(hero_fight, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Good Fortune"),
				id_skill_job(mercenary),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Strong Riposte"),
				id_skill_job(mercenary, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Sol"),
				id_skill_job(hero_merc),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Axebreaker"),
				id_skill_job(hero_merc, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Skill"),
				id_skill_job(bow_knight_merc),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Shurikenbreaker"),
				id_skill_job(bow_knight_merc, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Locktouch"),
				id_skill_job(outlaw),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Movement +1"),
				id_skill_job(outlaw, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Skill"),
				id_skill_job(bow_knight_out),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Shurikenbreaker"),
				id_skill_job(bow_knight_out, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Lucky 7"),
				id_skill_job(adventurer),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Pass"),
				id_skill_job(adventurer, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("Strength +2"),
				id_skill_job(wyvern_rider),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Lunge"),
				id_skill_job(wyvern_rider, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Defence"),
				id_skill_job(wyvern_lord),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Swordbreaker"),
				id_skill_job(wyvern_lord, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Savage Blow"),
				id_skill_job(malig_knight),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Trample"),
				id_skill_job(malig_knight, 1),
				(promo_second) });

		add_ability(
			Ability_Job_Fates{
				string("HeartSeeker"),
				id_skill_job(dark_mage),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Malefic Aura"),
				id_skill_job(dark_mage, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Vengence"),
				id_skill_job(sorcerer),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Bowbreaker"),
				id_skill_job(sorcerer, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Seal Magic"),
				id_skill_job(dark_knight),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Lifetaker"),
				id_skill_job(dark_knight, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Resistance +2"),
				id_skill_job(troubadour_m),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Gentilhomme"),
				id_skill_job(troubadour_m, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Resistance"),
				id_skill_job(strategist_m),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Inspiration"),
				id_skill_job(strategist_m, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Live to Serve"),
				id_skill_job(butler),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Tomebreaker"),
				id_skill_job(butler, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Resistance +2"),
				id_skill_job(troubadour_f),
				(unpromo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Demoiselle"),
				id_skill_job(troubadour_f, 1),
				(unpromo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Rally Resistance"),
				id_skill_job(strategist_f),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Inspiration"),
				id_skill_job(strategist_f, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Live to Serve"),
				id_skill_job(maid),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Tomebreaker"),
				id_skill_job(maid, 1),
				(promo_second) });
		add_ability(
			Ability_Job_Fates{
				string("Live to Serve"),
				id_skill_job(maid),
				(promo_first) });
		add_ability(
			Ability_Job_Fates{
				string("Tomebreaker"),
				id_skill_job(maid, 1),
				(promo_second) });
	};
	/*personal Hosh*/
	using fe_fates::id_skill_unit;
	{
		add_ability(
			Ability_FE{
				string("Supportive"),
				id_skill_unit(avatar_m) });
		add_ability(
			Ability_FE{
				string("Supportive"),
				id_skill_unit(avatar_f) });
		add_ability(
			Ability_FE{
				string("Devoted Partner"),
				id_skill_unit(felicia_1) });
		add_ability(
			Ability_FE{
				string("Devoted Partner"),
				id_skill_unit(felicia_2) });
		add_ability(
			Ability_FE{
				string("Evasive Partner"),
				id_skill_unit(jacob_1) });
		add_ability(
			Ability_FE{
				string("Evasive Partner"),
				id_skill_unit(jacob_2) });
		add_ability(
			Ability_FE{
				string("Miraculous Save"),
				id_skill_unit(kaze_h) });
		add_ability(
			Ability_FE{
				string("Healing Descant"),
				id_skill_unit(azura) });
		add_ability(
			Ability_FE{
				string("Vow of Friendship"),
				id_skill_unit(silas_h) });
		add_ability(
			Ability_FE{
				string("Highwayman"),
				id_skill_unit(shura_h) });
		add_ability(
			Ability_FE{
				string("Peacebringer"),
				id_skill_unit(izana) });
		add_ability(
			Ability_FE{
				string("Forager"),
				id_skill_unit(mozu) });

		add_ability(
			Ability_FE{
				string("Fiery Blood"),
				id_skill_unit(rinkah) });
		add_ability(
			Ability_FE{
				string("Quiet Strength"),
				id_skill_unit(sakura) });
		add_ability(
			Ability_FE{
				string("Fearsome Blow"),
				id_skill_unit(hana) });
		add_ability(
			Ability_FE{
				string("Perfectionist"),
				id_skill_unit(subaki) });
		add_ability(
			Ability_FE{
				string("Pyrotechnics"),
				id_skill_unit(saizo) });
		add_ability(
			Ability_FE{
				string("Capture"),
				id_skill_unit(orochi) });
		add_ability(
			Ability_FE{
				string("Rallying Cry"),
				id_skill_unit(hinoka) });
		add_ability(
			Ability_FE{
				string("Devine Retribution"),
				id_skill_unit(azama) });
		add_ability(
			Ability_FE{
				string("Optimist"),
				id_skill_unit(setsuna) });
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
}

void Rolodex::populate_fates_jobs() {
	using namespace fe_fates::ids;
	using fe_fates::id_job;
	typedef std::array<int16_t, BLOCK_SIZE> arr_b;
	
	/* template */
	/*
	add_job(Job_Fates{ "",
			id, move,
			Bonus_list{{}},
			StatBlock_Fates{
				arr_b {},
				arr_b {},
				arr_b {}
			} });
	*/

	add_job(Job_Fates{ "debug",
		debug_job, 5,
		Bonus_list {{0}},
		StatBlock_Fates{
			arr_b {0},
			arr_b {0},
			arr_b {0},
		}});
	add_job(Job_Fates{ "debug promo",
		debug_job + 1, 6,
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
	}

	/* Hosh Jobs */
	{
		add_job(Job_Fates{ "Hoshido Noble",
			hoshido_nob, 6,
			Bonus_list {{2,0,1,1,2,2,0,0}},
			StatBlock_Fates{
				arr_b {19,10,4,5,6,4,7,3},
				arr_b {15,15,10,10,10,10,15,0},
				arr_b {60,34,28,29,30,33,31,28}
			} });
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
		add_unit(Unit_Base_Fates{ "Avatar",
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
	for (const auto& [key, val] : abilities) {
		val.debug_console_print();
		std::cout << std::endl;
	}
	supports.debug_console_print();
}


Rolodex common_table {};