#pragma once
#include "Menus.h"
class Player2WinsMenu :
    public Menus
{
public:
    Player2WinsMenu();

    void PrintMenu(CombatDataHandler& DataHandler);

    ~Player2WinsMenu();

};

