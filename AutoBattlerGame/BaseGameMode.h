#pragma once
#include <Windows.h>
#include "Node.h"
#include "Menus.h"
#include "Renderer.h"
#include "CombatLoop.h"
#include "FStreamExtractor.h"
#include "LLNodeOperations.h"

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

	std::vector<int> XCoordVec{ 5, 14, 23, 31 };

	std::vector<int> P2XCoordVec{ 50, 59, 68, 77 };

	int TargetingP1VecLocation = 3;

	int TargetingP2VecLocation = 0;

	int PlayerCatalogMenuSelectedCard = 0;

	int PlayerDeckSelectedCard = 0;

	//Node* P1Copy = new Node();

	//Node* P2Copy = new Node();

	int YCoord = 7;

	bool IsCombatSetup = false;

	bool IsCombatFinished = false;

	bool Player1Wins = false;

	bool Player2Wins = false;

	bool IsPlayerViewingCatalog = true;

	bool IsPlayerViewingDeck = false;

	bool IsPlayerReplacingACard = false;

	std::vector<int> CardCatalogXCOORDTargetVec = { 0, 1, 2, 3, 4 };

	std::vector<int> CardCatalogYCOORDTargetVec = { 0, 1 ,2 };

	int CardCatalogXCOORDTarget = 0;

	int CardCatalogYCoordTarget = 0;


	BaseGameMode();

	void MainMenuMode();

	void StartCombatMenu(Node* Player1Board, Node* Player2Board, bool &IsCombatFinished);

	void InitiateCombatMenu(Node* Player1Board, Node* Player2Board, LLNodeOperations NodeOperations, CombatLoop CombatObject, bool &IsCombatFinished);

	void BestiaryMenu(LLNodeOperations BestiaryHandler, Node* Bestiary, Renderer BestiaryRender);

	void PlayerCatalogAndDeckBuilderMenu(Node* PlayerCatalog, Node* PlayerDeck, LLNodeOperations CatalogHandler);

	~BaseGameMode();

};

