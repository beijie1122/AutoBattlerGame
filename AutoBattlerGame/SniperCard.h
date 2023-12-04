#pragma once
#include "VanillaCards.h"
#include "CombatDataHandler.h"
class SniperCard :
    public VanillaCards
{
public:

    std::string SniperType = "Sniper";

    SniperCard();

    SniperCard(int HP, int ATT, std::string NamePassed);

    void PreCombatAbility(CombatDataHandler& DataHandler, std::string Owner);

    ~SniperCard();
};

