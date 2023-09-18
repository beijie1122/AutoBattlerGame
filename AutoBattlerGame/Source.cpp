#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "LLNodeOperations.h"
#include "Renderer.h"
#include <Windows.h>
#include "CombatLoop.h"
#include "Menus.h"
#include "BaseGameMode.h"



int main()
{
	InitializeRenderer();

	Renderer MainRender;

	std::unique_ptr<BaseGameMode> BaseGame = std::make_unique<BaseGameMode>();

	BaseGame->MainMenuMode();
	
	return 0;
}