#pragma once
#include "Menus.h"

class PreCombatMenu :
    public Menus
{

    std::vector<int> XCoordVec{ 5, 14, 23, 31 };

    int YCoord = 7;

public:

    PreCombatMenu();

    void PrintMenu(CombatDataHandler& DataHandler);

    ~PreCombatMenu();
};

