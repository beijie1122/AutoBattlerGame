#pragma once
#include "Menus.h"


class MainMenu : public Menus

{
public:

    MainMenu();

    void PrintMenu(Renderer MenuRender, int SelectionVariable);

    ~MainMenu();

};

