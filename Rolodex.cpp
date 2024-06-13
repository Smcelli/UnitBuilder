#include "Rolodex.h"

Rolodex::Rolodex()
{
	populate_fates_abilities();
	populate_fates_jobs();
	populate_fates_units();
	populate_supports_h();
}

Job_Fates Rolodex::get_job(uint16_t id) const
{
	return jobs.get_job(id);
}

Job_Fates* Rolodex::get_job_ptr(uint16_t id)
{
	return jobs.get_job_ptr(id);
}

Unit_Base_Fates Rolodex::get_unit(uint16_t id) const
{
	const auto target = units.find(id);
	if (target == units.end()) {
		return Unit_Base_Fates();
	}
	return Unit_Base_Fates(target->second);
}

void Rolodex::populate_fates_abilities()
{
	using namespace fe_fates;
	using std::string;

	/*Unique Jobs*/
	{
		abilities.add_skill(Ability_Job_Fates{
			string("Luck +4"),
			(ID_SKILL_JOB + songstress * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Inspiring Song"),
			(ID_SKILL_JOB + (songstress * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Voice of Peace"),
			(ID_SKILL_JOB + (songstress * 2) + 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Foreign Princess"),
			(ID_SKILL_JOB + (songstress * 2) + 3) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Evenhanded"),
			(ID_SKILL_JOB + kitsune * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Beastbane"),
			(ID_SKILL_JOB + (kitsune * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Even Better"),
			(ID_SKILL_JOB + ninetails * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Grisly Wound"),
			(ID_SKILL_JOB + (ninetails * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Wolfskin"),
			(ID_SKILL_JOB + wolfskin * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Beastbane"),
			(ID_SKILL_JOB + (wolfskin * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Better Odds"),
			(ID_SKILL_JOB + wolfssegner * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Grisly Wound"),
			(ID_SKILL_JOB + (wolfssegner * 2) + 1) ,
			(promo_second) });
	};
	/*Hosh Jobs*/
	{
		abilities.add_skill(Ability_Job_Fates{
			string("Duelist's Blow"),
			(ID_SKILL_JOB + samurai * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Vantage"),
			(ID_SKILL_JOB + (samurai * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Astra "),
			(ID_SKILL_JOB + sword_master * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Swordfaire"),
			(ID_SKILL_JOB + (sword_master * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Seal Strength"),
			(ID_SKILL_JOB + master_arms_sam * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Life and Death"),
			(ID_SKILL_JOB + (master_arms_sam * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Seal Resistance"),
			(ID_SKILL_JOB + oni_savage * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Shove"),
			(ID_SKILL_JOB + (oni_savage * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Death Blow"),
			(ID_SKILL_JOB + oni_chief * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Counter"),
			(ID_SKILL_JOB + (oni_chief * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Salvage Blow"),
			(ID_SKILL_JOB + blacksmith * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Lancebreaker"),
			(ID_SKILL_JOB + (blacksmith * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Seal Defence"),
			(ID_SKILL_JOB + spear_fighter * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Swap"),
			(ID_SKILL_JOB + (spear_fighter * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Seal Speed"),
			(ID_SKILL_JOB + spear_master * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Lancefaire"),
			(ID_SKILL_JOB + (spear_master * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rend Heavern"),
			(ID_SKILL_JOB + basara_spr * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Quixotic"),
			(ID_SKILL_JOB + (basara_spr * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Magic +2"),
			(ID_SKILL_JOB + diviner * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Future Sight"),
			(ID_SKILL_JOB + (diviner * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Magic"),
			(ID_SKILL_JOB + onmyoji_div * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Tomefaire"),
			(ID_SKILL_JOB + (onmyoji_div * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rend Heaven"),
			(ID_SKILL_JOB + basara_div * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Quixotic"),
			(ID_SKILL_JOB + (basara_div * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Miracle"),
			(ID_SKILL_JOB + monk * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Luck"),
			(ID_SKILL_JOB + (monk * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Renewal"),
			(ID_SKILL_JOB + great_master * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Countermagic"),
			(ID_SKILL_JOB + (great_master * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Magic"),
			(ID_SKILL_JOB + onmyoji_mon * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Tomefaire"),
			(ID_SKILL_JOB + (onmyoji_mon * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Miracle"),
			(ID_SKILL_JOB + shrine_maiden * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Luck"),
			(ID_SKILL_JOB + (shrine_maiden * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Renewal"),
			(ID_SKILL_JOB + priestess * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Countermagic"),
			(ID_SKILL_JOB + (priestess * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Magic"),
			(ID_SKILL_JOB + onmyoji_shr * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Tomefaire"),
			(ID_SKILL_JOB + (onmyoji_shr * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Darting Blow"),
			(ID_SKILL_JOB + sky_knight * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Camaraderie"),
			(ID_SKILL_JOB + (sky_knight * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Speed"),
			(ID_SKILL_JOB + falcon_knight * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Warding Blow"),
			(ID_SKILL_JOB + (falcon_knight * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Air Superiority"),
			(ID_SKILL_JOB + kinshi_sky * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Amaterasu"),
			(ID_SKILL_JOB + (kinshi_sky * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Skill +2"),
			(ID_SKILL_JOB + archer * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Quick Draw"),
			(ID_SKILL_JOB + (archer * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Certain Blow"),
			(ID_SKILL_JOB + sniper * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Bowfaire"),
			(ID_SKILL_JOB + (sniper * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Air Superiority"),
			(ID_SKILL_JOB + kinshi_arc * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Amaterasu"),
			(ID_SKILL_JOB + (kinshi_arc * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Locktouch"),
			(ID_SKILL_JOB + ninja * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Poinson Strike"),
			(ID_SKILL_JOB + (ninja * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Lethality"),
			(ID_SKILL_JOB + master_nin * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Shurikenfaire"),
			(ID_SKILL_JOB + (master_nin * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Golembane"),
			(ID_SKILL_JOB + mechanist_nin * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Replicate"),
			(ID_SKILL_JOB + (mechanist_nin * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Potent Potion"),
			(ID_SKILL_JOB + apothecary * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Quick Salve"),
			(ID_SKILL_JOB + (apothecary * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Profiteer"),
			(ID_SKILL_JOB + merchant_apo * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Spendthrift"),
			(ID_SKILL_JOB + (merchant_apo * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Golembane"),
			(ID_SKILL_JOB + mechanist_apo * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Replicate"),
			(ID_SKILL_JOB + (mechanist_apo * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Aptitudes"),
			(ID_SKILL_JOB + villager * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Underdog"),
			(ID_SKILL_JOB + (villager * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Profiteer"),
			(ID_SKILL_JOB + merchant_vil * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Spendthrift"),
			(ID_SKILL_JOB + (merchant_vil * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Seal Strength"),
			(ID_SKILL_JOB + master_arms_vil * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Life and Death"),
			(ID_SKILL_JOB + (master_arms_vil * 2) + 1) ,
			(promo_second) });
	};
	/*Nohr Jobs*/
	{
		abilities.add_skill(Ability_Job_Fates{
			string("Elbow Room"),
			(ID_SKILL_JOB + cavalier * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Shelter"),
			(ID_SKILL_JOB + (cavalier * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Defender"),
			(ID_SKILL_JOB + paladin * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Aegis"),
			(ID_SKILL_JOB + (paladin * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Luna"),
			(ID_SKILL_JOB + great_knight_cav * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Armored Blow"),
			(ID_SKILL_JOB + (great_knight_cav * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Defence +2"),
			(ID_SKILL_JOB + knight * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Natural Cover"),
			(ID_SKILL_JOB + (knight * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Wary Fighter"),
			(ID_SKILL_JOB + general * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Pavise"),
			(ID_SKILL_JOB + (general * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Luna"),
			(ID_SKILL_JOB + great_knight_kni * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Armored Blow"),
			(ID_SKILL_JOB + (great_knight_kni * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("HP +5"),
			(ID_SKILL_JOB + fighter * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Gamble"),
			(ID_SKILL_JOB + (fighter * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Strength"),
			(ID_SKILL_JOB + berserker * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Axefaire"),
			(ID_SKILL_JOB + (berserker * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Sol"),
			(ID_SKILL_JOB + hero_fight * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Axebreaker"),
			(ID_SKILL_JOB + (hero_fight * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Good Fortune"),
			(ID_SKILL_JOB + mercenary * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Strong Riposte"),
			(ID_SKILL_JOB + (mercenary * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Sol"),
			(ID_SKILL_JOB + hero_merc * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Axebreaker"),
			(ID_SKILL_JOB + (hero_merc * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Skill"),
			(ID_SKILL_JOB + bow_knight_merc * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Shurikenbreaker"),
			(ID_SKILL_JOB + (bow_knight_merc * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Locktouch"),
			(ID_SKILL_JOB + outlaw * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Movement +1"),
			(ID_SKILL_JOB + (outlaw * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Skill"),
			(ID_SKILL_JOB + bow_knight_out * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Shurikenbreaker"),
			(ID_SKILL_JOB + (bow_knight_out * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Lucky 7"),
			(ID_SKILL_JOB + adventurer * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Pass"),
			(ID_SKILL_JOB + (adventurer * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Strength +2"),
			(ID_SKILL_JOB + wyvern_rider * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Lunge"),
			(ID_SKILL_JOB + (wyvern_rider * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Defence"),
			(ID_SKILL_JOB + wyvern_lord * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Swordbreaker"),
			(ID_SKILL_JOB + (wyvern_lord * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Savage Blow"),
			(ID_SKILL_JOB + malig_knight * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Trample"),
			(ID_SKILL_JOB + (malig_knight * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("HeartSeeker"),
			(ID_SKILL_JOB + dark_mage * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Malefic Aura"),
			(ID_SKILL_JOB + (dark_mage * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Vengence"),
			(ID_SKILL_JOB + sorcerer * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Bowbreaker"),
			(ID_SKILL_JOB + (sorcerer * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Seal Magic"),
			(ID_SKILL_JOB + dark_knight * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Lifetaker"),
			(ID_SKILL_JOB + (dark_knight * 2) + 1) ,
			(promo_second) });

		abilities.add_skill(Ability_Job_Fates{
			string("Resistance +2"),
			(ID_SKILL_JOB + troubadour * 2) ,
			(unpromo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Gentilhomme/Demoiselle"),
			(ID_SKILL_JOB + (troubadour * 2) + 1) ,
			(unpromo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Rally Resistance"),
			(ID_SKILL_JOB + strategist * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Inspiration"),
			(ID_SKILL_JOB + (strategist * 2) + 1) ,
			(promo_second) });
		abilities.add_skill(Ability_Job_Fates{
			string("Live to Serve"),
			(ID_SKILL_JOB + maid_butler * 2) ,
			(promo_first) });
		abilities.add_skill(Ability_Job_Fates{
			string("Tomebreaker"),
			(ID_SKILL_JOB + (maid_butler * 2) + 1) ,
			(promo_second) });
	};
	/*personal Hosh*/
	{
		abilities.add_skill(Ability_FE{
			string("Supportive"),
			(ID_SKILL_UNIT + avatar) });
		abilities.add_skill(Ability_FE{
			string("Devoted Partner"),
			(ID_SKILL_UNIT + felicia_1) });
		abilities.add_skill(Ability_FE{
			string("Evasive Partner"),
			(ID_SKILL_UNIT + jacob_1) });
		abilities.add_skill(Ability_FE{
			string("Miraculous Save"),
			(ID_SKILL_UNIT + kaze_h) });
		abilities.add_skill(Ability_FE{
			string("Healing Descant"),
			(ID_SKILL_UNIT + azura) });
		abilities.add_skill(Ability_FE{
			string("Vow of Friendship"),
			(ID_SKILL_UNIT + silas_h) });
		abilities.add_skill(Ability_FE{
			string("Highwayman"),
			(ID_SKILL_UNIT + shura_h) });
		abilities.add_skill(Ability_FE{
			string("Peacebringer"),
			(ID_SKILL_UNIT + izana) });
		abilities.add_skill(Ability_FE{
			string("Forager"),
			(ID_SKILL_UNIT + mozu) });

		abilities.add_skill(Ability_FE{
			string("Fiery Blood"),
			(ID_SKILL_UNIT + rinkah) });
		abilities.add_skill(Ability_FE{
			string("Quiet Strength"),
			(ID_SKILL_UNIT + sakura) });
		abilities.add_skill(Ability_FE{
			string("Fearsome Blow"),
			(ID_SKILL_UNIT + hana) });
		abilities.add_skill(Ability_FE{
			string("Perfectionist"),
			(ID_SKILL_UNIT + subaki) });
		abilities.add_skill(Ability_FE{
			string("Pyrotechnics"),
			(ID_SKILL_UNIT + saizo) });
		abilities.add_skill(Ability_FE{
			string("Capture"),
			(ID_SKILL_UNIT + orochi) });
		abilities.add_skill(Ability_FE{
			string("Rallying Cry"),
			(ID_SKILL_UNIT + hinoka) });
		abilities.add_skill(Ability_FE{
			string("Devine Retribution"),
			(ID_SKILL_UNIT + azama) });
		abilities.add_skill(Ability_FE{
			string("Optimist"),
			(ID_SKILL_UNIT + setsuna) });
		abilities.add_skill(Ability_FE{
			string("Pride"),
			(ID_SKILL_UNIT + hayato) });
		abilities.add_skill(Ability_FE{
			string("Nohr Enmity"),
			(ID_SKILL_UNIT + oboro) });
		abilities.add_skill(Ability_FE{
			string("Triple Threat"),
			(ID_SKILL_UNIT + hinata) });
		abilities.add_skill(Ability_FE{
			string("Competitive"),
			(ID_SKILL_UNIT + takumi) });
		abilities.add_skill(Ability_FE{
			string("Shiruken Mastery"),
			(ID_SKILL_UNIT + kagero) });
		abilities.add_skill(Ability_FE{
			string("Morbid Celebration"),
			(ID_SKILL_UNIT + reina) });
		abilities.add_skill(Ability_FE{
			string("Reciprocity"),
			(ID_SKILL_UNIT + kaden) });
		abilities.add_skill(Ability_FE{
			string("Bushido"),
			(ID_SKILL_UNIT + ryoma) });
		abilities.add_skill(Ability_FE{
			string("In Extremis"),
			(ID_SKILL_UNIT + scarlet) });
		abilities.add_skill(Ability_FE{
			string("Perspicacious"),
			(ID_SKILL_UNIT + yukimura) });
	};
}

void Rolodex::populate_fates_jobs() {
	using namespace fe_fates;
	jobs.add_job(Job_Fates{
		std::string("debug"),
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE>{0},
			std::array<int, BLOCK_SIZE>{0},
			std::array<int, BLOCK_SIZE>{0}
		},
		Bonus_statblock{
			std::array<int, BLOCK_SIZE>{0}, 0
		},
		debug_job + ID_JOB,0,0 //ID, promo, move
		});
	/* template */
/*
	jobs.add_job(Job_Fates{
		std::string(""),
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {},
			std::array<int, BLOCK_SIZE> {},
			std::array<int, BLOCK_SIZE> {}},
		Bonus_statblock{
			std::array<int, BLOCK_SIZE> {},0
		},
		 + ID_JOB_COMMON, 0, 7
	});
	*/
	/* Unique Jobs */

	/* Hosh Jobs */
	{
		jobs.add_job(Job_Fates{
			std::string("Samurai"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {17, 4, 0, 5, 8, 3, 3, 3},
				std::array<int, BLOCK_SIZE> {10, 10, 0, 15, 20, 15, 0, 10},
				std::array<int, BLOCK_SIZE> {40, 20, 16, 23, 25, 24, 18, 20}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0, 0, 0, 4, 2, 0, 0}, 0},
			samurai + ID_JOB, 0, 5
			});
		jobs.add_job(Job_Fates{
			std::string("SwordMaster"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {18,6,2,7,11,4,5,5},
				std::array<int, BLOCK_SIZE> {10,10,5,15,20,15,0,10},
				std::array<int, BLOCK_SIZE> {55,30,28,32,35,33,27,31}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,0,0,5,3,0,0},0
			},
			sword_master + ID_JOB, 1, 6
			});
		jobs.add_job(Job_Fates{
			std::string("Master of Arms"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {20,8,0,6,9,3,7,3},
				std::array<int, BLOCK_SIZE> {20,15,0,10,10,10,10,0},
				std::array<int, BLOCK_SIZE> {65,33,25,30,30,31,31,28}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,2,0,2,2,0,2,0},0
			},
			master_arms_sam + ID_JOB, 1, 6
			});
		jobs.add_job(master_arms_vil, master_arms_sam);
		jobs.add_job(Job_Fates{
			std::string("Oni Savage"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {18,6,1,2,5,0,7,1},
				std::array<int, BLOCK_SIZE> {20,20,10,0,10,0,20,0},
				std::array<int, BLOCK_SIZE> {45,24,19,16,20,17,23,18}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,4,0,0,0,0,2,0},0
			},
			oni_savage + ID_JOB, 0, 5
			});
		jobs.add_job(Job_Fates{
			std::string("Oni Chieftain"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {19,9,5,2,7,0,10,5},
				std::array<int, BLOCK_SIZE> {10,20,15,0,10,0,20,5},
				std::array<int, BLOCK_SIZE> {60,34,28,25,30,25,36,31}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,4,0,0,0,0,4,0},0
			},
			oni_chief + ID_JOB, 1, 6
			});
		jobs.add_job(Job_Fates{
			std::string("Blacksmith"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {21,8,0,9,8,3,8,2},
				std::array<int, BLOCK_SIZE> {20,15,0,15,10,5,15,0},
				std::array<int, BLOCK_SIZE> {65,33,25,32,31,30,32,27}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,3,0,2,0,0,3,0},0
			},
			blacksmith + ID_JOB, 1, 6
			});
		jobs.add_job(Job_Fates{
			std::string("Spear Fighter"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {17,6,0,6,6,2,5,2},
				std::array<int, BLOCK_SIZE> {15,15,0,15,15,5,10,5},
				std::array<int, BLOCK_SIZE> {40,22,15,23,22,21,22,21}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,2,0,2,2,0,0,0},0
			},
			spear_fighter + ID_JOB, 0,5
			});
		jobs.add_job(Job_Fates{
			std::string("Spear Master"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {18,9,0,8,8,3,7,3},
				std::array<int, BLOCK_SIZE> {15,15,0,15,15,5,10,5},
				std::array<int, BLOCK_SIZE> {60,34,25,33,32,29,30,29}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,3,0,3,2,0,0,0},0
			},
			spear_master + ID_JOB, 1, 6
			});
		jobs.add_job(Job_Fates{
			std::string("Basara"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {20,7,5,7,7,5,7,6},
				std::array<int, BLOCK_SIZE> {20,10,10,10,10,15,5,10},
				std::array<int, BLOCK_SIZE> {65,31,30,30,31,35,30,32}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,0,0,0,5,0,3},0
			},
			basara_div + ID_JOB, 1, 6
			});
		jobs.add_job(basara_spr, basara_div);
		jobs.add_job(Job_Fates{
			std::string("Diviner"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {15,0,4,5,6,1,1,3},
				std::array<int, BLOCK_SIZE> {0,5,15,10,15,5,0,10},
				std::array<int, BLOCK_SIZE> {35,17,22,20,23,19,16,20}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,3,0,3,0,0,0},0
			},
			diviner + ID_JOB, 0, 5
			});
		jobs.add_job(Job_Fates{
			std::string("Onmyoji"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {16,0,7,6,7,2,3,6},
				std::array<int, BLOCK_SIZE> {0,0,20,10,15,0,0,15},
				std::array<int, BLOCK_SIZE> {45,25,33,31,32,27,25,31}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,4,0,4,0,0,0},0
			},
			onmyoji_div + ID_JOB, 1, 6
			});
		jobs.add_job(onmyoji_mon, onmyoji_div);
		jobs.add_job(onmyoji_shr, onmyoji_div);
		jobs.add_job(Job_Fates{
			std::string("Monk"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {16,0,3,5,5,4,2,5},
				std::array<int, BLOCK_SIZE> {0,5,10,10,15,15,0,20},
				std::array<int, BLOCK_SIZE> {35,18,21,20,22,23,17,24}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,2,0,0,2,0,2},0
			},
			monk + ID_JOB, 0, 5
			});
		jobs.add_job(shrine_maiden, monk);
		jobs.add_job(Job_Fates{
			std::string("Great Master"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {19,8,6,6,8,5,6,7},
				std::array<int, BLOCK_SIZE> {10,15,5,5,15,15,10,10},
				std::array<int, BLOCK_SIZE> {55,32,30,31,33,32,28,32}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,3,0,0,2,0,3},0
			},
			great_master + ID_JOB, 1, 6
			});
		jobs.add_job(Job_Fates{
			std::string("Priestess"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {19,6,7,6,9,5,5,8},
				std::array<int, BLOCK_SIZE> {10,10,10,5,15,15,0,20},
				std::array<int, BLOCK_SIZE> {50,29,32,30,33,34,26,34}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,3,0,0,2,0,3},0
			},
			priestess + ID_JOB, 1, 6
			});
		jobs.add_job(Job_Fates{
			std::string("Sky Knight"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {16,3,0,5,7,4,2,6},
				std::array<int, BLOCK_SIZE> {0,10,0,10,15,20,0,20},
				std::array<int, BLOCK_SIZE> {35,19,16,21,23,25,18,25}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,0,0,3,0,0,3},0
			},
			sky_knight + ID_JOB, 0, 7
			});
		jobs.add_job(Job_Fates{
			std::string("Falcon Knight"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {18,5,4,6,10,5,5,9},
				std::array<int, BLOCK_SIZE> {0,10,10,10,15,20,0,20},
				std::array<int, BLOCK_SIZE> {55,28,27,30,34,35,27,35}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,0,0,3,0,0,3},1
			},
			falcon_knight + ID_JOB, 1, 8
			});
		jobs.add_job(Job_Fates{
			std::string("Kinshi Knight"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {17,4,1,9,8,5,4,7},
				std::array<int, BLOCK_SIZE> {0,5,0,15,15,15,0,15},
				std::array<int, BLOCK_SIZE> {50,27,26,33,31,34,25,31}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,0,2,2,2,0,0},1
			},
			kinshi_arc + ID_JOB, 1, 8
			});
		jobs.add_job(kinshi_sky, kinshi_arc);
		jobs.add_job(Job_Fates{
			std::string("Archer"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {17,5,0,7,5,2,4,1},
				std::array<int, BLOCK_SIZE> {10,15,0,15,15,5,10,0},
				std::array<int, BLOCK_SIZE> {40,21,15,23,21,20,20,17}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,2,0,2,2,0,0,0},0
			},
			archer + ID_JOB, 0, 5
			});
		jobs.add_job(Job_Fates{
			std::string("Sniper"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {19,7,0,10,9,3,6,2},
				std::array<int, BLOCK_SIZE> {10,15,0,20,15,5,10,0},
				std::array<int, BLOCK_SIZE> {55,31,25,35,33,30,31,28}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,2,0,3,3,0,0,0},0
			},
			sniper + ID_JOB, 1, 6
			});
		jobs.add_job(Job_Fates{
			std::string("Ninja"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {16,3,0,8,8,1,3,3},
				std::array<int, BLOCK_SIZE> {5,5,0,20,20,0,5,15},
				std::array<int, BLOCK_SIZE> {35,17,15,25,25,18,19,20}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,0,1,3,0,0,0},1
			},
			ninja + ID_JOB, 0, 5
			});
		jobs.add_job(Job_Fates{
			std::string("Master Ninja"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {17,5,0,10,11,2,4,8},
				std::array<int, BLOCK_SIZE> {5,5,0,20,20,0,5,20},
				std::array<int, BLOCK_SIZE> {55,27,25,35,35,28,26,34}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,0,2,4,0,0,0},1
			},
			master_nin + ID_JOB, 1, 6
			});
		jobs.add_job(Job_Fates{
			std::string("Mechanist"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {18,7,0,9,7,2,6,6},
				std::array<int, BLOCK_SIZE> {10,10,0,15,10,5,5,15},
				std::array<int, BLOCK_SIZE> {60,30,25,33,30,30,31,31}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,2,0,2,0,0,2,2},0
			},
			mechanist_apo + ID_JOB, 1, 7
			});
		jobs.add_job(mechanist_nin, mechanist_apo);
		jobs.add_job(Job_Fates{
			std::string("Apothecary"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {18,6,0,4,4,2,6,2},
				std::array<int, BLOCK_SIZE> {20,20,0,10,10,5,10,5},
				std::array<int, BLOCK_SIZE> {45,24,15,19,19,21,23,20}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,3,0,0,0,0,2,1},0
			},
			apothecary + ID_JOB, 0, 5
			});
		jobs.add_job(Job_Fates{
			std::string("Merchant"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {20,8,0,6,5,4,8,5},
				std::array<int, BLOCK_SIZE> {20,20,0,10,5,15,10,5},
				std::array<int, BLOCK_SIZE> {65,33,25,29,28,32,33,30}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,3,0,0,0,0,3,2},0
			},
			merchant_apo + ID_JOB, 1, 6
			});
		jobs.add_job(merchant_vil, merchant_apo);
		jobs.add_job(Job_Fates{
			std::string("Villager"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {17,5,0,4,5,3,4,0},
				std::array<int, BLOCK_SIZE> {10,10,0,10,10,20,10,0},
				std::array<int, BLOCK_SIZE> {35,19,15,19,19,22,18,15}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0,0,0,3,0,3,0,0},0
			},
			villager + ID_JOB, 0, 5
			});
	};
	/* Nohr Jobs */
	{
		jobs.add_job(Job_Fates{
			std::string("Cavalier"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {17,6,0,5,5,3,5,3},
				std::array<int, BLOCK_SIZE> {10,15,0,10,10,15,10,5},
				std::array<int, BLOCK_SIZE> {40, 22,15,21,20,24,22,21}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0, 2,0,0,0,0,2,2},0
			},
			cavalier + ID_JOB, 0, 7
			});
		jobs.add_job(Job_Fates{
			std::string("Paladin"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {19,8,1,7,7,4,7,6},
				std::array<int, BLOCK_SIZE> {10,15,0,10,10,15,10,10},
				std::array<int, BLOCK_SIZE> {60, 31,26,30,30,32,32,32}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0, 2,0,0,0,0,2,2},1
			},
			paladin + ID_JOB, 1, 8
			});
		jobs.add_job(Job_Fates{
			std::string("great knight"),
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {21,10,0,6,6,3,10,2},
				std::array<int, BLOCK_SIZE> {10,15,0,10,10,15,10,10},
				std::array<int, BLOCK_SIZE> {65, 35,25,29,27,28,37,28}},
			Bonus_statblock{
				std::array<int, BLOCK_SIZE> {0, 2,0,0,0,0,4,0}, 1 },
			great_knight_cav + ID_JOB, 1, 7
			});
		jobs.add_job(great_knight_kni, great_knight_cav);
	};
}

void Rolodex::populate_fates_units() {
	/*
	offsets
	Felicia, Jakob: 0
	Gunter: 5
	Camilla, Reina: 15
	Leo: 18
	*/
	/*template*/
/*
	units.try_emplace(ID_UNIT + , Unit_Base_Fates{
		"",
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {},
			std::array<int, BLOCK_SIZE> {},
			std::array<int, BLOCK_SIZE> {}
		},
		Bonus_statblock{std::array <int, BLOCK_SIZE>
			{}, },
		ID_UNIT + , ID_JOB_COMMON + , ID_JOB_COMMON + ,
		0, 0, 0,
		});
*/
	using fe_fates::id_type, fe_fates::ID_UNIT;

	units.try_emplace(ID_UNIT + silas_h, Unit_Base_Fates{
		"Silas",
		StatBlock_Fates{
			std::array<int, BLOCK_SIZE> {22, 11, 0, 9, 8, 7, 10, 5},
			std::array<int, BLOCK_SIZE> {40, 45, 5, 50, 40, 40, 40, 25},
			std::array<int, BLOCK_SIZE> {0, 1, 0, 2, 0, -1, 0, -1 }
		},
		Bonus_statblock{std::array <int, BLOCK_SIZE>
			{0, 2, 0, 1, 1, 0, 1, 0}, 0},
		ID_UNIT + silas_h, ID_JOB + cavalier, ID_JOB + mercenary,
		6, 0, 0,
		});

	/* Hosh Units */
	{
		units.try_emplace(ID_UNIT + ryoma, Unit_Base_Fates{
			"Ryoma",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {36, 20, 2, 18, 24, 20, 16, 13},
				std::array<int, BLOCK_SIZE> {50, 45, 0, 50, 45, 40, 35, 25},
				std::array<int, BLOCK_SIZE> {0, 1, 0, 2, 1, 1, -2, -2 }
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE> {0, 100, 0, 100, 300, 0, 0, 0}, 0},
			ID_UNIT + ryoma, ID_JOB + sword_master, ID_JOB + sky_knight,
			24, 0, 1,
			});
		units.try_emplace(ID_UNIT + rinkah, Unit_Base_Fates{
			"Rinkah",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {20,8,2,6,8,5,10,3},
				std::array<int, BLOCK_SIZE> {20,25,15,50,45,35,45,20},
				std::array<int, BLOCK_SIZE> {0,-1,0,-2,1,0,2,0}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,1,0,0,2,0,2,0}, 0},
			ID_UNIT + rinkah, ID_JOB + oni_savage, ID_JOB + ninja,
			4, 0, 0,
			});
		units.try_emplace(ID_UNIT + sakura, Unit_Base_Fates{
			"Sakura",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {16,3,6,5,7,9,5,7},
				std::array<int, BLOCK_SIZE> {45,30,50,40,40,55,30,20},
				std::array<int, BLOCK_SIZE> {0,0,2,-1,1,0,-1,0}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,0,1,0,2,1,0,1}, 0},
			ID_UNIT + sakura, ID_JOB + shrine_maiden, ID_JOB + sky_knight,
			1, 0, 0,
			});
		units.try_emplace(ID_UNIT + hana, Unit_Base_Fates{
			"Hana",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {20,9,0,11,11,5,6,9},
				std::array<int, BLOCK_SIZE> {25,55,10,45,55,25,20,30},
				std::array<int, BLOCK_SIZE> {0,1,0,1,2,-1,-3,1}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,2,0,1,2,0,0,0}, 0},
			ID_UNIT + hana, ID_JOB + samurai, ID_JOB + shrine_maiden,
			4, 0, 0,
			});
		units.try_emplace(ID_UNIT + subaki, Unit_Base_Fates{
			"Subaki",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {22,8,0,13,10,7,9,10},
				std::array<int, BLOCK_SIZE> {55,30,20,50,20,25,45,5},
				std::array<int, BLOCK_SIZE> {0,-1,0,2,-2,-1,3,-1}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,0,0,2, 0,0,2,1}, 0},
			ID_UNIT + subaki, ID_JOB + sky_knight, ID_JOB + samurai,
			5, 0, 0,
			});
		units.try_emplace(ID_UNIT + saizo, Unit_Base_Fates{
			"Saizo",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {23,11,3,14,11,9,9,7},
				std::array<int, BLOCK_SIZE> {40,50,45,60,30,55,45,10},
				std::array<int, BLOCK_SIZE> {0,1,0,3,-2,0,1,-2}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,1,0,1, 1,2,0,0}, 0},
			ID_UNIT + saizo, ID_JOB + ninja, ID_JOB + samurai,
			7, 0, 0,
			});
		units.try_emplace(ID_UNIT + orochi, Unit_Base_Fates{
			"Orochi",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {20,0,9,11,7,6,5,10},
				std::array<int, BLOCK_SIZE> {35,5,65,50,15,35,25,45},
				std::array<int, BLOCK_SIZE> {0,0,3,2,-2,-1,-2,1}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,0,2,1, 0,0,0,2}, 0},
			ID_UNIT + orochi, ID_JOB + diviner, ID_JOB + apothecary,
			5, 0, 0,
			});
		units.try_emplace(ID_UNIT + hinoka, Unit_Base_Fates{
			"Hinoka",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {23,9,4,13,16,12,9,15},
				std::array<int, BLOCK_SIZE> {45,45,15,40,45,40,35,40},
				std::array<int, BLOCK_SIZE> {0,1,-1,-1,1,0,-1,2}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,1,0,0, 1,1,0,2}, 0},
			ID_UNIT + hinoka, ID_JOB + sky_knight, ID_JOB + spear_fighter,
			8, 0, 0,
			});
		units.try_emplace(ID_UNIT + azama, Unit_Base_Fates{
			"Azama",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {24,9,7,9,10,12,10,8},
				std::array<int, BLOCK_SIZE> {55,50,20,40,45,40,40,20},
				std::array<int, BLOCK_SIZE> {0,2,-3,0,1,0,1,0}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,2,0,0, 1,1,1,0}, 0},
			ID_UNIT + azama, ID_JOB + monk, ID_JOB + apothecary,
			7, 0, 0,
			});
		units.try_emplace(ID_UNIT + setsuna, Unit_Base_Fates{
			"Setsuna",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {19,8,0,9,10,6,5,3},
				std::array<int, BLOCK_SIZE> {30,20,0,30,60,30,15,40},
				std::array<int, BLOCK_SIZE> {0,0,0,1,3,-1,-1,-1}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,0,0,1, 3,0,0,1}},
			ID_UNIT + setsuna, ID_JOB + archer, ID_JOB + ninja,
			3, 0, 0,
			});
		units.try_emplace(ID_UNIT + hayato, Unit_Base_Fates{
			"Hayato",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {16,1,4,5,7,8,4,5},
				std::array<int, BLOCK_SIZE> {50,30,40,30,45,60,40,20},
				std::array<int, BLOCK_SIZE> {0,0,1,-1,2,1,-1,-1}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,0,1,0, 2,2,0,0}},
			ID_UNIT + hayato, ID_JOB + diviner, ID_JOB + oni_savage,
			1, 0, 0,
			});
		units.try_emplace(ID_UNIT + oboro, Unit_Base_Fates{
			"Oboro",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {25,13,0,11,12,11,13,8},
				std::array<int, BLOCK_SIZE> {30,40,20,40,40,40,40,30},
				std::array<int, BLOCK_SIZE> {0,1,-1,1,1,-1,1,-1}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,1,0,1, 1,1,1,0}},
			ID_UNIT + oboro, ID_JOB + spear_fighter, ID_JOB + apothecary,
			10, 0, 0,
			});
		units.try_emplace(ID_UNIT + hinata, Unit_Base_Fates{
			"Hinata",
			StatBlock_Fates{
				std::array<int, BLOCK_SIZE> {26,11,0,9,14,10,12,4},
				std::array<int, BLOCK_SIZE> {55,35,0,25,15,45,45,15},
				std::array<int, BLOCK_SIZE> {0,1,0,-1,-2,0,2,0}
			},
			Bonus_statblock{std::array <int, BLOCK_SIZE>
				{0,2,0,0, 0,1,2,0}},
			ID_UNIT + hinata, ID_JOB + samurai, ID_JOB + oni_savage,
			10, 0, 0,
			});
	};
}

void Rolodex::populate_supports_h() {

	/* Hosh Supports */
	{
		unordered_set<uint16_t> wives_common_h{ hinoka, sakura, felicia_1, felicia_2, azura, mozu, rinkah, orochi, kagero, hana, setsuna, oboro };
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
			unordered_set<uint16_t>{ryoma, jacob_1, jacob_2, kaze_h});
		supports.emplace(ryoma, 2,
			unordered_set<uint16_t>{saizo, silas_h, takumi});
		supports.emplace(jacob_1, 2,
			unordered_set<uint16_t>{silas_h, takumi});
		supports.emplace(kaze_h, 2,
			unordered_set<uint16_t>{saizo, silas_h});
		supports.emplace(saizo, 2,
			unordered_set<uint16_t>{ryoma, subaki, kaze_h});
		supports.emplace(kaden, 2,
			unordered_set<uint16_t>{hinata, azama, hayato});
		supports.emplace(hinata, 2,
			unordered_set<uint16_t>{takumi, kaden, subaki});
		supports.emplace(azama, 2,
			unordered_set<uint16_t>{kaden, subaki, hayato});
		supports.emplace(subaki, 2,
			unordered_set<uint16_t>{azama, saizo, hinata});
		supports.emplace(hayato, 2,
			unordered_set<uint16_t>{kaden, azama});
		supports.emplace(takumi, 2,
			unordered_set<uint16_t>{ryoma, hinata, jacob_1});

	};
}

void Rolodex::debug_console_print()
{
	abilities.debug_console_print();
	jobs.debug_console_print();
	for (const auto& [key, val] : units) {
		val.debug_console_print();
		std::cout << std::endl;
	}
	supports.debug_console_print();
}