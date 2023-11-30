#pragma once
#include "Menus.h"
#include "CombatDataHandler.h"

class InitiateCombatMenu :
    public Menus
{
public:

    InitiateCombatMenu();

    void PrintMenu(CombatDataHandler& DataHandler);

    ~InitiateCombatMenu();
};

