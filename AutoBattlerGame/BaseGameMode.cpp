#include "BaseGameMode.h"

BaseGameMode::BaseGameMode()
{
	FStreamExtractor GameSetupDataExtraction;

	GameSetupDataExtraction.FStreamCardDataExtraction(GameSetupDataExtraction.FStreamFileCardInfo, FStreamCardNameVec, FStreamCardHPVec, FStreamCardATTVec);
}

bool IsVirtualKeyPressed(int VirtKey)
{
	return GetAsyncKeyState(VirtKey) != 0;
}

void BaseGameMode::MainMenuMode()
{
	Menus TestMenu; // Consider making a ptr in Int Main and passing it 

	Node* Player1CardCatalog = new Node();

	Node* Player2Board = new Node();

	Node* Bestiary = new Node();

	LLNodeOperations PerformOperationsObject;

	CombatLoop PerformCombatObject;

	Player1CardCatalog = PerformOperationsObject.TakeInputFromVector(FStreamCardHPVec, FStreamCardATTVec, FStreamCardNameVec);

	//Player1CardCatalog = PerformOperationsObject.TakeInputFromVector(CardHealth, CardAttack, CardName);

	Player2Board = PerformOperationsObject.TakeInputFromVector(P2CardHealth, P2CardAttack, P2CardName);

	Bestiary = PerformOperationsObject.SetupBestiary();

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

		if (IsVirtualKeyPressed(0x32)) //2 Key
		{
			if (SelctionToBePassed == 0)
			{
				StartCombatMenu(Player1CardCatalog, Player2Board, IsCombatFinished);
			}
			else if (SelctionToBePassed == 1)
			{
				//View Cards Menu
			}
			else if (SelctionToBePassed == 2)
			{
				//Bestiary
				BestiaryMenu(PerformOperationsObject, Bestiary, RenderingObjects);
			}
		}
	}
}

void BaseGameMode::StartCombatMenu(Node* Player1Board, Node* Player2Board, bool &IsCombatFinished)
{
	LLNodeOperations PerformOperationsObject;

	CombatLoop PerformCombatObject;

	Node* P1Copy = PerformOperationsObject.CopyDataValueofLinkedList(Player1Board);
	Node* P2Copy = PerformOperationsObject.CopyDataValueofLinkedList(Player2Board);
	IsCombatFinished = false;
	
	while (true)
	{
		if (IsCombatFinished == false)
		{
			Renderer RenderStartBattle;
			Menus CombatMenu;

			CombatMenu.StartCombatMenu(RenderStartBattle);

			PerformOperationsObject.print(P1Copy, RenderStartBattle, XCoordVec, YCoord);

			if (IsVirtualKeyPressed(0x33)) //3 key
			{
				InitiateCombatMenu(P1Copy, P2Copy, PerformOperationsObject, PerformCombatObject, IsCombatFinished);
			}
		}
		else
		{
			return;
			delete P1Copy;
			delete P2Copy;
		}
	}
}

void BaseGameMode::InitiateCombatMenu(Node* Player1Board, Node* Player2Board, LLNodeOperations NodeOperations, CombatLoop CombatObject, bool &IsCombatFinished)
{

	while (true)
	{
		if (IsCombatFinished == false)
		{
			Renderer RenderThiscombat;

			Menus InitiateCombatMenu;

			InitiateCombatMenu.InitiateCombatMenu(RenderThiscombat);

			NodeOperations.print(Player1Board, RenderThiscombat, XCoordVec, YCoord);
			NodeOperations.print(Player2Board, RenderThiscombat, P2XCoordVec, YCoord);

			if (IsVirtualKeyPressed(0x34)) //4 Key
			{
				CombatObject.BasicCombatSetup(Player1Board, Player2Board, IsCombatSetup, RenderThiscombat, IsCombatFinished);
			}
		}
		else
		{

			//while (true)
			//{

				//CombatObject.WinOrLoseState();
				//if (IsVirtualKeyPressed(VK_NUMPAD4))
				//{
				//	IsCombatSetup = false;
				//	IsCombatFinished = false;
				//	return;
				//}
			//}
			IsCombatSetup = false;
			//IsCombatFinished = false;
			return;
		}

	}
}

void BaseGameMode::BestiaryMenu(LLNodeOperations BestiaryHandler, Node* Bestiary, Renderer BestiaryRender)
{
	while (true)
	{

		Renderer BestiaryRender2;

		Menus BestiaryMenuItem;
		BestiaryMenuItem.InitiateBestiaryMenu(BestiaryRender2);

		BestiaryHandler.PrintBestiary(Bestiary, BestiaryRender2);

		if (IsVirtualKeyPressed(0x33)) // 3 key
		{
			break;
		}

	}
	
}

BaseGameMode::~BaseGameMode()
{

}