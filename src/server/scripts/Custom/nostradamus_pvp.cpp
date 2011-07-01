/* 
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2011-2012 Gamerlive <https://wow.gamerlive.cl/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"

/*  Informacion NPC-Spell-Gobject 
* Tipo		: [NPC] Custom Boss 
* Nombre	: Nostradamus
* Propocito	: Fomentar PVP
* Script	: Base 0%
*/

enum Yells
{
    SAY_AGGRO                                   = -1999900,
    SAY_RANDOM_0                                = -1999901,
    SAY_RANDOM_1                                = -1999902,
    SAY_RANDOM_2                                = -1999903,
    SAY_RANDOM_3                                = -1999904,
    SAY_RANDOM_4                                = -1999905,
    SAY_BERSERK                                 = -1999906,
    SAY_PHASE                                   = -1999907,
    SAY_DANCE                                   = -1999908,
    SAY_SALUTE                                  = -1999909,
    SAY_EVADE                                   = -1999910,
};

enum Spells
{
    SPELL_BUFF                                  = 25661,
    SPELL_ONE                                   = 12555,
    SPELL_ONE_ALT                               = 24099,
    SPELL_TWO                                   = 10017,
    SPELL_THREE                                 = 26027,
    SPELL_FRENZY                                = 23537,
    SPELL_BERSERK                               = 32965,
};

enum eEnums
{
    FACTION_HOSTIL                              = 14
};

//List of gossip item texts. Items will appear in the gossip window.
#define GOSSIP_ITEM     "I'm looking for a fight"

class nostradamus_pvp : public CreatureScript
{
    public:

        nostradamus_pvp()
            : CreatureScript("nostradamus_pvp")
        {
        }

        struct nostradamus_pvpAI : public ScriptedAI
        {
            // *** HANDLED FUNCTION ***
            //This is the constructor, called only once when the Creature is first created
            nostradamus_pvpAI(Creature *c) : ScriptedAI(c) {}

            // *** CUSTOM VARIABLES ****
            //These variables are for use only by this individual script.
            //Nothing else will ever call them but us.

            uint32 m_uiSayTimer;                                    // Timer for random chat
            uint32 m_uiRebuffTimer;                                 // Timer for rebuffing
            uint32 m_uiSpell1Timer;                                 // Timer for spell 1 when in combat
            uint32 m_uiSpell2Timer;                                 // Timer for spell 1 when in combat
            uint32 m_uiSpell3Timer;                                 // Timer for spell 1 when in combat
            uint32 m_uiBeserkTimer;                                 // Timer until we go into Beserk (enraged) mode
            uint32 m_uiPhase;                                       // The current battle phase we are in
            uint32 m_uiPhaseTimer;                                  // Timer until phase transition

            // *** HANDLED FUNCTION ***
            //This is called after spawn and whenever the core decides we need to evade
            void Reset()
            {
                m_uiPhase = 1;                                      // Start in phase 1
                m_uiPhaseTimer = 60000;                             // 60 seconds
                m_uiSpell1Timer = 5000;                             //  5 seconds
                m_uiSpell2Timer = urand(10000, 20000);               // between 10 and 20 seconds
                m_uiSpell3Timer = 19000;                            // 19 seconds
                m_uiBeserkTimer = 120000;                           //  2 minutes

                me->RestoreFaction();
            }

            // *** HANDLED FUNCTION ***
            // Enter Combat called once per combat
            void EnterCombat(Unit* pWho)
            {
                //Say some stuff
                DoScriptText(SAY_AGGRO, me, pWho);
            }

            // *** HANDLED FUNCTION ***
            // Attack Start is called when victim change (including at start of combat)
            // By default, attack pWho and start movement toward the victim.
            //void AttackStart(Unit* pWho)
            //{
            //    ScriptedAI::AttackStart(pWho);
            //}

