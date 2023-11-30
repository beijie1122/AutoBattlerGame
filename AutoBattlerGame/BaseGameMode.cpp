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

	MainMenu *TestMainMenu = new MainMenu();

	PreCombatMenu* PreCombatTest = new PreCombatMenu();

	CombatDataHandler DataHandler;

	//STACK FOR MENUS
	MenuStack.push(TestMainMenu);

	CardHolder P1Deck;

	P1Deck.PopulateAllCardsVector(FStreamCardHPVec, FStreamCardATTVec, FStreamCardNameVec);

	CardHolder P2Deck;

	P2Deck.PopulateAllCardsVector(P2CardHealth, P2CardAttack, P2CardName);

	DataHandler.P1Deck = P1Deck.Holder;

	DataHandler.P2Deck = P2Deck.Holder;

	DataHandler.EstablishStoredDecks();

	

	while (true)
	{
		//Will be deleted
		Renderer* RenderingObjects = new Renderer();

		MenuStack.top()->PrintMenu(DataHandler);

		if (IsVirtualKeyPressed(0x57))
		{
			if (DataHandler.SelectionToBePassed != 0)
			{
				DataHandler.SelectionToBePassed--;
			}
			PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);

		}
		else if (IsVirtualKeyPressed(0x53))
		{
			if (DataHandler.SelectionToBePassed < 2)
			{
				DataHandler.SelectionToBePassed++;
			}
			PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);
		}
		else if (IsVirtualKeyPressed(0x32)) //2 Key
		{
			if (DataHandler.SelectionToBePassed == 0)
			{
				MenuStack.push(PreCombatTest);
				StartCombatMenu(DataHandler);
			}
			else if (DataHandler.SelectionToBePassed == 1)
			{
				//PlayerCatalogAndDeckBuilderMenu(PlayerOwnedCards, Player1CardCatalog, PerformOperationsObject);
			}
			else if (DataHandler.SelectionToBePassed == 2)
			{
				//Bestiary
				//BestiaryMenu(PerformOperationsObject, Bestiary, *RenderingObjects);
			}
		}

		delete RenderingObjects;
	}
}

void BaseGameMode::StartCombatMenu(CombatDataHandler& DataHandler)
{
	
	while (true)
	{
		if (DataHandler.IsCombatFinished == false)
		{
			//NOT SURE WHY DELETING THIS MESSES UP THE RENDERER
			Renderer RenderStartBattle;

			MenuStack.top()->PrintMenu(DataHandler);

			if (IsVirtualKeyPressed(0x33)) //3 key
			{
				InitiateCombatMenu* TestingThisCombatMenu = new InitiateCombatMenu();

				MenuStack.push(TestingThisCombatMenu);

				InitiateCombatMenu1(DataHandler);
			}
		}
		else
		{
			DataHandler.PostCombatValueReset();
			MenuStack.pop();
			return;
		}
	}
}

void BaseGameMode::InitiateCombatMenu1(CombatDataHandler& DataHandler)
{

	while (true)
	{
		if (DataHandler.IsCombatFinished == false)
		{
			Renderer RenderThiscombat;

			MenuStack.top()->PrintMenu(DataHandler);

			CombatLoopUsingVector NewCombatLoop;

			if (IsVirtualKeyPressed(0x34)) //4 Key
			{
				NewCombatLoop.BasicCombatSetup(DataHandler);
			}
		}
		else
		{
			MenuStack.pop();
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
			PlaySound(TEXT("ExitNoise.wav"), NULL, SND_ASYNC);
			break;
		}

	}

}

BaseGameMode::~BaseGameMode()
{

}