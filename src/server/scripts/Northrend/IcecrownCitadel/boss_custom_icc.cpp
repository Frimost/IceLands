/*
* Boss para reemplazar Gunship Battle de icc
*@Autor: Vertex
*
*/
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "MapManager.h"
#include "icecrown_citadel.h"
//#include "ScriptPCH.h"
enum Spells
{
	SPELL_WOUNDING        = 69651,
	SPELL_WOUNDING_HERO   = 72570,
	SPELL_TOXIC_WASTE     = 70436,
	SPELL_DESPERATE       = 72536,
	SPELL_CLEAVE          = 15284,
	SPELL_HAMMER          = 66940,
	SPELL_ADD_HEAL        = 26565,
	SPELL_ADD_HEAL_VISUAL = 17137 //1.5 seg de cast heal muy bajo
};
enum Adds
{
	NPC_ADD = 68709
};
enum Events
{
	EVENT_WOUNDING     = 1,
	EVENT_TOXIC_WASTE  = 2,
	EVENT_DESPERATE    = 3,
	EVNET_CLEAVE       = 4,
	EVENT_SPELL_HAMMER = 5,
	EVENT_ENRAGE       = 6,
	EVENT_SUMMON       = 7,
	EVENT_HEAL         = 8,
	EVENT_HEAL_VISUAL  = 9
};
enum Yells
{
	SAY_AGRO      = 1,
	SAY_DESPERATE = 2,
	//SAY_HAMMER  = 3,
	SAY_SUMMON    = 4,
	//ADD yells
	SAY_HEAL      = 5
};
class boss_custom_icc : public CreatureScript
{
public:
	boss_custom_icc() : CreatureScript("boss_custom_icc") { }

	struct boss_custom_iccAI : public BossAI
	{
		boss_custom_iccAI(Creature* creature) : BossAI(creature, DATA_GUNSHIP_BATTLE_EVENT)
		{}

		void Reset()
		{
			_Reset();
			me->RemoveAurasDueToSpell(SPELL_BERSERK);
			_desperate = false;
			events.Reset();
			events.ScheduleEvent(EVENT_WOUNDING, 2000);
			events.ScheduleEvent(EVENT_TOXIC_WASTE, 2500);
			events.ScheduleEvent(EVNET_CLEAVE,3000);
			events.ScheduleEvent(EVENT_SPELL_HAMMER,4000);
			events.ScheduleEvent(EVENT_SUMMON,10000);
			events.ScheduleEvent(EVENT_ENRAGE, 600000);
		}

		void EnterCombat(Unit* /*who*/)
		{
			Talk(SAY_AGRO);
			me->setActive(true);
			DoZoneInCombat();
		}

		void JustDied(Unit* /*killer*/)
		{
			//Talk(SAY_DEATH);
			//instance->SetBossState(DATA_GUNSHIP_BATTLE_EVENT,DONE);
			_JustDied();
		}

		void JustReachedHome()
		{
			_JustReachedHome();
			instance->SetBossState(DATA_GUNSHIP_BATTLE_EVENT, FAIL);
		}
		void DamageTaken(Unit* /*damageDealer*/, uint32& damage)
		{
			// Al 30%
			if(!_desperate && HealthBelowPct(31))
			{
				_desperate = true;
				DoCast(me,SPELL_DESPERATE);
				Talk(SAY_DESPERATE);
			}					
		}
		void KilledUnit(Unit* victim)
		{
			// if (victim->GetTypeId() == TYPEID_PLAYER)
			//   Talk(SAY_KILL);
		}
		void JustSummoned(Creature* summon)
		{	//change 0 to 1
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
				summon->AI()->AttackStart(target);
			summons.Summon(summon);
		}
		void SummonedCreatureDespawn(Creature* summon)
		{
			summons.Despawn(summon);
		}
		void MoveInLineOfSight(Unit* who)
		{
			//  if (!_introDone && me->IsWithinDistInMap(who, 70.0f))
			// {
			//   Talk(SAY_ENTER_ZONE);
			//  _introDone = true;
			//}
		}

