#include "CombatLoopUsingVector.h"

CombatLoopUsingVector::CombatLoopUsingVector()
{

}

void CombatLoopUsingVector::BasicCombatSetup(CombatDataHandler &DataHandler)
{
	Player1Wins = false;
	Player2Wins = false;

	if (DataHandler.IsCombatFinished == false)
	{
		if (DataHandler.IsCombatSetup == false)
		{
			DataHandler.TargetingP1VecLocation = 3;
			DataHandler.TargetingP2VecLocation = 0;
			P1Current = 3;
			P2Current = 0;
			DataHandler.IsCombatSetup = true;
			BasicLoop(DataHandler);
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

void CombatLoopUsingVector::BasicLoop(CombatDataHandler &DataHandler)
{
	DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation).Health = DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation).Health - DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation).Attack;
	DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation).Health = DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation).Health - DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation).Attack;

	if (DataHandler.P1Deck.at(DataHandler.TargetingP1VecLocation).Health <= 0 && DataHandler.TargetingP1VecLocation == 0)
	{
		Player2Wins = true;
		DataHandler.IsCombatFinished = true;
		return;
	}
	else if (DataHandler.P2Deck.at(DataHandler.TargetingP2VecLocation).Health <= 0 && DataHandler.TargetingP2VecLocation == 3)
	{
		Player1Wins = true;
		DataHandler.IsCombatFinished = true;
		return;
	}


	if (DataHandler.P1Deck.at(P1Current).Health <= 0)
	{
		P1Current--;
		DataHandler.TargetingP1VecLocation--;
	}

	if (DataHandler.P2Deck.at(P2Current).Health <= 0)
	{
		P2Current++;
		DataHandler.TargetingP2VecLocation++;
	}

}

CombatLoopUsingVector::~CombatLoopUsingVector()
{

}
