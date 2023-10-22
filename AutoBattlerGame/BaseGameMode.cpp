#include "BaseGameMode.h"
#include <Windows.h>
#include <mmsystem.h>

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

	Node* PlayerOwnedCards = new Node();

	LLNodeOperations PerformOperationsObject;

	CombatLoop PerformCombatObject;

	Player1CardCatalog = PerformOperationsObject.TakeInputFromVector(FStreamCardHPVec, FStreamCardATTVec, FStreamCardNameVec);

	PlayerOwnedCards = PerformOperationsObject.SetupBestiary();

	PlayerOwnedCards = PerformOperationsObject.SetupPlayerCardCatalog(PlayerOwnedCards, Player1CardCatalog);

	//PlayerOwnedCards = PerformOperationsObject.TakeInputFromVector(FStreamCardHPVec, FStreamCardATTVec, FStreamCardNameVec);

	Player2Board = PerformOperationsObject.TakeInputFromVector(P2CardHealth, P2CardAttack, P2CardName);

	Bestiary = PerformOperationsObject.SetupBestiary();

	

	while (true)
	{
		//Renderer RenderingObjects;

		Renderer* RenderingObjects = new Renderer();

		TestMenu.MainGameMenu(*RenderingObjects, SelctionToBePassed);

		if (IsVirtualKeyPressed(0x57))
		{
			if (SelctionToBePassed != 0)
			{
				SelctionToBePassed--;
			}
			PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);

		}
		else if (IsVirtualKeyPressed(0x53))
		{
			if (SelctionToBePassed < 2)
			{
				SelctionToBePassed++;
			}
			PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);
		}
		else if (IsVirtualKeyPressed(0x32)) //2 Key
		{
			if (SelctionToBePassed == 0)
			{
				StartCombatMenu(Player1CardCatalog, Player2Board, IsCombatFinished);
			}
			else if (SelctionToBePassed == 1)
			{
				PlayerCatalogAndDeckBuilderMenu(PlayerOwnedCards, Player1CardCatalog, PerformOperationsObject);
			}
			else if (SelctionToBePassed == 2)
			{
				//Bestiary
				BestiaryMenu(PerformOperationsObject, Bestiary, *RenderingObjects);
			}
		}

		delete RenderingObjects;
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
			CombatMenu.CombatMenuFirstAndLastPreview(RenderStartBattle, XCoordVec, YCoord);

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
			InitiateCombatMenu.CombatInitiatedMenu(RenderThiscombat, XCoordVec, P2XCoordVec, YCoord, TargetingP1VecLocation, TargetingP2VecLocation);

			NodeOperations.print(Player1Board, RenderThiscombat, XCoordVec, YCoord);
			NodeOperations.print(Player2Board, RenderThiscombat, P2XCoordVec, YCoord);

			if (IsVirtualKeyPressed(0x34)) //4 Key
			{
				CombatObject.BasicCombatSetup(Player1Board, Player2Board, IsCombatSetup, RenderThiscombat, IsCombatFinished, TargetingP1VecLocation, TargetingP2VecLocation);
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
			TargetingP1VecLocation = 3;
			TargetingP2VecLocation = 0;
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
		BestiaryMenuItem.PrintBestiarySelection(BestiaryRender2);

		BestiaryHandler.PrintBestiary(Bestiary, BestiaryRender2);

		if (IsVirtualKeyPressed(0x33)) // 3 key
		{
			//Make sound for Exit Noise 
			PlaySound(TEXT("ExitNoise.wav"), NULL, SND_ASYNC);
			break;
		}

	}
	
}

void BaseGameMode::PlayerCatalogAndDeckBuilderMenu(Node* PlayerCatalog, Node* PlayerDeck, LLNodeOperations CatalogHandler)
{

	while (true)
	{
		Menus CatalogMenuItem;
		Renderer CatalogRenderer;

		if (IsPlayerViewingCatalog == true)
		{
			//code for viewing catalog
			CatalogMenuItem.PlayerIsViewingCardCatalogMenu(CatalogRenderer, CatalogHandler.BestiaryXCOORD, CatalogHandler.BestiaryYCOORD, CardCatalogXCOORDTargetVec.at(CardCatalogXCOORDTarget), CardCatalogYCOORDTargetVec.at(CardCatalogYCoordTarget));
			CatalogMenuItem.CardCatalogAndDeckBuilderMenu(CatalogRenderer);
			CatalogHandler.PrintPlayerCatalog(PlayerCatalog, PlayerDeck, CatalogRenderer);

			if (IsVirtualKeyPressed(0x31))
			{
				if (CardCatalogXCOORDTarget == 4)
				{
					CardCatalogYCoordTarget = 1;
					CardCatalogXCOORDTarget = 0;
				}
				else
				{
					CardCatalogXCOORDTarget++;
				}

			}
			else if (IsVirtualKeyPressed(0x32))
			{
				CardCatalogXCOORDTarget--;
			}

		}
		else if (IsPlayerViewingDeck == true)
		{
			//code for Viewing Deck
		}
		else if (IsPlayerReplacingACard == true)
		{
			//replace Card Logic
		}



		if (IsVirtualKeyPressed(0x33)) // 3 key
		{
			break;
		}

	}

}

BaseGameMode::~BaseGameMode()
{

}