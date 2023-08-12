#include "CombatLoop.h"
#include <chrono>
#include <conio.h>
#include <thread>

CombatLoop::CombatLoop()
{

}

void CombatLoop::BasicCombatSetup(Node* Player1, Node* Player2, bool& IsCombatSetup, Renderer RenderAttack)
{
	if (IsCombatSetup == false)
	{
		P1Copy = Player1;
		P2Copy = Player2;
		P1Current = P1Copy->next->next->next;
		P2Current = P2Copy;
		IsCombatSetup = true;
		BasicLoop(P1Copy, P2Copy, RenderAttack);
	}
	else
	{
		BasicLoop(P1Copy, P2Copy, RenderAttack);
	}

}

void CombatLoop::BasicLoop(Node* Player1, Node* Player2, Renderer RenderAttack)
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
		RenderAttack.DrawCardIntValue(10, { 20, 25 });
		return;
	}
	else if (P2Current->Health <= 0 && P2Current->next == NULL)
	{
		RenderAttack.DrawCardIntValue(11, { 35, 25 });
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