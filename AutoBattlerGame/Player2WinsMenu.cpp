#include "Player2WinsMenu.h"

Player2WinsMenu::Player2WinsMenu()
{
}

void Player2WinsMenu::PrintMenu(CombatDataHandler& DataHandler)
{
	DataHandler.RenderObject.DrawStringValue("You lose!!!", { 20, 15 });
}

Player2WinsMenu::~Player2WinsMenu()
{
}
