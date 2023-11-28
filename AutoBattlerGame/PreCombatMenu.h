#pragma once
#include "Menus.h"

class PreCombatMenu :
    public Menus
{

public:

    PreCombatMenu();

    void PrintMenu(Renderer MenuRender, int SelectionVariable);

    ~PreCombatMenu();
};

