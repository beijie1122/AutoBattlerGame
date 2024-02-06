#pragma once
#include "Menus.h"


class MainMenu : public Menus

{
public:

    MainMenu();

    void PrintMenu(CombatDataHandler& DataHandler);

    ~MainMenu();

};

