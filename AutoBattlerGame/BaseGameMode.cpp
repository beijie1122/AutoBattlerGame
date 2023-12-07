#include "BaseGameMode.h"
#include <Windows.h>
#include <mmsystem.h>

BaseGameMode::BaseGameMode()
{
	FStreamExtractor GameSetupDataExtraction;

	GameSetupDataExtraction.FStreamCardDataExtraction(GameSetupDataExtraction.FStreamFileCardInfo, FStreamCardNameVec, FStreamCardHPVec, FStreamCardATTVec, FStreamCardTypeVec);
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

	CardHolder AllCardsContainer;

	CardHolder P1Deck;

	AllCardsContainer.PopulateAllCardsVector(FStreamCardHPVec, FStreamCardATTVec, FStreamCardNameVec, FStreamCardTypeVec);

	P1Deck.PopulatePlayer1BaseDeck(AllCardsContainer);

	DataHandler.P1Deck = P1Deck.Holder;

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
			PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);
			if (DataHandler.SelectionToBePassed == 0)
			{
				//Make into it's own function 
				CardHolder P2Deck("Player2Deck", AllCardsContainer);
				DataHandler.P2Deck = P2Deck.Holder;
				DataHandler.EstablishStoredDecks();

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
	InitiateCombatMenu* TestingThisCombatMenu = new InitiateCombatMenu();
	while (true)
	{
		if (DataHandler.IsCombatFinished == false)
		{
			//NOT SURE WHY DELETING THIS MESSES UP THE RENDERER
			Renderer RenderStartBattle;

			MenuStack.top()->PrintMenu(DataHandler);

			if (IsVirtualKeyPressed(0x33)) //3 key
			{
				PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);

				MenuStack.push(TestingThisCombatMenu);

				InitiateCombatMenu1(DataHandler);
			}
		}
		else
		{

			DataHandler.PostCombatValueReset();
			if (!MenuStack.empty())
			{
				MenuStack.pop();
				delete TestingThisCombatMenu;
				
			}
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
				PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);
				NewCombatLoop.BasicCombatSetup(DataHandler);
			}
		}
		else
		{
			
			if (DataHandler.Player1Wins == true)
			{
				DisplayPlayer1WinsMenu(DataHandler);
			}
			else if (DataHandler.Player2Wins == true)
			{
				DisplayPlayer2WinsMenu(DataHandler);
			}
			else if (DataHandler.CombatResultsInADraw == true)
			{
				DisplayCombatDrawMenu(DataHandler);
			}
			
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

void BaseGameMode::DisplayPlayer1WinsMenu(CombatDataHandler& DataHandler)
{
	PlaySound(TEXT("Victory_Fanfare.wav"), NULL, SND_ASYNC);
	Renderer NewRender;
	Player1WinsMenu* Player1WinMenu = new Player1WinsMenu();
	MenuStack.push(Player1WinMenu);
	while (true)
	{
		MenuStack.top()->PrintMenu(DataHandler);
		if (IsVirtualKeyPressed(0x35))
		{
			//Stops playing the victory fanfare
			PlaySound(NULL, NULL, 0);
			if (!MenuStack.empty())
			{
				PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);
				MenuStack.pop();
				delete Player1WinMenu;
				return;
			}
		}
	}
}

void BaseGameMode::DisplayPlayer2WinsMenu(CombatDataHandler& DataHandler)
{
	Renderer NewRender;
	Player2WinsMenu* Player2WinMenu = new Player2WinsMenu();
	MenuStack.push(Player2WinMenu);
	while (true)
	{
		MenuStack.top()->PrintMenu(DataHandler);
		if (IsVirtualKeyPressed(0x35))
		{
			PlaySound(NULL, NULL, 0);
			if (!MenuStack.empty())
			{
				PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);
				MenuStack.pop();
				delete Player2WinMenu;
				return;
			}

		}
	}
}

void BaseGameMode::DisplayCombatDrawMenu(CombatDataHandler& DataHandler)
{
	Renderer AnotherRender;
	CombatDrawMenu* DrawMenuObject = new CombatDrawMenu();
	MenuStack.push(DrawMenuObject);
	while (true)
	{
		MenuStack.top()->PrintMenu(DataHandler);
		if (IsVirtualKeyPressed(0x35))
		{
			PlaySound(NULL, NULL, 0);
			if (!MenuStack.empty())
			{
				PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);
				MenuStack.pop();
				delete DrawMenuObject;
				return;
			}
		}
	}
}

BaseGameMode::~BaseGameMode()
{

}