#pragma once
#include "Menus.h"

class DeckBuilderMenu :
    public Menus
{

public:

    DeckBuilderMenu();

    void PrintMenu(CombatDataHandler& DataHandler);

    ~DeckBuilderMenu();

};

