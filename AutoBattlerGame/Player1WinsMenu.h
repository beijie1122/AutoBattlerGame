#pragma once
#include "Menus.h"
class Player1WinsMenu :
    public Menus
{
public:
    Player1WinsMenu();

    void PrintMenu(CombatDataHandler& DataHandler);

    ~Player1WinsMenu();

};

