#pragma once
#include "CombatDataHandler.h"
#include "VanillaCards.h"
#include <vector>

class CombatLoopUsingVector
{
public:

	bool Player1Wins = false;

	bool Player2Wins = false;

	int P1Current = 3;

	int P2Current = 0;

	CombatLoopUsingVector();

	void BasicLoop(CombatDataHandler &DataHandler);

	void BasicCombatSetup(CombatDataHandler &DataHandler);

	void CheckIfHealthIsLessThanZero(CombatDataHandler& DataHandler);

	~CombatLoopUsingVector();

};

