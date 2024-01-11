#pragma once
#include "Menus.h"
#include <string>
#include <vector>

class DeckBuilderMenu :
    public Menus
{
    std::vector<int> YCoordVector{ 4, 5, 6, 7, 10, 11, 12, 13 };

    int XCoord = 90;

    std::vector<std::string> MenuButtonDescription{ "Selection:", "Press 1 to Move Left", "Press 2 to Move Right",
    "Press 4 to Swap Deck and Collection", "Deck Editor:", "Press 5 to Select a Card to Replace", "Press 6 to confirm replacement card", 
        "Press 3 to Exit Menu"};

public:

    DeckBuilderMenu();

    void PrintMenu(CombatDataHandler& DataHandler);

    ~DeckBuilderMenu();

};

