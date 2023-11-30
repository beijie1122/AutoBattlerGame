#pragma once
#include "Renderer.h"
#include "CardHolder.h"
#include "VanillaCards.h"

class CombatDataHandler
{
public:

	Renderer RenderObject;

	std::vector<int> XCoordVec{ 5, 14, 23, 31 };

	std::vector<int> P2XCoordVec{ 50, 59, 68, 77 };

	std::vector<VanillaCards> P1Deck;

	std::vector<VanillaCards> P2Deck;

	int YCoord = 7;

	int TargetingP1VecLocation = 3;

	int TargetingP2VecLocation = 0;

	int SelectionToBePassed = 0;

	bool IsCombatSetup = false;

	bool IsCombatFinished = false;

	CombatDataHandler();

	~CombatDataHandler();

};
