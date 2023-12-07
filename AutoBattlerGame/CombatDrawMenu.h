#pragma once
#include "Menus.h"
#include "CombatDataHandler.h"

class CombatDrawMenu :
    public Menus
{

public:

    CombatDrawMenu();

    void PrintMenu(CombatDataHandler& DataHandler);

    ~CombatDrawMenu();
};

