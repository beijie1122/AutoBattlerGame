#pragma once
#include "VanillaCards.h"
#include "CombatDataHandler.h"

class OnDeathCards :
    public VanillaCards
{
public:

    OnDeathCards();

    OnDeathCards(int HP, int ATT, std::string NamePassed, std::string Type);

    void OnDeathEffect(CombatDataHandler& DataHandler, std::string Owner);

    ~OnDeathCards();
};

