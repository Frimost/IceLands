#include "ScriptPCH.h"

enum Zones
{
    ZONE_ELWYNN_FOREST = 12,
    ZONE_DUROTAR = 14,
    ZONE_DALARAN = 4395,
};

class duel_reset : public PlayerScript
{
    public:
        duel_reset() : PlayerScript("duel_reset") {}

    void OnDuelEnd(Player* winner, Player* loser, DuelCompleteType type)
    {
        if (type == DUEL_WON)
        {
            switch (winner->GetZoneId())
            {
                case ZONE_ELWYNN_FOREST:
                case ZONE_DUROTAR:
                case ZONE_DALARAN:
                    winner->RemoveArenaSpellCooldowns();
                    loser->RemoveArenaSpellCooldowns();

                    winner->SetHealth(winner->GetMaxHealth());
                    loser->SetHealth(loser->GetMaxHealth());

                    if (winner->getPowerType() == POWER_MANA)
                        winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));

                    if (loser->getPowerType() == POWER_MANA)
                        loser->SetPower(POWER_MANA, loser->GetMaxPower(POWER_MANA));

                    break;
            }
        }
    }
};

void AddSC_DuelReset()
{
    new duel_reset;
}

