#include "Player2WinsMenu.h"

Player2WinsMenu::Player2WinsMenu()
{
}

void Player2WinsMenu::PrintMenu(CombatDataHandler& DataHandler)
{
	DataHandler.RenderObject.DrawStringValue("You lose!!!", { 20, 15 });
	DataHandler.RenderObject.DrawStringValue("Press 5 to exit this menu", { 20, 17 });
}

Player2WinsMenu::~Player2WinsMenu()
{
}
