#include "CombatLoopUsingVector.h"

CombatLoopUsingVector::CombatLoopUsingVector()
{

}

void CombatLoopUsingVector::BasicCombatSetup(CombatDataHandler &DataHandler, Broadcaster* BroadcasterObj)
{
	if (DataHandler.IsCombatFinished == false)
	{
		if (DataHandler.IsCombatSetup == false)
		{
			DataHandler.CombatAlreadySetup();
			PreCombatAbilityLoop(DataHandler, BroadcasterObj);
		}
		else
		{
			BasicLoop(DataHandler, BroadcasterObj);
		}
	}
	else
	{
		return;
	}

}

void CombatLoopUsingVector::PreCombatAbilityLoop(CombatDataHandler& DataHandler, Broadcaster* BroadcasterObj)
{
	for (size_t i = 0; i < DataHandler.P1Deck.size(); i++)
	{
		if (DataHandler.P1Deck.at(i)->DoesCardHavePreCombatAbility == true)
		{
			DataHandler.P1Deck.at(i)->PreCombatAbility(DataHandler, "P1");
			CheckIfHealthIsLessThanZero(DataHandler, BroadcasterObj);
		}
	}

	for (size_t j = 0; j < DataHandler.P2Deck.size(); j++)
	{
		if (DataHandler.P2Deck.at(j)->DoesCardHavePreCombatAbility == true)
		{
			DataHandler.P2Deck.at(j)->PreCombatAbility(DataHandler, "P2");
			CheckIfHealthIsLessThanZero(DataHandler, BroadcasterObj);
		}
	}

	CheckIfEntireBoardHealthIsLessThanZero(DataHandler, BroadcasterObj);

	BasicLoop(DataHandler, BroadcasterObj);
}

void CombatLoopUsingVector::CheckIfHealthIsLessThanZero(CombatDataHandler& DataHandler, Broadcaster* BroadcasterObj)
{
	if (DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->Health < 0)
	{
		DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->RoundHealthtoZero();
	}

	if (DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->Health < 0)
	{
		DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->RoundHealthtoZero();
	}
}

void CombatLoopUsingVector::CheckForWinCondition(CombatDataHandler& DataHandler, Broadcaster* BroadcasterObj)
{
	if (DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->Health <= 0 && DataHandler.TargetingP1VecLocation == 0 
		&& DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->Health <= 0 && DataHandler.TargetingP2VecLocation == 3)
	{
		DataHandler.CombatIsADraw();
		return;
	}
	else if (DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->Health <= 0 && DataHandler.TargetingP1VecLocation == 0)
	{
		DataHandler.Player2WinsCombat();
		return;
	}
	else if (DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->Health <= 0 && DataHandler.TargetingP2VecLocation == 3)
	{
		DataHandler.Player1WinsCombat();

		BroadcasterObj->IncrementWinGameAmt();

		return;
	}
}

void CombatLoopUsingVector::CheckIfEntireBoardHealthIsLessThanZero(CombatDataHandler DataHandler, Broadcaster* BroadcasterObj)
{
	for (size_t i = 0; i < DataHandler.P1Deck.size(); i++)
	{
		if (DataHandler.P1Deck.at(i)->Health < 0)
		{
			DataHandler.P1Deck.at(i)->RoundHealthtoZero();
		}
		if (DataHandler.P2Deck.at(i)->Health < 0)
		{
			DataHandler.P2Deck.at(i)->RoundHealthtoZero();
			//Need to add broadcaster increment here but need to fix the loop first
		}
	}
}

void CombatLoopUsingVector::BasicLoop(CombatDataHandler &DataHandler, Broadcaster* BroadcasterObj)
{
	DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->ReduceHP(DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->Attack);
	DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->ReduceHP(DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->Attack);

	BroadcasterObj->IncrementDamageDeltAmt(DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->Attack);

	//If new cards are added, this can be turned off to check if values are subtracting correctly
	CheckIfHealthIsLessThanZero(DataHandler, BroadcasterObj);

	CheckForWinCondition(DataHandler, BroadcasterObj);

	if (DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->Health <= 0)
	{
		DataHandler.AdvanceP1TargetVecLocation();
	}

	if (DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->Health <= 0)
	{
		DataHandler.AdvanceP2TargetVecLocation();

		BroadcasterObj->IncrementCardsDefeatedAmt();
	}

}

CombatLoopUsingVector::~CombatLoopUsingVector()
{

}
