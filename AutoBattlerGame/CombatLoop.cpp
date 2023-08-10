#include "CombatLoop.h"

CombatLoop::CombatLoop()
{

}

void CombatLoop::BasicLoop(Node* Player1, Node* Player2)
{
	Player1 = Player1->next->next->next;
	Player1->Health = Player1->Health - Player2->Attack;
	Player2->Health = Player2->Health - Player1->Attack;
}

CombatLoop::~CombatLoop()
{

}