#include "BaseGameMode.h"
#include <Windows.h>

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

	CardFactory Factory;

	//NEW CARD FACTORY FUNCTIONS
	Factory.CreateDummyAllCardsHolder(AllCardsContainer, FStreamCardHPVec);
	Factory.CreateAllCardsHolder(AllCardsContainer, FStreamCardHPVec, FStreamCardATTVec, FStreamCardNameVec, FStreamCardTypeVec);

	Factory.CreateDummyDeck(DataHandler.P1Deck);
	Factory.CreateP1StartingDeck(DataHandler.P1Deck, AllCardsContainer);

	Factory.CreateStoredDummyDecks(DataHandler);

	Broadcaster* BroadcastObj = new Broadcaster();

	Listener* ListenerObj = new Listener();

	//NEW CARD FACTORY FUNCTION
	Factory.CreateDummyDeckBuilderDeck(DataHandler.P1DeckBuilderDeck, AllCardsContainer);

	while (true)
	{
		Renderer* RenderingObjects = new Renderer();

		MenuStack.top()->PrintMenu(DataHandler);

		ListenerObj->QuestsStorageVector.at(0)->PrintQuestInfo(RenderingObjects, 75, 10);

		if (IsVirtualKeyPressed(0x57))
		{
			if (DataHandler.SelectionToBePassed != 0)
			{
				DataHandler.SelectionToBePassed--;
			}
			DataHandler.AudioPlayer.NavigateMenuSoundAudio();
			

		}
		else if (IsVirtualKeyPressed(0x53))
		{
			if (DataHandler.SelectionToBePassed < 2)
			{
				DataHandler.SelectionToBePassed++;
			}
			DataHandler.AudioPlayer.NavigateMenuSoundAudio();
		}
		else if (IsVirtualKeyPressed(0x32)) //2 Key
		{
			DataHandler.AudioPlayer.NavigateMenuSoundAudio();
			if (DataHandler.SelectionToBePassed == 0)
			{
				Factory.CreateDummyP2Deck(DataHandler.P2Deck, AllCardsContainer);
				
				Factory.CopyDecksToStoredDecks(DataHandler.P1Deck, DataHandler.P2Deck, DataHandler);

				MenuStack.push(PreCombatTest);

				StartCombatMenu(DataHandler, BroadcastObj, ListenerObj);
			}
			else if (DataHandler.SelectionToBePassed == 1)
			{
				PlayerCatalogAndDeckBuilderMenu(DataHandler);
			}
			else if (DataHandler.SelectionToBePassed == 2)
			{
				//Bestiary UNDER CONSTRUCTION
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
				DataHandler.AudioPlayer.NavigateMenuSoundAudio();
				//PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);

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
				DataHandler.AudioPlayer.NavigateMenuSoundAudio();
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
			CombatHandler.AudioPlayer.ExitNoiseAudio();
			MenuStack.pop();
			break;
		}

	}

}

void BaseGameMode::DisplayPlayer1WinsMenu(CombatDataHandler& DataHandler)
{
	//PlaySound(TEXT("Victory_Fanfare.wav"), NULL, SND_ASYNC);
	DataHandler.AudioPlayer.FictoryFanfareAudio();
	Renderer NewRender;
	Player1WinsMenu* Player1WinMenu = new Player1WinsMenu();
	MenuStack.push(Player1WinMenu);
	while (true)
	{
		MenuStack.top()->PrintMenu(DataHandler);
		if (IsVirtualKeyPressed(0x35))
		{
			//Stops playing the victory fanfare
			DataHandler.AudioPlayer.ExitNoiseAudio();
			if (!MenuStack.empty())
			{
				DataHandler.AudioPlayer.ExitNoiseAudio();
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
				DataHandler.AudioPlayer.ExitNoiseAudio();
				//PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);
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
				DataHandler.AudioPlayer.ExitNoiseAudio();
				//PlaySound(TEXT("NavigateMenuSound.wav"), NULL, SND_ASYNC);
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