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

	std::vector<int> XCoordVec{ 5, 12, 19, 26 };

	std::vector<int> P2XCoordVec{ 50, 57, 64, 71 };

	//Node* P1Copy = new Node();

	//Node* P2Copy = new Node();

	int YCoord = 7;

	bool IsCombatSetup = false;

	bool IsCombatFinished = false;

	bool Player1Wins = false;

	bool Player2Wins = false;


	BaseGameMode();

	void MainMenuMode();

	void StartCombatMenu(Node* Player1Board, Node* Player2Board, bool &IsCombatFinished);

	void InitiateCombatMenu(Node* Player1Board, Node* Player2Board, LLNodeOperations NodeOperations, CombatLoop CombatObject, bool &IsCombatFinished);

	void BestiaryMenu(LLNodeOperations BestiaryHandler, Node* Bestiary, Renderer BestiaryRender);

	~BaseGameMode();

};

