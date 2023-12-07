#include "CombatLoopUsingVector.h"

CombatLoopUsingVector::CombatLoopUsingVector()
{

}

void CombatLoopUsingVector::BasicCombatSetup(CombatDataHandler &DataHandler)
{
	if (DataHandler.IsCombatFinished == false)
	{
		if (DataHandler.IsCombatSetup == false)
		{
			DataHandler.CombatAlreadySetup();
			PreCombatAbilityLoop(DataHandler);
		}
		else
		{
			BasicLoop(DataHandler);
		}
	}
	else
	{
		return;
	}

}

void CombatLoopUsingVector::PreCombatAbilityLoop(CombatDataHandler& DataHandler)
{
	for (size_t i = 0; i < DataHandler.P1Deck.size(); i++)
	{
		if (DataHandler.P1Deck.at(i)->DoesCardHavePreCombatAbility == true)
		{
			DataHandler.P1Deck.at(i)->PreCombatAbility(DataHandler, "P1");
		}
	}

	for (size_t j = 0; j < DataHandler.P2Deck.size(); j++)
	{
		if (DataHandler.P2Deck.at(j)->DoesCardHavePreCombatAbility == true)
		{
			DataHandler.P2Deck.at(j)->PreCombatAbility(DataHandler, "P2");
		}
	}
	BasicLoop(DataHandler); 
}

void CombatLoopUsingVector::CheckIfHealthIsLessThanZero(CombatDataHandler& DataHandler)
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

void CombatLoopUsingVector::BasicLoop(CombatDataHandler &DataHandler)
{
	DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->ReduceHP(DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->Attack);
	DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->ReduceHP(DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->Attack);

	//If new cards are added, this can be turned off to check if values are subtracting correctly
	CheckIfHealthIsLessThanZero(DataHandler);

	if (DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->Health <= 0 && DataHandler.TargetingP1VecLocation == 0)
	{
		DataHandler.Player2WinsCombat();
		return;
	}
	else if (DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->Health <= 0 && DataHandler.TargetingP2VecLocation == 3)
	{
		DataHandler.Player1WinsCombat();
		return;
	}


	if (DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation)->Health <= 0)
	{
		DataHandler.AdvanceP1TargetVecLocation();
	}

	if (DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation)->Health <= 0)
	{
		DataHandler.AdvanceP2TargetVecLocation();
	}

}

CombatLoopUsingVector::~CombatLoopUsingVector()
{

}
