#pragma once

#include "Node.h"
#include "Renderer.h"
#include "Menus.h"

class CombatLoop
{
public:



	Node* P1Current = new Node();

	Node* P2Current = new Node();

	bool Player1Wins = false;

	bool Player2Wins = false;

	CombatLoop();

	void BasicLoop(Node* Player1, Node* Player2, Renderer RenderAttack, bool &IsCombatFinished);

	void BasicCombatSetup(Node* Player1, Node* Player2, bool& IsCombatSetup, Renderer RenderAttack, bool& IsCombatFinished);

	void WinOrLoseState();

	~CombatLoop();
};

