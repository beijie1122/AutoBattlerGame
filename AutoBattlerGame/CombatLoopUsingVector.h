#pragma once
#include "CombatDataHandler.h"
#include "VanillaCards.h"
#include <vector>
#include "Broadcaster.h"

class CombatLoopUsingVector
{
public:

	CombatLoopUsingVector();

	void BasicLoop(CombatDataHandler &DataHandler, Broadcaster* BroadcasterObj);

	void BasicCombatSetup(CombatDataHandler &DataHandler, Broadcaster* BroadcasterObj);

	void PreCombatAbilityLoop(CombatDataHandler& DataHandler, Broadcaster* BroadcasterObj);

	void CheckIfHealthIsLessThanZero(CombatDataHandler& DataHandler, Broadcaster* BroadcasterObj);

	void CheckForWinCondition(CombatDataHandler& DataHandler, Broadcaster* BroadcasterObj);

	void CheckIfEntireBoardHealthIsLessThanZero(CombatDataHandler DataHandler, Broadcaster* BroadcasterObj);

	~CombatLoopUsingVector();

};