		void UpdateAI(uint32 const diff)
		{
			if (!UpdateVictim())				
				return;

			if (me->HasUnitState(UNIT_STAT_CASTING))
				return;

			events.Update(diff);
			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_WOUNDING:
					if(!IsHeroic())
					{
						DoCastVictim(SPELL_WOUNDING);
					} else {
						DoCastVictim(SPELL_WOUNDING_HERO);
					}                               
					events.ScheduleEvent(EVENT_WOUNDING, 8000);
					break;
				case EVENT_TOXIC_WASTE:
					if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 1)) {
						DoCast(unit, SPELL_TOXIC_WASTE);
					}
					events.ScheduleEvent(EVENT_TOXIC_WASTE,18000);
					break;
				case EVNET_CLEAVE:
					DoCastVictim(SPELL_CLEAVE);
					events.ScheduleEvent(EVNET_CLEAVE,3500);
					break;
				case EVENT_SPELL_HAMMER:
					if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 1)) {
						DoCast(unit,SPELL_HAMMER);
						//Talk(SAY_HAMMER);
					}
					events.ScheduleEvent(EVENT_SPELL_HAMMER,10000);
					break;
				case EVENT_SUMMON:
					me->SummonCreature(NPC_ADD, me->GetPositionX()+3.0f, me->GetPositionY()+5.0f, me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
					Talk(SAY_SUMMON);
					if(Is25ManRaid())
						//otro add
						me->SummonCreature(NPC_ADD, me->GetPositionX()+5.0f, me->GetPositionY()+7.0f, me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
					events.ScheduleEvent(EVENT_SUMMON,55000);
					break;
				case EVENT_ENRAGE:
					if(!me->HasAura(SPELL_BERSERK))
						DoCast(me,SPELL_BERSERK);
					break;
				default:
					break;
				}
			}             
			DoMeleeAttackIfReady();
		}
	private:
		bool _desperate;
	};  
	CreatureAI* GetAI(Creature* creature) const
	{
		return new boss_custom_iccAI(pCreature);
		//return GetIcecrownCitadelAI<boss_custom_iccAI>(creature);
	}
};    


class custom_add_icc : public CreatureScript
{
public:
	custom_add_icc() : CreatureScript("custom_add_icc") { }
	struct custom_add_iccAI : public ScriptedAI
	{
		custom_add_iccAI(Creature* creature) : ScriptedAI(creature)
		{}
		void Reset()
		{
			Events.Reset();
			Events.ScheduleEvent(EVENT_HEAL_VISUAL,20000);
		}
		void UpdateAI(uint32 const diff)
		{
			if (!me->getVictim())
				return;
			 Events.Update(diff);
			if (me->HasUnitState(UNIT_STAT_CASTING))
				return;
			while (uint32 eventId = Events.ExecuteEvent())
			{
				switch (eventId)
				{

				case EVENT_HEAL_VISUAL:
					Events.ScheduleEvent(EVENT_HEAL,1600);
					Talk(SAY_HEAL);
					DoCast(me,SPELL_ADD_HEAL_VISUAL);
					if(Is25ManRaid())
							Events.ScheduleEvent(EVENT_HEAL_VISUAL,10000);
						else
							Events.ScheduleEvent(EVENT_HEAL_VISUAL,15000);
				case EVENT_HEAL:
					if(Unit* owner = me->ToTempSummon()->GetSummoner())
					{
						DoCast(owner, SPELL_ADD_HEAL);						
					}
					break;
				default:
					break;
				}
			}
			DoMeleeAttackIfReady();
		}
	protected:
		EventMap Events;
		
	};
	CreatureAI* GetAI(Creature* pCreature) const
	{
		return new custom_add_iccAI(pCreature);
	}
};

void AddSC_boss_custom_icc()
{
	new  boss_custom_icc();
	new custom_add_icc();
}