            // *** HANDLED FUNCTION ***
            // Called when going out of combat. Reset is called just after.
            void EnterEvadeMode()
            {
                DoScriptText(SAY_EVADE, me);
            }

            // *** HANDLED FUNCTION ***
            //Our Receive emote function
            void ReceiveEmote(Player* /*pPlayer*/, uint32 uiTextEmote)
            {
                me->HandleEmoteCommand(uiTextEmote);

                switch(uiTextEmote)
                {
                    case TEXT_EMOTE_DANCE:
                        DoScriptText(SAY_DANCE, me);
                        break;
                    case TEXT_EMOTE_SALUTE:
                        DoScriptText(SAY_SALUTE, me);
                        break;
                }
             }

            // *** HANDLED FUNCTION ***
            //Update AI is called Every single map update (roughly once every 50ms if a player is within the grid)
            void UpdateAI(const uint32 uiDiff)
            {
                //Out of combat timers
                if (!me->getVictim())
                {
                    //Random Say timer
                    if (m_uiSayTimer <= uiDiff)
                    {
                        //Random switch between 5 outcomes
                        DoScriptText(RAND(SAY_RANDOM_0, SAY_RANDOM_1, SAY_RANDOM_2, SAY_RANDOM_3, SAY_RANDOM_4), me);

                        m_uiSayTimer = 45000;                      //Say something agian in 45 seconds
                    }
                    else
                        m_uiSayTimer -= uiDiff;

                    //Rebuff timer
                    if (m_uiRebuffTimer <= uiDiff)
                    {
                        DoCast(me, SPELL_BUFF);
                        m_uiRebuffTimer = 900000;                  //Rebuff agian in 15 minutes
                    }
                    else
                        m_uiRebuffTimer -= uiDiff;
                }

                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //Spell 1 timer
                if (m_uiSpell1Timer <= uiDiff)
                {
                    //Cast spell one on our current target.
                    if (rand()%50 > 10)
                        DoCast(me->getVictim(), SPELL_ONE_ALT);
                    else if (me->IsWithinDist(me->getVictim(), 25.0f))
                        DoCast(me->getVictim(), SPELL_ONE);

                    m_uiSpell1Timer = 5000;
                }
                else
                    m_uiSpell1Timer -= uiDiff;

                //Spell 2 timer
                if (m_uiSpell2Timer <= uiDiff)
                {
                    //Cast spell two on our current target.
                    DoCast(me->getVictim(), SPELL_TWO);
                    m_uiSpell2Timer = 37000;
                }
                else
                    m_uiSpell2Timer -= uiDiff;

                //Beserk timer
                if (m_uiPhase > 1)
                {
                    //Spell 3 timer
                    if (m_uiSpell3Timer <= uiDiff)
                    {
                        //Cast spell one on our current target.
                        DoCast(me->getVictim(), SPELL_THREE);

                        m_uiSpell3Timer = 19000;
                    }
                    else
                        m_uiSpell3Timer -= uiDiff;

                    if (m_uiBeserkTimer <= uiDiff)
                    {
                        //Say our line then cast uber death spell
                        DoScriptText(SAY_BERSERK, me, me->getVictim());
                        DoCast(me->getVictim(), SPELL_BERSERK);

                        //Cast our beserk spell agian in 12 seconds if we didn't kill everyone
                        m_uiBeserkTimer = 12000;
                    }
                    else
                        m_uiBeserkTimer -= uiDiff;
                }
                else if (m_uiPhase == 1)                            //Phase timer
                {
                    if (m_uiPhaseTimer <= uiDiff)
                    {
                        //Go to next phase
                        ++m_uiPhase;
                        DoScriptText(SAY_PHASE, me);
                        DoCast(me, SPELL_FRENZY);
                    }
                    else
                        m_uiPhaseTimer -= uiDiff;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new nostradamus_pvpAI(pCreature);
        }
};

void AddSC_nostradamus_pvp()
{
    new nostradamus_pvp();
}