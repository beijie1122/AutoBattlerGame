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
	
	/*
	while (P1Current->prev)
	{
	std::this_thread::sleep_for(std::chrono::seconds(1));
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
	}
	*/

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
	
}

CombatLoop::~CombatLoop()
{

}