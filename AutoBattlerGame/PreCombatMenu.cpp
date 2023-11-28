#include "PreCombatMenu.h"

PreCombatMenu::PreCombatMenu()
{

}

void PreCombatMenu::PrintMenu(Renderer MenuRender, int SelectionVariable)
{
	MenuRender.DrawStringValue(CombatSelectionText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });
}

PreCombatMenu::~PreCombatMenu()
{

}
