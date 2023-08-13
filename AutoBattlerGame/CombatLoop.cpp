#include "CombatLoop.h"
#include <chrono>
#include <conio.h>
#include <thread>

CombatLoop::CombatLoop()
{

}

void CombatLoop::BasicCombatSetup(Node* Player1, Node* Player2, bool& IsCombatSetup, Renderer RenderAttack, bool& IsCombatFinished)
{

	if (IsCombatFinished == false)
	{
		if (IsCombatSetup == false)
		{
			P1Current = Player1->next->next->next;
			P2Current = Player2;
			IsCombatSetup = true; //WATCH THIS BOOL!!! 
			BasicLoop(Player1, Player2, RenderAttack, IsCombatFinished);
		}
		else
		{
			BasicLoop(Player1, Player2, RenderAttack, IsCombatFinished);
		}
	}
	else
	{
		return;
	}


}

void CombatLoop::BasicLoop(Node* Player1, Node* Player2, Renderer RenderAttack, bool& IsCombatFinished)
{
	
	//For attempting a auto battle 
	/*
	while (P1Current->prev)
	{
		if (P1Current->Health <= 0)
		{
			P1Current = P1Current->prev;
			RenderAttack.DrawCardIntValue(10, { 20, 25 });
		}

		if (P2Current->Health <= 0)
		{
			P2Current = P2Current->next;
			RenderAttack.DrawCardIntValue(11, { 35, 25 });
		}

		P1Current->Health = P1Current->Health - P2Current->Attack;
		P2Current->Health = P2Current->Health - P1Current->Attack;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	*/

	//Combat Loop for clicking a button to iterate every loop

	if (P1Current->Health <= 0 && P1Current->prev == NULL)
	{
		//Function going to Player 2 Wins Screen
		IsCombatFinished = true;
		return;
	}
	else if (P2Current->Health <= 0 && P2Current->next == NULL)
	{
		//Function going to Player 1 Wins Screen 
		IsCombatFinished = true;
		return;
	}
	
	if (P1Current->Health <= 0)
	{
		P1Current = P1Current->prev;
	}

	if (P2Current->Health <= 0)
	{
		P2Current = P2Current->next;
		
	}

	P1Current->Health = P1Current->Health - P2Current->Attack;
	P2Current->Health = P2Current->Health - P1Current->Attack;
	
}

CombatLoop::~CombatLoop()
{

}