#pragma once
#include "CombatDataHandler.h"
#include "VanillaCards.h"
#include <vector>

class CombatLoopUsingVector
{
public:

	CombatLoopUsingVector();

	void BasicLoop(CombatDataHandler &DataHandler);

	void BasicCombatSetup(CombatDataHandler &DataHandler);

	void PreCombatAbilityLoop(CombatDataHandler& DataHandler);

	void CheckIfHealthIsLessThanZero(CombatDataHandler& DataHandler);

	void CheckForWinCondition(CombatDataHandler& DataHandler);

	void CheckIfEntireBoardHealthIsLessThanZero(CombatDataHandler DataHandler);

	~CombatLoopUsingVector();

};

