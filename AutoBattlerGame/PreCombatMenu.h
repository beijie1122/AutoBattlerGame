#pragma once
#include "Menus.h"

class PreCombatMenu :
    public Menus
{

    std::vector<int> XCoordVec{ 5, 14, 23, 31 };

    int YCoord = 7;

public:

    std::string CombatMenuFrontText = "Front";

    std::string CombatMenuBackText = "Back";

    std::string CombatMenuTargetText = "Target";

    std::string PreCombatMenuText = "Combat Setup";

    std::string CombatInitializedText = "Combat Started";

    std::string CombatSelectionText = "Press 3 to start combat";

    PreCombatMenu();

    void PrintMenu(CombatDataHandler& DataHandler);

    ~PreCombatMenu();
};

