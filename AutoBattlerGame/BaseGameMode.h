#pragma once
#include <Windows.h>
#include "Menus.h"
#include "Renderer.h"
#include "FStreamExtractor.h"
#include <stack>
#include "MainMenu.h"
#include "PreCombatMenu.h"
#include "CombatDataHandler.h"
#include "CardHolder.h"
#include "VanillaCards.h"
#include "InitiateCombatMenu.h"
#include "CombatLoopUsingVector.h"
#include "Player1WinsMenu.h"
#include "Player2WinsMenu.h"
#include "SniperCard.h"
#include "CombatDrawMenu.h"
#include "Broadcaster.h"
#include "Listener.h"
#include "QuestsBaseClass.h"
#include "DefeatCardsQuest.h"

class BaseGameMode
{
public:

	//Variables 

	int SelctionToBePassed = 0;

	std::vector<int> CardHealth{ 1, 2, 5, 4 };
	std::vector<int> CardAttack{ 2, 1, 1, 2 };
	std::vector<std::string> CardName{ "Guard", "Trooper", "Attacker", "Backup" };

	std::vector<int> P2CardHealth{ 1, 1, 1, 1 };
	std::vector<int> P2CardAttack{ 1, 2, 1, 1 };
	std::vector<std::string> P2CardName{ "Guard", "Trooper", "Attacker", "Backup" };

	std::vector<int> FStreamCardHPVec{};
	std::vector<int> FStreamCardATTVec{};
	std::vector<std::string> FStreamCardNameVec{};
	std::vector<std::string> FStreamCardTypeVec{};

	//Already migrated over to PreCombatMenu
	std::vector<int> XCoordVec{ 5, 14, 23, 31 };

	std::vector<int> P2XCoordVec{ 50, 59, 68, 77 };

	int TargetingP1VecLocation = 3;

	int TargetingP2VecLocation = 0;

	int PlayerCatalogMenuSelectedCard = 0;

	int PlayerDeckSelectedCard = 0;

	int YCoord = 7;

	bool IsCombatSetup = false;

	bool Player1Wins = false;

	bool Player2Wins = false;

	bool IsPlayerViewingCatalog = true;

	bool IsPlayerViewingDeck = false;

	bool IsPlayerReplacingACard = false;

	std::vector<int> CardCatalogXCOORDTargetVec = { 0, 1, 2, 3, 4 };

	std::vector<int> CardCatalogYCOORDTargetVec = { 0, 1 ,2 };

	int CardCatalogXCOORDTarget = 0;

	int CardCatalogYCoordTarget = 0;

	//UI-Related Elements 

	std::stack<Menus*> MenuStack;


	BaseGameMode();

	void MainMenuMode();

	void StartCombatMenu(CombatDataHandler &DataHandler, Broadcaster* BroadcasterObj, Listener* ListenerObj);

	void InitiateCombatMenu1(CombatDataHandler& DataHandler, Broadcaster* BroadcasterObj, Listener* ListenerObj);

	void BestiaryMenu(LLNodeOperations BestiaryHandler, Node* Bestiary, Renderer BestiaryRender);

	void PlayerCatalogAndDeckBuilderMenu(Node* PlayerCatalog, Node* PlayerDeck, LLNodeOperations CatalogHandler);

	void DisplayPlayer1WinsMenu(CombatDataHandler& DataHandler);

	void DisplayPlayer2WinsMenu(CombatDataHandler& DataHandler);

	void DisplayCombatDrawMenu(CombatDataHandler& DataHandler);

	~BaseGameMode();

};

