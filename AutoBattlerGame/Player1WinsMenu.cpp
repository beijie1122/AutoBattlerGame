#include "Player1WinsMenu.h"

Player1WinsMenu::Player1WinsMenu()
{

}

void Player1WinsMenu::PrintMenu(CombatDataHandler& DataHandler)
{
	DataHandler.RenderObject.DrawStringValue("You Win!!!", { 20, 15 });
	DataHandler.RenderObject.DrawStringValue("Press 5 to exit this menu", { 20, 17 });
}

Player1WinsMenu::~Player1WinsMenu()
{

}
