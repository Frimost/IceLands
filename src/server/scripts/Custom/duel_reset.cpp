#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "Config.h"

class duel_reset : public PlayerScript
{
    public:
        duel_reset() : PlayerScript("duel_reset") {}

    void OnDuelEnd(Player *winner, Player *looser, DuelCompleteType type)
    {
        // reset cooldowns in elwynn forest and durotar
        if (winner->GetZoneId() == 14 || winner->GetZoneId() == 12)
        {
            if (type == DUEL_WON)
            {
			    //Remove Cooldowns
                winner->RemoveArenaSpellCooldowns();
                looser->RemoveArenaSpellCooldowns();
				/* descomentar si se quiere restaurar hp/mana
				// Restore HP
                winner->SetHealth(winner->GetMaxHealth());
                looser->SetHealth(looser->GetMaxHealth());
				//Restore Mana
                if (winner->getPowerType() == POWER_MANA) 
                    winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));

                if (looser->getPowerType() == POWER_MANA) 
                    looser->SetPower(POWER_MANA, looser->GetMaxPower(POWER_MANA));
				*/
            }
        }
    }
};

void AddSC_DuelReset()
{
    new duel_reset;
}
