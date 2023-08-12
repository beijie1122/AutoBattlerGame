#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "LLNodeOperations.h"
#include "Renderer.h"
#include <Windows.h>
#include "CombatLoop.h"
#include "Menus.h"

bool IsVirtualKeyPressed(int VirtKey)
{
	return GetAsyncKeyState(VirtKey) != 0;
}

int main()
{
	InitializeRenderer();

	Menus TestMenu;

	int SelctionToBePassed = 0;

	/*
	while (true)
	{
		
		Renderer RenderingObjects;
		TestMenu.MainGameMenu(RenderingObjects, SelctionToBePassed);

		if (IsVirtualKeyPressed(0x57))
		{
			if (SelctionToBePassed != 0)
			{
				SelctionToBePassed--;
			}
			
		}
		if (IsVirtualKeyPressed(0x53))
		{
			if (SelctionToBePassed < 2)
			{
				SelctionToBePassed++;
			}
		}
	}
	*/
	Renderer RenderingObjects;

	std::vector<int> CardHealth{ 1, 2, 5, 4};
	std::vector<int> CardAttack{ 2, 1, 1, 2 };
	std::vector<std::string> CardName{ "Guard", "Trooper", "Attacker", "Backup" };

	std::vector<int> P2CardHealth{1, 1, 1, 1};
	std::vector<int> P2CardAttack{1, 2, 1, 1};
	std::vector<std::string> P2CardName{ "Guard", "Trooper", "Attacker", "Backup" };

	std::vector<int> XCoordVec{ 5, 12, 19, 26};

	std::vector<int> P2XCoordVec{50, 57, 64, 71};

	int YCoord = 7;

	bool IsCombatSetup = false;

	Node* Player1CardCatalog = new Node();

	Node* Player2Board = new Node();

	LLNodeOperations PerformOperationsObject;

	CombatLoop PerformCombatObject;

	Player1CardCatalog = PerformOperationsObject.TakeInputFromVector(CardHealth, CardAttack, CardName);

	Player2Board = PerformOperationsObject.TakeInputFromVector(P2CardHealth, P2CardAttack, P2CardName);


	while (true)
	{
		Renderer RenderingObjects;

		PerformOperationsObject.print(Player1CardCatalog, RenderingObjects, XCoordVec, YCoord);

		PerformOperationsObject.print(Player2Board, RenderingObjects, P2XCoordVec, YCoord);

		if (IsVirtualKeyPressed(VK_NUMPAD1))
		{
			PerformCombatObject.BasicCombatSetup(Player1CardCatalog, Player2Board, IsCombatSetup, RenderingObjects);
		}

		//PerformOperationsObject.print(Player1CardCatalog, RenderingObjects);
	}

	

	return 0;
}