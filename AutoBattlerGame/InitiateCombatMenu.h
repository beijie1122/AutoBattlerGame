#pragma once
#include "Menus.h"
#include "CombatDataHandler.h"

class InitiateCombatMenu :
    public Menus
{
public:

    std::string CombatMenuTargetText = "Target";

    std::string CombatInitializedText = "Combat Started";

    std::string InitiateCombatText = "Press 4 to move along combat";

    InitiateCombatMenu();

    void PrintMenu(CombatDataHandler& DataHandler);

    ~InitiateCombatMenu();
};

