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

	//Consider taking out this function and just making the P1 Deck in Data Handler Directly
	CardHolder P1Deck;

	CardFactory Factory;

	//NEW CARD FACTORY FUNCTIONS
	Factory.CreateDummyAllCardsHolder(AllCardsContainer, FStreamCardHPVec);
	Factory.CreateAllCardsHolder(AllCardsContainer, FStreamCardHPVec, FStreamCardATTVec, FStreamCardNameVec, FStreamCardTypeVec);

	//NEW CARD FACTORY FUNCTIONS -- SUCCESSFUL INTEGRATION
	Factory.CreateDummyDeck(P1Deck);
	Factory.CreateP1StartingDeck(P1Deck, AllCardsContainer);

	//DANGEROUS!!! DELETE THIS ONCE MIGRATION TO DATA HANDLER IS DONE 
	DataHandler.P1Deck = P1Deck.Holder;

	Factory.CreateStoredDummyDecks(DataHandler);

	Broadcaster* BroadcastObj = new Broadcaster();

	Listener* ListenerObj = new Listener();

	//MAKE CARD FACTORY FUNCTION -- POPULATE DECK BUILDER
	//DataHandler.PopulateStartGameP1Deck(AllCardsContainer);

	//NEW CARD FACTORY FUNCTION
	Factory.CreateDummyDeckBuilderDeck(DataHandler.P1DeckBuilderDeck, AllCardsContainer);

	while (true)
	{
		//Will be deleted
		Renderer* RenderingObjects = new Renderer();

		MenuStack.top()->PrintMenu(DataHandler);

		ListenerObj->QuestsStorageVector.at(0)->PrintQuestInfo(RenderingObjects, 75, 10);

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
				//MAKE INTO CARD FACTORY FUNCTION
				//CardHolder P2Deck("Player2Deck", AllCardsContainer);
				//DataHandler.P2Deck = P2Deck.Holder;

				//FACTORY FUNCTIONS - SUCCESS
				CardHolder Player2Deck;
				Factory.CreateDummyP2Deck(Player2Deck, AllCardsContainer);
				DataHandler.P2Deck = Player2Deck.Holder;

				//MAKE CARD FACTORY FUNCTION
				//DataHandler.EstablishStoredDecks();

				//FACTORY FUNCTION -- SUCCESSFUL INTEGRATION
				
				Factory.CopyDecksToStoredDecks(P1Deck, Player2Deck, DataHandler);

				MenuStack.push(PreCombatTest);

				StartCombatMenu(DataHandler, BroadcastObj, ListenerObj);
			}
			else if (DataHandler.SelectionToBePassed == 1)
			{
				PlayerCatalogAndDeckBuilderMenu(DataHandler);
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

void BaseGameMode::StartCombatMenu(CombatDataHandler& DataHandler, Broadcaster* BroadcasterObj, Listener* ListenerObj)
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

				InitiateCombatMenu1(DataHandler, BroadcasterObj, ListenerObj);
			}
		}
		else
		{
			DataHandler.PostCombatValueReset();

			CardFactory Factory;
			Factory.ResetDecksForDataHandler(DataHandler);

			if (!MenuStack.empty())
			{
				MenuStack.pop();
				ListenerObj->UpdateForDefeatCardsQuests(BroadcasterObj);
				BroadcasterObj->ResetAllValues();
				delete TestingThisCombatMenu;
			}
			return;
		}
	}
}

void BaseGameMode::InitiateCombatMenu1(CombatDataHandler& DataHandler, Broadcaster* BroadcasterObj, Listener* ListenerObj)
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
				NewCombatLoop.BasicCombatSetup(DataHandler, BroadcasterObj);
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

void BaseGameMode::PlayerCatalogAndDeckBuilderMenu(CombatDataHandler& CombatHandler)
{
	DeckBuilderMenu* DeckBuilderMenuTest = new DeckBuilderMenu();

	MenuStack.push(DeckBuilderMenuTest);

	while (true)
	{
		Renderer CatalogRenderer;
		MenuStack.top()->PrintMenu(CombatHandler);

		//Move Right
		if (IsVirtualKeyPressed(0x32))
		{
			CombatHandler.IncreaseTargetValue();
		}
		//Move Left
		else if (IsVirtualKeyPressed(0x31))
		{
			CombatHandler.DecreaseTargetValue();
		}
		//Change to EditDeckMode
		else if (IsVirtualKeyPressed(0x34))
		{
			CombatHandler.ChangeEdit();
		}
		//Select a card to swap 
		else if (IsVirtualKeyPressed(0x35))
		{
			CombatHandler.SelectCardAndSwapState();
		}
		//Confirm Swap
		else if (IsVirtualKeyPressed(0x36))
		{
			CombatHandler.ConfirmSwap();
		}

		//Exit
		if (IsVirtualKeyPressed(0x33)) // 3 key
		{
			PlaySound(TEXT("ExitNoise.wav"), NULL, SND_ASYNC);
			MenuStack.pop();
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