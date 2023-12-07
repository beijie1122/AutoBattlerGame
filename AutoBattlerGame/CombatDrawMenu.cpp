#include "CombatDrawMenu.h"

CombatDrawMenu::CombatDrawMenu()
{
}

void CombatDrawMenu::PrintMenu(CombatDataHandler& DataHandler)
{
	DataHandler.RenderObject.DrawStringValue("That's a Draw, no winner!", { 20, 15 });
	DataHandler.RenderObject.DrawStringValue("Press 5 to exit this menu", { 20, 17 });
}

CombatDrawMenu::~CombatDrawMenu()
{
}
